#include "DomainWindow.h"
#include <Editor/Domain/DomainAPI.h>
#include <imgui.h>

namespace Portakal
{
	void RenderFolderPath(const SharedHeap<DomainFolder>& pFolder)
	{
		const String text = pFolder.IsShutdown() ? "unknown" : pFolder->GetPath();
		ImGui::Text(*text);
		ImGui::Separator();
	}
	void RenderFolders(const SharedHeap<DomainFolder>& pFolder,const Array<SharedHeap<DomainFolder>>& selectedFolders,const float width,const float height,SharedHeap<DomainFolder>& pOpenFolder)
	{
		//Get folders
		const Array<SharedHeap<DomainFolder>>& folders = pFolder->GetFolders();

		//Render each
		for (const SharedHeap<DomainFolder>& pFolder : folders)
		{
			//Get if selected or not
			const bool bSelected = selectedFolders.Has(pFolder);

			//Create selectable
			const ImVec2 preSelectablePos = ImGui::GetCursorPos();
			const bool bClicked = ImGui::Selectable(*pFolder->GetName(),bSelected, ImGuiSelectableFlags_DontClosePopups, {width,height});

			//Check if requested to open folder
			if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left) && ImGui::IsItemHovered())
			{
				pOpenFolder = pFolder;
				DEV_LOG("DomainWindow", "Double clicked %s", *pFolder->GetName());
			}

			//Create image

			//Reset same line
			ImGui::SameLine();
		}
	}
	void DomainWindow::OnShutdown()
	{

	}
	void DomainWindow::OnShow()
	{

	}
	void DomainWindow::OnHide()
	{

	}
	void DomainWindow::OnPaint()
	{
		//Render target path
		{
			const String text = mTargetFolder == nullptr ? "unknown" : mTargetFolder->GetPath();
			ImGui::Text(*text);
			ImGui::Separator();
		}

		//Render folders
		const Array<SharedHeap<DomainFolder>>& folders = mTargetFolder->GetFolders();
		{
			DomainFolder* pNextOpenFolder = nullptr;
			const float folderWidth = 64;
			const float folderHeight = 64;
			for (const SharedHeap<DomainFolder>& pFolder : folders)
			{
				//Get if selected or not
				const bool bSelected = mSelectedFolders.Has(pFolder);

				//Create selectable
				const ImVec2 preSelectablePos = ImGui::GetCursorPos();
				const bool bClicked = ImGui::Selectable(*pFolder->GetName(), bSelected, ImGuiSelectableFlags_DontClosePopups, { folderWidth,folderHeight });

				//Check if requested to open folder
				if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left) && ImGui::IsItemHovered())
				{
					pNextOpenFolder = pFolder.GetHeap();
					DEV_LOG("DomainWindow", "Double clicked %s", *pFolder->GetName());
				}

				//Create image

				//Reset same line
				ImGui::SameLine();
			}

			//Check if requested to open folder
			if (pNextOpenFolder != nullptr)
			{
				mTargetFolder = pNextOpenFolder;
				return;
			}
		}

		//Render files

		//Handle events
		if (ImGui::IsKeyPressed(ImGuiKey_Backspace)) // wants to go back to the previous folder
		{
			if (!mTargetFolder->IsRootFolder())
			{

			}
		}
	}
	void DomainWindow::OnInitialize()
	{
		//Get domain API folder
		SharedHeap<DomainFolder> pRootFolder = DomainAPI::GetRootFolder();
		if (pRootFolder.IsShutdown())
			return;

		mTargetFolder = pRootFolder.GetHeap();
	}
}
