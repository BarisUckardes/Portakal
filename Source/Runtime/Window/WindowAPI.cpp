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
	void WindowAPI::_RegisterWindow(const SharedHeap<PlatformWindow>& pTargetWindow)
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Add for both map and the array
		pAPI->mWindows.Add(pTargetWindow);
	}
	void WindowAPI::_RemoveWindow(PlatformWindow* pTargetWindow)
	{
		WindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		for (UInt32 i = 0; i < pAPI->mWindows.GetSize(); i++)
		{
			const SharedHeap<PlatformWindow>& pWindow = pAPI->mWindows[i];
			if (pWindow.GetHeap() == pTargetWindow)
			{
				pAPI->mWindows.RemoveAt(i);
				return;
			}
		}
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
