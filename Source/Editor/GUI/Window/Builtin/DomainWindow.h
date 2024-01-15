#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFile.h>
#include <Editor/GUI/IContextMenuItem.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/GUI/IThumbnail.h>
#include "DomainWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API DomainWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		DomainWindow() : mTargetFolder(nullptr), mContextMenuFolder(nullptr), mFolderChanged(false),mFileSize(64),mFolderSize(64),mItemGap(16)
		{

		}
		~DomainWindow() = default;

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
		DomainFolder* mContextMenuFolder;
		bool mFolderChanged;
		float mFolderSize;
		float mFileSize;
		float mItemGap;

		//Context menu item variables
		Array<IContextMenuItem*> mContextCreateActions;
		Array<IContextMenuItem*> mTickingContextCreateActions;

		//Thumbnail variables
		HashMap<SharedHeap<DomainFile>, SharedHeap<IThumbnail>> mThumnails;
	};
}





































