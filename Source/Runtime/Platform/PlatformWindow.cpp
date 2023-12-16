#include "PlatformWindow.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Window.h>
typedef Portakal::Win32Window PlatformAbstraction;
#endif

namespace Portakal
{
	SharedHeap<PlatformWindow> PlatformWindow::Create(const WindowDesc& desc)
	{
		return new PlatformAbstraction(desc);
	}
	void PlatformWindow::SetTitle(const String& title)
	{
		SetTitleCore(title);
		mTitle = title;
	}
	void PlatformWindow::SetSize(const Vector2US size)
	{
		SetSizeCore(size);
		mSize = size;
	}
	void PlatformWindow::SetPosition(const Vector2I position)
	{
		SetPosition(position);
		mPosition = position;
	}
	void PlatformWindow::SetMode(const WindowMode mode)
	{
		SetModeCore(mode);
		mMode = mode;
	}
	void PlatformWindow::SwitchMonitor(const SharedHeap<PlatformMonitor>& pMonitor)
	{
		SwitchMonitorCore(pMonitor);
		mMonitor = pMonitor;
	}
	void PlatformWindow::PollMessages()
	{
		mEvents.Clear();
		PollMessagesCore();
	}
	void PlatformWindow::Show()
	{
		ShowCore();
		mVisible = true;
	}
	void PlatformWindow::Hide()
	{
		HideCore();
		mVisible = false;
	}
	void PlatformWindow::DispatchWindowEvent(const WindowEventData& data)
	{
		if (data.Type == WindowEventType::WindowClosed)
			Shutdown();
	}
	void PlatformWindow::OnShutdown()
	{
		DEV_LOG("PlatformWindow", "Window shutdown");
	}
	void PlatformWindow::OnWindowClosed()
	{

	}
	void PlatformWindow::OnWindowResize(const Vector2US size)
	{
	}
	void PlatformWindow::OnWindowMoved(const Vector2I position)
	{
	}
}
