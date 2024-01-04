#include "GUIWindowAPI.h"
#include <imgui.h>
#include <imgui_internal.h>

namespace Portakal
{
	GUIWindowAPI::GUIWindowAPI() : mLayoutDirty(true)
	{

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

			}

			//Set dockbuilder finish
			ImGui::DockBuilderFinish(dockIDDown);

			//Remove the dirty mark
			mLayoutDirty = false;
		}

		ImGui::End();

	}
}
