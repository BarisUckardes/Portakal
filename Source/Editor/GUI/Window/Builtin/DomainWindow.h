#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFile.h>
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
	};
}

