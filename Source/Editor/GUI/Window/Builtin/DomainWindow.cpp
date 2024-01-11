#include "DomainWindow.h"
#include <Editor/Domain/DomainAPI.h>
#include <imgui.h>
#include <Runtime/Reflection/ReflectionAPI.h>

namespace Portakal
{
	void DomainWindow::SelectFile(const SharedHeap<DomainFile>& pFile)
	{
		if (mSelectedFiles.Remove(pFile))
			return;

		mSelectedFiles.Add(pFile);
	}
	void DomainWindow::DeleteFolder(const SharedHeap<DomainFolder>& pFolder)
	{
		if (pFolder.IsShutdown())
			return;
		pFolder->Delete();
	}
	void DomainWindow::DeleteSelections()
	{
		for (const SharedHeap<DomainFile>& pFile : mSelectedFiles)
			pFile->Delete();

		for (const SharedHeap<DomainFolder>& pFolder : mSelectedFolders)
			pFolder->Delete();

		mSelectedFiles.Clear();
		mSelectedFolders.Clear();
	}
	void DomainWindow::SelectFolder(const SharedHeap<DomainFolder>& pFolder)
	{
		if (mSelectedFolders.Remove(pFolder))
			return;

		mSelectedFolders.Add(pFolder);
	}
	void DomainWindow::ClearSelections()
	{
		mSelectedFiles.Clear();
		mSelectedFolders.Clear();
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

				//Check if requested selection
				if (ImGui::IsKeyDown(ImGuiKey_LeftCtrl) && bClicked)
				{
					SelectFolder(pFolder);
				}

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
				mTargetFolder = mTargetFolder->GetOwnerFolder();
				ClearSelections();
			}
		}
		if (ImGui::IsAnyMouseDown() && !ImGui::IsAnyItemHovered()) // clicked empty space, will clear all the selections
		{
			ClearSelections();
		}
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) // wants to delete the selected items
		{
			DeleteSelections();
		}
		if (ImGui::IsMouseClicked(ImGuiMouseButton_Right) && !ImGui::IsAnyItemHovered() && ImGui::IsWindowFocused()) // wants to open context popup
		{
			ImGui::OpenPopup("CreateContext");
		}

		//Handle popups
		if (ImGui::BeginPopup("FolderOptions"))
		{

			ImGui::EndPopup();
		}
		if (ImGui::BeginPopup("CreateContext"))
		{
			ImGui::Text("Create:");
			ImGui::Separator();
			ImGui::Spacing();

			for (IContextMenuItem* pAction : mContextCreateActions)
			{
				const String title = pAction->GetName();
				if (ImGui::Selectable(*title))
				{
					if (pAction->OnAction(mTargetFolder))
					{
						mTickingContextCreateActions.Add(pAction);
						break;
					}
				}
			}

			ImGui::EndPopup();
		}

		//Tick context actions
		for (Int32 i = 0;i<mTickingContextCreateActions.GetSize();i++)
		{
			IContextMenuItem* pAction = mTickingContextCreateActions[i];

			//Tick and check if close requested
			if (!pAction->OnTick(mTargetFolder))
			{
				//Remove from the ticking actions
				mTickingContextCreateActions.RemoveAt(i);

				//Remove the instance from the context create actions
				const Int32 index = mContextCreateActions.FindIndex(pAction);
				mContextCreateActions.RemoveAt(index);

				//Create new instnace
				IContextMenuItem* pNewAction = (IContextMenuItem*)pAction->GetType()->CreateDefaultHeapObject();
				pNewAction->SetName(pNewAction->GetType()->GetAttribute<ContextMenuItem>()->GetName());
				mContextCreateActions.Add(pNewAction);

				//Shutdown and delete
				pAction->Shutdown();
				delete pAction;

				i--;
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

		//Collect contenxt actions
		Array<Type*> contextCreateActionTypes = ReflectionAPI::GetSubTypes(typeof(IContextMenuItem));
		for (Type* pType : contextCreateActionTypes)
		{
			IContextMenuItem* pAction = (IContextMenuItem*)pType->CreateDefaultHeapObject();
			pAction->SetName(pType->GetAttribute<ContextMenuItem>()->GetName());
			mContextCreateActions.Add(pAction);
		}
	}
}
