#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFile.h>
#include <Editor/GUI/IContextCreateAction.h>
#include "DomainWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API DomainWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		DomainWindow() = default;
		~DomainWindow() = default;

	private:

		void SelectFolder(const SharedHeap<DomainFolder>& pFolder);
		void SelectFile(const SharedHeap<DomainFile>& pFile);
		void DeleteFolder(const SharedHeap<DomainFolder>& pFolder);
		void DeleteSelections();
		void ClearSelections();

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
		Array<IContextCreateAction*> mContextCreateActions;
		Array<IContextCreateAction*> mTickingContextCreateActions;
	};
}

