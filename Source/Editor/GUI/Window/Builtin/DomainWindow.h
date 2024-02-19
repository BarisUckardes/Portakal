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
		DomainWindow() : mTargetFolder(nullptr), mContextMenuFolder(nullptr), mFolderChanged(false),mItemSize(64),mItemGap(16),mFontSize(16)
		{

		}
		~DomainWindow() = default;

		FORCEINLINE Float32 GetItemSize() const noexcept
		{
			return mItemSize;
		}
		FORCEINLINE Float32 GetItemGap() const noexcept
		{
			return mItemGap;
		}
		FORCEINLINE Float32 GetFontSize() const noexcept
		{
			return mFontSize;
		}

		void SetItemSize(const Float32 size);
		void SetItemGap(const Float32 gap);
	private:
		void SelectFolder(const SharedHeap<DomainFolder>& pFolder);
		void SelectFile(const SharedHeap<DomainFile>& pFile); 
		void DeleteFolder(const SharedHeap<DomainFolder>& pFolder);
		void DeleteSelections();
		void ClearSelections();
		void OpenFolder(DomainFolder* pFolder);
		void ProcessDragDrops(const Array<String>& items);

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
		Float32 mItemSize;
		Float32 mItemGap;
		Float32 mFontSize;

		//Context menu item variables
		Array<SharedHeap<IContextMenuItem>> mContextCreateActions;
		Array<SharedHeap<IContextMenuItem>> mTickingContextCreateActions;

		//File rename
		String mFileRenameName;
		SharedHeap<DomainFile> mTargetRenameFile;
	};
}





































