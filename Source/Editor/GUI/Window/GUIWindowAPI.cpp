#include "GUIWindowAPI.h"
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/Project/ProjectAPI.h>
#include <Editor/GUI/Window/GUIWindowSettings.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Yaml/Yaml.h>
#include <imgui.h>
#include <imgui_internal.h>

namespace Portakal
{
	void GUIWindowAPI::MarkLayoutDirty()
	{
		GUIWindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

	}
	SharedHeap<GUIWindow> GUIWindowAPI::CreateWindow(Type* pType)
	{
		GUIWindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		SharedHeap<GUIWindow> pWindow = (GUIWindow*)pType->CreateDefaultHeapObject();
		pWindow->OnInitialize();

		pAPI->mWindows.Add(pWindow);

		return pWindow;
	}
	GUIWindowAPI::GUIWindowAPI() : mLayoutDirty(true)
	{
		LoadWindowSettings();
	}
	GUIWindowAPI::~GUIWindowAPI()
	{

	}
	void GUIWindowAPI::Render()
	{
		//Construct initial layout
		ImGuiViewport* pViewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(pViewport->Pos);
		ImGui::SetNextWindowSize(pViewport->Size);
		ImGui::SetNextWindowViewport(pViewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		bool open = true;
		ImGui::Begin("DockSpaceWindow", &open,
			ImGuiWindowFlags_MenuBar |
			ImGuiWindowFlags_NoDocking |
			ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBringToFrontOnFocus |
			ImGuiWindowFlags_NoNavFocus);
		ImGui::PopStyleVar(3);

		if (mLayoutDirty)
		{
			ImGuiID dockspaceID = ImGui::GetID("Dockspace");
			ImGui::DockBuilderRemoveNode(dockspaceID);
			ImGui::DockBuilderAddNode(dockspaceID);

			ImGuiID dockOppositeNode = dockspaceID;
			ImGuiID dockLeftNode = ImGui::DockBuilderSplitNode(dockOppositeNode, ImGuiDir_Left, 0.20f, NULL, &dockOppositeNode);
			ImGuiID dockRightNode = ImGui::DockBuilderSplitNode(dockOppositeNode, ImGuiDir_Right, 0.20f, NULL, &dockOppositeNode);
			ImGuiID dockUpNode = ImGui::DockBuilderSplitNode(dockOppositeNode, ImGuiDir_Up, 0.20f, NULL, &dockOppositeNode);
			ImGuiID dockBottomNode = ImGui::DockBuilderSplitNode(dockOppositeNode, ImGuiDir_Down, 0.20f, NULL, &dockOppositeNode);
			const UInt32 nodes[] = { dockOppositeNode,dockLeftNode,dockRightNode,dockUpNode,dockBottomNode };

			for (const SharedHeap<GUIWindow>& pWindow : mWindows)
			{
				const UInt32 dockNode = nodes[(Int64)pWindow->GetDockDirection() + 1];
				ImGui::DockBuilderDockWindow(*pWindow->GetType()->GetName(), dockNode);
			}
			ImGui::DockBuilderFinish(dockspaceID);

			mLayoutDirty = false;
		}

		ImGuiID dockspace_id = ImGui::GetID("Dockspace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), 0);
		ImGui::End();

		//Render each window
		for (Int32 i = 0; i < mWindows.GetSize(); i++) 
		{
			SharedHeap<GUIWindow>& pWindow = mWindows[i];

			//Get former visibility
			const bool bFormerVisibility = pWindow->IsVisible();
			bool bActive = true;
			const bool bCurrentlyVisible = ImGui::Begin(*pWindow->GetType()->GetName(), &bActive);

			//Check if visibility changed
			if (bCurrentlyVisible != bFormerVisibility)
			{
				if (bCurrentlyVisible)
					pWindow->OnShow();
				else
					pWindow->OnHide();
			}

			//Paint window if visible
			if (bCurrentlyVisible)
				pWindow->OnPaint();

			//Check if closed
			if (pWindow.IsShutdown() || !bActive)
			{
				mWindows.RemoveAt(i);
				i--;
				pWindow.Shutdown();
			}
			else
			{
				const ImVec2 pos = ImGui::GetWindowPos();
				const ImVec2 size = ImGui::GetWindowSize();

				pWindow->_SetPosition({ (UInt16)pos.x,(UInt16)pos.y });
				pWindow->_SetSize({ (UInt16)size.x,(UInt16)size.y });
				pWindow->_SetVisibility(bCurrentlyVisible);
			}

			//End window
			ImGui::End();
		}
	}
	void GUIWindowAPI::OnPreInvalidate()
	{
		SaveWindowSettings();
	}
	void GUIWindowAPI::OnPostInvalidate()
	{
		LoadWindowSettings();
	}
	void GUIWindowAPI::CreateDefaultWindowSettings()
	{
		//Get project folder path
		const String projectFolderPath = ProjectAPI::GetFolderPath();
		if (!PlatformDirectory::Exists(projectFolderPath))
		{
			DEV_LOG("GUIWindowAPI", "Project folder path is invalid");
			return;
		}

		//Get project details
		const ProjectDescriptor descriptor = ProjectAPI::GetProjectDetails();

		//Create settings path if does not exists
		const String settingsFolderPath = projectFolderPath + "\\Settings";
		if (!PlatformDirectory::Exists(settingsFolderPath))
		{
			DEV_LOG("GUIWindowAPI", "Settings folder does not exists, creating new one");
			if (!PlatformDirectory::Create(settingsFolderPath))
			{
				DEV_LOG("GUIWindowAPI","Failed to create settings folder!");
				return;
			}
		}

		//Create default settings file
		const String windowSettingsFilePath = settingsFolderPath + "\\WindowSettings.psettings";
		if (PlatformFile::Exists(windowSettingsFilePath))
			PlatformFile::Delete(windowSettingsFilePath);

		GUIWindowSettings settings =
		{
			{
				{"WorldWindow",Guid::Create(),{256,256},{100,100},GUIDirection::Left},
				{"DomainWindow",Guid::Create(),{256,256},{100,100},GUIDirection::Down},
				{"ObjectWindow",Guid::Create(),{256,256},{100,100},GUIDirection::Right},
				{"GameWindow",Guid::Create(),{256,256},{100,100},GUIDirection::None},
				{"SceneWindow",Guid::Create(),{256,256},{100,100},GUIDirection::None},
			}
		};

		const String fileDescriptorYAML = Yaml::ToYaml<GUIWindowSettings>(&settings);

		PlatformFile::Create(windowSettingsFilePath);
		PlatformFile::Write(windowSettingsFilePath, fileDescriptorYAML);

	}
	void GUIWindowAPI::LoadWindowSettings()
	{
		//Get project folder path
		const String projectFolderPath = ProjectAPI::GetFolderPath();
		if (!PlatformDirectory::Exists(projectFolderPath))
		{
			DEV_LOG("GUIWindowAPI", "Project folder path is invalid");
			return;
		}

		//Get project details
		const ProjectDescriptor descriptor = ProjectAPI::GetProjectDetails();

		//Validate settings folder path
		const String settingsFolderPath = projectFolderPath + "\\Settings";
		bool bDefaultSettingsCreated = false;
		if (!PlatformDirectory::Exists(settingsFolderPath))
		{
			DEV_LOG("GUIWindowAPI", "Settings folder is missing, creating default settings");
			CreateDefaultWindowSettings();
			bDefaultSettingsCreated = true;
		}

		//Load settings file
		const String windowSettingsFilePath = settingsFolderPath + "\\WindowSettings.psettings";
		if (!PlatformFile::Exists(windowSettingsFilePath))
		{
			DEV_LOG("GUIWindowAPI", "Settings file is missing!");
			if (bDefaultSettingsCreated)
				return;
			else
				CreateDefaultWindowSettings();
		}

		String fileContent;
		if (!PlatformFile::Read(windowSettingsFilePath, fileContent))
		{
			DEV_LOG("GUIWindowAPI", "Failed to read the settings file!");
			return;
		}
		if (!Yaml::IsYaml(fileContent))
		{
			DEV_LOG("GUIWindowAPI", "Settings file is corrupt");
			return;
		}

		//Get settings
		GUIWindowSettings settings = {};
		Yaml::ToObject<GUIWindowSettings>(fileContent,&settings);

		//Create windows
		for (const GUIWindowDescriptor& descriptor : settings.Settings)
		{
			//Get and validate type
			Type* pType = ReflectionAPI::GetType(descriptor.Name);
			if (pType == nullptr)
			{
				DEV_LOG("GUIWindowAPI", "Window type[%s] not found within the reflection domain",*descriptor.Name);
				continue;
			}

			//Create window
			SharedHeap<GUIWindow> pWindow = GUIWindowAPI::CreateWindow(pType);
			pWindow->OverrideID(descriptor.ID);
			pWindow->SetName(descriptor.Name);
			pWindow->_SetPosition(descriptor.Position);
			pWindow->_SetSize(descriptor.Size);
			pWindow->_SetDockDirection(descriptor.DockDirection);
		}

	}
	void GUIWindowAPI::SaveWindowSettings()
	{

	}
}
