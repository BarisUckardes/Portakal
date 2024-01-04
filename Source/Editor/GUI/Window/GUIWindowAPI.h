#pragma once
#include <Runtime/Object/API.h>
#include <Editor/GUI/Window/GUIWindow.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class EDITOR_API GUIWindowAPI : public API<GUIWindowAPI>
	{
		friend class GUIWindowModule;
	private:
		GUIWindowAPI();
		~GUIWindowAPI();

		void Render();
	private:
		Array<SharedHeap<GUIWindow>> mWindows;
		Bool8 mLayoutDirty;
	};
}
