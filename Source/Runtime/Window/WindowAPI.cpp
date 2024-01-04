#include "WindowAPI.h"

namespace Portakal
{
	SharedHeap<PlatformWindow> WindowAPI::GetDefaultWindow()
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mWindows.IsEmpty() ? nullptr : pAPI->mWindows.GetFirst();
	}
	Array<SharedHeap<PlatformWindow>> WindowAPI::GetWindows()
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mWindows;
	}
	void WindowAPI::_RegisterWindow(const SharedHeap<PlatformWindow>& pWindow)
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Add for both map and the array
		pAPI->mWindows.Add(pWindow);
		pAPI->mMap.Insert(pWindow.GetHeap(), pWindow);
	}
	void WindowAPI::_RemoveWindow(PlatformWindow* pWindow)
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Get index
		const Int32 index = pAPI->mMap.FindIndex(pWindow);
		if (index == -1)
			return;

		//Remove from both map and the array
		pAPI->mMap.Remove(pWindow);
		pAPI->mWindows.RemoveAt(index);
	}
	void WindowAPI::_PollEvents()
	{
		for (SharedHeap<PlatformWindow>& pWindow : mWindows)
			pWindow->PollMessages();
	}
	WindowAPI::WindowAPI()
	{

	}
	WindowAPI::~WindowAPI()
	{

	}
}
