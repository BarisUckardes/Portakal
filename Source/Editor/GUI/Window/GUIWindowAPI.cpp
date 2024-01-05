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
	GUIWindowAPI::GUIWindowAPI() : mLayoutDirty(true)
	{
		LoadWindowSettings();
	}
	GUIWindowAPI::~GUIWindowAPI()
	{

	}
	void GUIWindowAPI::Render()
	{
		//Setup layout
		const ImGuiViewport* pViewport = ImGui::GetMainViewport();

		ImGui::SetNextWindowSize(pViewport->Size);
		ImGui::SetNextWindowPos(pViewport->Pos);
		ImGui::SetNextWindowViewport(pViewport->ID);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
		ImGui::PushStyleColor(ImGuiCol_WindowBg, { 0,0,0,1.0f });

		bool bEnabled = true;
		ImGui::Begin("Dockspace", &bEnabled, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_MenuBar);

		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();

		const UInt64 dockspaceID = ImGui::GetID("EditorDockspace");
		ImGui::DockSpace(dockspaceID, { 0,0 });

		if (mLayoutDirty)
		{
			//Clear nodes
			ImGui::DockBuilderRemoveNode(dockspaceID);

			//Add dockspace node and properties
			ImGui::DockBuilderAddNode(dockspaceID, ImGuiDockNodeFlags_DockSpace);
			ImGui::DockBuilderSetNodeSize(dockspaceID, pViewport->Size);

			//Split the view
			UInt32 oppositeNode = 0;
			const UInt32 dockIDLeft = ImGui::DockBuilderSplitNode(dockspaceID, ImGuiDir_Left, 0.15f,nullptr,&oppositeNode);
			const UInt32 dockIDRight = ImGui::DockBuilderSplitNode(oppositeNode, ImGuiDir_Right, 0.25f, nullptr, &oppositeNode);
			const UInt32 dockIDUp = ImGui::DockBuilderSplitNode(oppositeNode, ImGuiDir_Up, 0.25, nullptr, &oppositeNode);
			const UInt32 dockIDDown = ImGui::DockBuilderSplitNode(oppositeNode, ImGuiDir_Down, 0.4f, nullptr, &oppositeNode);
			const UInt32 nodes[] = { 0,dockIDDown,dockIDLeft,dockIDRight,dockIDUp,dockIDDown };

			//Dock the windows
			for (const SharedHeap<GUIWindow>& pWindow : mWindows)
			{
				if (pWindow->GetDockDirection() == GUIDirection::None)
					continue;

				const UInt32 dockID = nodes[(int)pWindow->GetDockDirection()];
				ImGui::DockBuilderDockWindow(*pWindow->GetName(), dockID);
			}

			//Set dockbuilder finish
			ImGui::DockBuilderFinish(dockIDDown);

			//Remove the dirty mark
			mLayoutDirty = false;
		}

		//Render each window
		for (Int32 i = 0; i < mWindows.GetSize(); i++)
		{
			const SharedHeap<GUIWindow>& pWindow = mWindows[i];

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
		ImGui::End();

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

			//Create object
			SharedHeap<GUIWindow> pWindow = (GUIWindow*)pType->CreateDefaultHeapObject();
		}

	}
	void GUIWindowAPI::SaveWindowSettings()
	{

	}
}
