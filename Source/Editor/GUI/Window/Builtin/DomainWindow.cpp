#include "DomainWindow.h"
#include <Editor/Domain/DomainAPI.h>
#include <imgui.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/ImGui/ImGuiAPI.h>
#include <Runtime/Window/WindowAPI.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/Resource/CustomResourceSerializer.h>
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include <Editor/GUI/Object/EditorObjectAPI.h>
#include <Editor/GUI/OpenAction/IFileOpenAction.h>
#include <Editor/GUI/Thumbnail/Builtin/DefaultThumbnail.h>
#include <Editor/ImGui/ImGuiUtils.h>

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
	void DomainWindow::OpenFile(DomainFile* pFile)
	{
		Type* pActionType = pFile->GetOpenActionType();
		if (pActionType == nullptr)
		{
			DEV_LOG("DomainWindow", "Cannot open file %s, no open action defined", *pFile->GetName());
			return;
		}

		IFileOpenAction* pAction = (IFileOpenAction*)pActionType->CreateDefaultHeapObject();
		pAction->OnOpen(pFile);
		delete pAction;
	}
	void DomainWindow::OpenFolder(DomainFolder* pFolder)
	{
		mTargetFolder = pFolder;
		ClearSelections();
		ClearThumbnails();
	}
	void DomainWindow::ProcessDragDrops(const Array<String>& items)
	{
		//Iterate
		for (const String& itemPath : items)
			mTargetFolder->ImportExternalFile(itemPath);
	}
	void DomainWindow::InitializeThumbnail(const SharedHeap<DomainFile>& pFile)
	{
		//Check if this domain file already exists
		if (mThumnails.FindIndex(pFile) == -1)
		{
			Type* pType = pFile->GetThumbnailType();
			IThumbnail* pThumbnail = nullptr;
			if (pType == nullptr)
			{
				pThumbnail = new DefaultThumbnail();
			}
			else
			{
				pThumbnail = (IThumbnail*)pFile->GetThumbnailType()->CreateDefaultHeapObject();
				
			}
			
			pThumbnail->OnInitialize();
			mThumnails.Insert(pFile, pThumbnail);
		}
	}
	SharedHeap<TextureResource> DomainWindow::GetThumbnailImage(const SharedHeap<DomainFile>& pFile)
	{
		SharedHeap<IThumbnail>* pThumbnail = mThumnails.Find(pFile);
		return (*pThumbnail)->GetThumbnailTexture(pFile.GetHeap());
	}
	void DomainWindow::ClearThumbnails()
	{
		mThumnails.Clear();
	}

	void DomainWindow::RenameFile(const SharedHeap<DomainFile>& pFile)
	{
		mTargetRenameFile = pFile;
		ImGui::OpenPopup("FileRenameMenu");
	}
	void DomainWindow::RenameFolder(const SharedHeap<DomainFolder>& pFolder)
	{

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
		//First check window events for drag drops
		if (ImGui::IsWindowFocused())
		{
			//Get window events
			SharedHeap<PlatformWindow> pWindow = WindowAPI::GetDefaultWindow();
			const Array<WindowEventData>& events = pWindow->GetEvents();
			for (const WindowEventData& event : events)
			{
				if (event.Type == WindowEventType::DragDrop)
					ProcessDragDrops(event.DropItems);
			}
		}
		//Create&Reset states
		mFolderChanged = false;

		//Render target path
		{
			const String text = mTargetFolder == nullptr ? "unknown" : mTargetFolder->GetPath();
			ImGui::Text(*text);
			ImGui::Separator();
		}

		//Get item pos
		ImVec2 itemPos = ImGui::GetCursorPos();

		//Render folders
		const Array<SharedHeap<DomainFolder>>& folders = mTargetFolder->GetFolders();
		{
			DomainFolder* pNextOpenFolder = nullptr;
			for (const SharedHeap<DomainFolder>& pFolder : folders)
			{
				//Get if selected or not
				const bool bSelected = mSelectedFolders.Has(pFolder);

				//Create selectable
				ImGui::SetCursorPos(itemPos);
				ImGui::PushID(*pFolder->GetName());
				const bool bClicked = ImGui::Selectable("", bSelected, ImGuiSelectableFlags_DontClosePopups, { mFolderSize,mFolderSize });
				ImGui::PopID();

				//Check if requested selection
				if (ImGui::IsKeyDown(ImGuiKey_LeftCtrl) && bClicked)
					SelectFolder(pFolder);

				//Check if requested to open folder
				if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left) && ImGui::IsItemHovered())
					OpenFolder(pFolder.GetHeap());

				//Check if requested to open folder context menu
				if (ImGui::IsMouseClicked(ImGuiMouseButton_Right) && ImGui::IsItemHovered())
				{
					ImGui::OpenPopup("FolderContextMenu");
					mContextMenuFolder = pFolder;
				}

				//Create image
				ImGui::SetCursorPos(itemPos);
				ImGui::Image(mFolderIconBinding->GetTable(), { mFolderSize,mFolderSize });

				//Draw text
				ImGui::SetCursorPos({ itemPos.x,itemPos.y + mFolderSize });
				ImGui::Text(*pFolder->GetName());

				//Move next
				itemPos.x += (mFolderSize + mItemGap);

				//Reset same line
				ImGui::SameLine();
			}

			if (mFolderChanged)
				return;
		}

		//Render files
		const Array<SharedHeap<DomainFile>>& files = mTargetFolder->GetFiles();
		{
			for (const SharedHeap<DomainFile>& pFile : files)
			{
				//Get if selected
				const bool bSelected = mSelectedFiles.Has(pFile);

				//Create selectable
				ImGui::SetCursorPos(itemPos);
				ImGui::PushID(*pFile->GetName());
				const bool bClicked = ImGui::Selectable("", bSelected, ImGuiSelectableFlags_DontClosePopups, { mFileSize,mFileSize });
				ImGui::PopID();

				//Check if requested selection
				if (ImGui::IsKeyDown(ImGuiKey_LeftCtrl) && bClicked)
				{
					SelectFile(pFile);
					DEV_LOG("a", "Selected0 %d",mSelectedFiles.GetSize());
				}
				else if (bClicked)
				{
					ClearSelections();
					SelectFile(pFile);
					DEV_LOG("a","Selected1 %d",mSelectedFiles.GetSize());
				}

				//Check if requested to open file
				if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left) && ImGui::IsItemHovered())
					OpenFile(pFile.GetHeap());

				//Check if requested to open file context menu
				if (ImGui::IsMouseClicked(ImGuiMouseButton_Right) && ImGui::IsItemHovered())
				{
					ImGui::OpenPopup("FileContextMenu");
					mContextMenuFile = pFile;
				}

				//Thumbnail work
				InitializeThumbnail(pFile);

				SharedHeap<TextureResource> pTexture = GetThumbnailImage(pFile);
				SharedHeap<ImGuiTextureBinding> pBinding = ImGuiAPI::GetRenderer()->GetOrCreateTextureBinding(pTexture);

				//Create image
				ImGui::SetCursorPos(itemPos);
				ImGui::Image(pBinding->GetTable(), { mFileSize,mFileSize });

				//Draw text
				ImGui::SetCursorPos({ itemPos.x,itemPos.y + mFileSize });
				ImGui::Text(*pFile->GetName());

				//Move next
				itemPos.x += (mFileSize + mItemGap);

				//Reset same line
				ImGui::SameLine();
			}
		}

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
		if (ImGui::IsKeyPressed(ImGuiKey_F2)) // wants to rename stuff
		{
			if(mSelectedFiles.GetSize() == 1)
				RenameFile(mSelectedFiles[0]);
			if (!mSelectedFolders.GetSize() == 1)
				RenameFolder(mSelectedFolders[0]);
		}

		//Handle popups
		if (ImGui::BeginPopup("FolderContextMenu"))
		{
			ImGui::Text("Folder");
			ImGui::Separator();

			if (ImGui::Selectable("Open"))
			{
				OpenFolder(mContextMenuFolder.GetHeap());
			}
			if (ImGui::Selectable("Delete"))
			{
				mContextMenuFolder->Delete();
			}

			ImGui::EndPopup();
		}
		else
		{
			mContextMenuFolder = nullptr;
		}
		if (ImGui::BeginPopup("FileContextMenu"))
		{
			ImGui::Text("File");
			ImGui::Separator();

			if (ImGui::Selectable("Open"))
			{
				OpenFile(mContextMenuFile.GetHeap());
			}
			if (ImGui::Selectable("Rename"))
			{
				ImGui::EndPopup();
				RenameFile(mContextMenuFile);
			}
			else
			{
				ImGui::EndPopup();
			}
		}
		else
		{
			mContextMenuFile = nullptr;
		}
		if (ImGui::BeginPopup("FileRenameMenu"))
		{
			ImGui::Text("Rename file");
			ImGui::Separator();

			mFileRenameName = ImGuiUtils::TextField("New name", mFileRenameName);
			if (ImGui::Button("Apply"))
			{
				mTargetRenameFile->Rename(mFileRenameName);
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
		else
		{
			mFileRenameName = "";
			mTargetRenameFile = nullptr;
		}
		if (ImGui::BeginPopup("CreateContext"))
		{
			ImGui::Text("Create:");
			ImGui::Separator();
			ImGui::Spacing();

			for (SharedHeap<IContextMenuItem> pAction : mContextCreateActions)
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
		for (Int32 i = 0; i < mTickingContextCreateActions.GetSize(); i++)
		{
			SharedHeap<IContextMenuItem> pAction = mTickingContextCreateActions[i];

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
				pNewAction->SetName(pNewAction->GetType()->GetAttribute<CustomContextMenuItem>()->GetName());
				mContextCreateActions.Add(pNewAction);

				//Shutdown and delete
				pAction.Shutdown();

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

		//Collect context actions
		Array<Type*> contextCreateActionTypes = ReflectionAPI::GetSubTypes(typeof(IContextMenuItem));
		for (Type* pType : contextCreateActionTypes)
		{
			IContextMenuItem* pAction = (IContextMenuItem*)pType->CreateDefaultHeapObject();
			pAction->SetName(pType->GetAttribute<CustomContextMenuItem>()->GetName());
			mContextCreateActions.Add(pAction);
		}

		//Get folder icon
		SharedHeap<EditorTextureResource> pFolderIcon = EditorResourceAPI::GetResource("FolderIcon").QueryAs<EditorTextureResource>();
		mFolderIconBinding = ImGuiAPI::GetRenderer()->GetOrCreateTextureBinding(pFolderIcon->GetTexture());

		//Get default icon
		SharedHeap<EditorTextureResource> pDefaultIcon = EditorResourceAPI::GetResource("DefaultIcon").QueryAs<EditorTextureResource>();
		mDefaultItemIconBinding = ImGuiAPI::GetRenderer()->GetOrCreateTextureBinding(pDefaultIcon->GetTexture());

		//Setup defaults
		mFolderSize = 64;
		mFileSize = 64;
		mItemGap = 16;
	}
}
