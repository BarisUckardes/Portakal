#pragma once

#include <Runtime/Object/API.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Containers/Array.h>

#include <Editor/GUI/Window/GUIWindow.h>

namespace Portakal
{
	class EDITOR_API GUIWindowAPI : public API<GUIWindowAPI>
	{
	public:
		static const Array<SharedHeap<GUIWindow>>& GetWindows();
	public:
		GUIWindowAPI();
		~GUIWindowAPI();

		void RemoveWindow(const SharedHeap<GUIWindow>& window);
	private:
		Array<SharedHeap<GUIWindow>> mWindows;
	};
}