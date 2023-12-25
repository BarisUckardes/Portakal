#include "PlatformWindow.h"
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Window/WindowAPI.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Window.h>
typedef Portakal::Win32Window PlatformAbstraction;
#endif

namespace Portakal
{
	SharedHeap<PlatformWindow> PlatformWindow::Create(const WindowDesc& desc)
	{
		//Create
		SharedHeap<PlatformWindow> pWindow = new PlatformAbstraction(desc);

		//Set mode
		pWindow->SetMode(desc.Mode);

		//Register to the API
		WindowAPI::_RegisterWindow(pWindow.GetHeap());

		return pWindow;
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
	void PlatformWindow::SetMode( WindowMode mode)
	{
		//Call implementation
		SetModeCore(mode);

		//Set new mode
		mMode = mode;

		const Vector2US monitorSize = mMonitor.IsShutdown() ? Vector2US(1024, 1024) : mMonitor->GetSize();
		const Vector2US halfMonitorSize = monitorSize / 2;
		const Vector2I position = mMonitor->GetPosition();

		//Set position
		SetPosition(position);

		//Set sizes
		switch (mode)
		{
			case Portakal::WindowMode::Windowed:
			default:
			{
				SetSize(halfMonitorSize);
				break;
			}
			case Portakal::WindowMode::WindowedBorderless:
			{
				SetSize(halfMonitorSize);
				break;
			}
			case Portakal::WindowMode::Fullscreen:
			{
				SetSize(monitorSize);
				break;
			}
		}
		
		//Set swapchain mode
		if (!mSwapchain.IsShutdown())
			mSwapchain->SetMode(mode);
	}
	void PlatformWindow::SwitchMonitor(const SharedHeap<PlatformMonitor>& pMonitor)
	{
		//Validate monitor integrity
		if (pMonitor.IsShutdown())
		{
			DEV_LOG("PlatformWindow", "Given monitor is shutdown!");
			return;
		}

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
		WindowAPI::_RemoveWindow(this);

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
