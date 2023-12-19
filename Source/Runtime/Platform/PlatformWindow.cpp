#include "PlatformWindow.h"
#include <Runtime/Graphics/Swapchain/Swapchain.h>

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
		SetPositionCore(position);
		mPosition = position;
	}
	void PlatformWindow::SetMode(const WindowMode mode)
	{
		//Call implementation
		SetModeCore(mode);

		//Set new mode
		mMode = mode;

		//Set sizes
		if (mode == WindowMode::Fullscreen)
		{
			SetPosition({ 0,0 });
			SetSize({ 3920,2160 });
		}
		else
		{

		}

		//Set swapchain mode
		if (!mSwapchain.IsShutdown())
			mSwapchain->SetFullScreen(mode == WindowMode::Fullscreen);
	}
	void PlatformWindow::SwitchMonitor(const SharedHeap<PlatformMonitor>& pMonitor)
	{
		//Call implementation
		SwitchMonitorCore(pMonitor);

		//Set monitor
		mMonitor = pMonitor;

		//Set mode right away
		SetMode(mMode);
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
		switch (data.Type)
		{
			case Portakal::WindowEventType::None:
				break;
			case Portakal::WindowEventType::WindowClosed:
				Shutdown();
				break;
			case Portakal::WindowEventType::WindowMoved:
				break;
			case Portakal::WindowEventType::WindowResized:
				OnWindowResize(data.WindowSize);
				break;
			case Portakal::WindowEventType::DragDrop:
				break;
			case Portakal::WindowEventType::KeyboardDown:
				break;
			case Portakal::WindowEventType::KeyboardUp:
				break;
			case Portakal::WindowEventType::Char:
				break;
			case Portakal::WindowEventType::MouseButtonDown:
				break;
			case Portakal::WindowEventType::MouseButtonUp:
				break;
			case Portakal::WindowEventType::MouseMoved:
				break;
			case Portakal::WindowEventType::MouseScrolled:
				break;
			case Portakal::WindowEventType::GamepadButtonDown:
				break;
			case Portakal::WindowEventType::GamepadButtonUp:
				break;
			case Portakal::WindowEventType::GamepadTriggerMove:
				break;
			case Portakal::WindowEventType::GamepadThumbMove:
				break;
			default:
				break;
		}
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
		//Resize swapchain
		if (!mSwapchain.IsShutdown())
		{
			mSwapchain->Resize(size.X, size.Y);
			mSwapchain->TransitionToPresent();
		}

		//Set size
		mSize = size;
	}
	void PlatformWindow::OnWindowMoved(const Vector2I position)
	{
	}
	void PlatformWindow::_SetSwapchain(const SharedHeap<Swapchain>& swapchain)
	{
		mSwapchain = swapchain;
	}
}
