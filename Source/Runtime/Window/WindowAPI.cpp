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

		pAPI->mWindows.Add(pWindow);
	}
	void WindowAPI::_RemoveWindow(const SharedHeap<PlatformWindow>& pWindow)
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mWindows.Remove(pWindow);
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
		for (int32 i = 0; i < mWindows.GetSize(); i++)
		{
			mWindows[i].Shutdown();
			i--;
		}
	}
}
