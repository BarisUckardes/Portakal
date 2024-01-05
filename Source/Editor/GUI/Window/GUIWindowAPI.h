#pragma once
#include <Runtime/Object/API.h>
#include <Editor/GUI/Window/GUIWindow.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class EDITOR_API GUIWindowAPI : public API<GUIWindowAPI>
	{
		friend class GUIWindowModule;
	public:
		static void MarkLayoutDirty();
	private:
		GUIWindowAPI();
		~GUIWindowAPI();

		void Render();
		void OnPreInvalidate();
		void OnPostInvalidate();
		void CreateDefaultWindowSettings();
		void LoadWindowSettings();
		void SaveWindowSettings();
	private:
		Array<SharedHeap<GUIWindow>> mWindows;
		Bool8 mLayoutDirty;
	};
}
