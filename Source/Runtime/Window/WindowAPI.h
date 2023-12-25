#pragma once
#include <Runtime/Object/API.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API WindowAPI : API<WindowAPI>
	{
		friend class PlatformWindow;
		friend class WindowModule;
	public:
		static SharedHeap<PlatformWindow> GetDefaultWindow();
		static Array<SharedHeap<PlatformWindow>> GetWindows();
	private:
		static void _RegisterWindow(const SharedHeap<PlatformWindow>& pWindow);
		static void _RemoveWindow(PlatformWindow* pWindow);
	public:
		WindowAPI();
		~WindowAPI();
	private:
		void _PollEvents();
	private:
		Array<SharedHeap<PlatformWindow>> mWindows;
		HashMap<PlatformWindow*, SharedHeap<PlatformWindow>> mMap;
	};
}
