#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFile.h>
#include <Editor/GUI/ContextMenu/IContextMenuItem.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "DomainWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API DomainWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		DomainWindow() : mTargetFolder(nullptr), mContextMenuFolder(nullptr), mFolderChanged(false),mItemSize(64),mItemGap(16)
		{

		}
		~DomainWindow() = default;

		FORCEINLINE float GetItemSize() const noexcept
		{
			return mItemSize;
		}
		FORCEINLINE float GetItemGap() const noexcept
		{
			return mItemGap;
		}
		FORCEINLINE float GetFontSize() const noexcept
		{
			return mFontSize;
		}

		void SetItemSize(const float size);
		void SetItemGap(const float gap);
	private:
		void SelectFolder(const SharedHeap<DomainFolder>& pFolder);
		void SelectFile(const SharedHeap<DomainFile>& pFile); 
		void DeleteFolder(const SharedHeap<DomainFolder>& pFolder);
		void DeleteSelections();
		void ClearSelections();
		void OpenFile(DomainFile* pFile);
		void OpenFolder(DomainFolder* pFolder);
		void ProcessDragDrops(const Array<String>& items);
		void InitializeThumbnail(const SharedHeap<DomainFile>& pFile);
		SharedHeap<TextureResource> GetThumbnailImage(const SharedHeap<DomainFile>& pFile);
		void ClearThumbnails();

		void RenameFile(const SharedHeap<DomainFile>& pFile);
		void RenameFolder(const SharedHeap<DomainFolder>& pFolder);

		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	private:
		DomainFolder* mTargetFolder;
		Array<SharedHeap<DomainFolder>> mSelectedFolders;
		Array<SharedHeap<DomainFile>> mSelectedFiles;
		SharedHeap<ImGuiTextureBinding> mFolderIconBinding;
		SharedHeap<ImGuiTextureBinding> mDefaultItemIconBinding;
		SharedHeap<DomainFolder> mContextMenuFolder;
		SharedHeap<DomainFile> mContextMenuFile;
		bool mFolderChanged;
		float mItemSize;
		float mItemGap;
		float mFontSize;

		//Context menu item variables
		Array<SharedHeap<IContextMenuItem>> mContextCreateActions;
		Array<SharedHeap<IContextMenuItem>> mTickingContextCreateActions;

		//Thumbnail variables
		HashMap<SharedHeap<DomainFile>, SharedHeap<IThumbnail>> mThumnails;

		//File rename
		String mFileRenameName;
		SharedHeap<DomainFile> mTargetRenameFile;
	};
}





































