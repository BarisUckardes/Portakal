#include "Win32Window.h"
#include <Runtime/Win32/Win32Keys.h>

namespace Portakal
{
	Win32Window* GetUserWindowData(const HWND hwnd)
	{
		return (Win32Window*)GetWindowLongPtr(hwnd, -21); // -21 is a specific number that holds the user provided information
	}
	LRESULT Win32Window::Win32WindowMessageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CREATE:
		{
			Win32Window* pWindow = (Win32Window*)((LPCREATESTRUCT)lParam)->lpCreateParams;

			SetWindowLongPtr(hwnd, -21, (LONG_PTR)pWindow);
			break;
		}
		case WM_DESTROY:
		{
			DragAcceptFiles(hwnd, FALSE);
			break;
		}
		case WM_CLOSE:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);
			WindowEventData event = {};
			event.Type = WindowEventType::WindowClosed;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_MOVE:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::WindowMoved;
			event.WindowPosition = { LOWORD(lParam),HIWORD(lParam) };

			pWindow->DispatchWin32Event(event);

			break;
		}
		case WM_SIZE:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::WindowResized;
			event.WindowSize = { LOWORD(lParam),HIWORD(lParam) };

			pWindow->DispatchWin32Event(event);
			break;
		}
		
		case WM_MOUSEMOVE:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseMoved;
			event.MousePosition = { LOWORD(lParam),HIWORD(lParam) };

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_MOUSEWHEEL:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseScrolled;
			event.MouseWheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseButtonDown;
			event.MouseButton = MouseButtons::Left;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_LBUTTONUP:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseButtonUp;
			event.MouseButton = MouseButtons::Left;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseButtonDown;
			event.MouseButton = MouseButtons::Right;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_RBUTTONUP:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::MouseButtonUp;
			event.MouseButton = MouseButtons::Right;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);
			WindowEventData event = {};
			event.Type = WindowEventType::KeyboardDown;
			event.KeyboardKey = Win32Keys::GetKey(wParam);

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_KEYUP:
		case WM_SYSKEYUP:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::KeyboardUp;
			event.KeyboardKey = Win32Keys::GetKey(wParam);

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_CHAR:
		{
			Win32Window* pWindow = GetUserWindowData(hwnd);

			WindowEventData event = {};
			event.Type = WindowEventType::Char;
			event.KeyboardChar = wParam;

			pWindow->DispatchWin32Event(event);
			break;
		}
		case WM_DEVICECHANGE:
		{
			/*
			* Check if any input device has been removed!
			*/

			break;
		}
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);

		}

		return 0;
	}

	Win32Window::Win32Window(const WindowDesc& desc) : PlatformWindow(desc)
	{
		constexpr const Char WINDOW_CLASS_NAME[] = "PortakalWin32WindowClass";

		//Get process handle
		const HINSTANCE processHandle = GetModuleHandle(NULL);

		//Register window class
		WNDCLASSEX windowClass = {};
		windowClass.cbSize = sizeof(windowClass);
		windowClass.hInstance = processHandle;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = sizeof(Win32Window*);
		windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = WINDOW_CLASS_NAME;
		windowClass.lpfnWndProc = Win32WindowMessageProc;

		DEV_ASSERT(RegisterClassEx(&windowClass) != NULL, "Win32Window", "Failed to register win32 window class!!");

		//Create window
		const HWND windowHandle = CreateWindowEx(
			0,
			WINDOW_CLASS_NAME,
			desc.Title.GetSource(),
			WS_OVERLAPPEDWINDOW | WS_EX_ACCEPTFILES,
			desc.Position.X,desc.Position.Y,desc.Size.X,desc.Size.Y,
			NULL,NULL,processHandle,
			this
		);

		//Add message filters
		ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);
		ChangeWindowMessageFilter(WM_COPYDATA, MSGFLT_ADD);
		ChangeWindowMessageFilter(0x0049, MSGFLT_ADD);

		mWindowHandle = windowHandle;
		mDeviceContext = GetDC(windowHandle);
	}
	void Win32Window::DispatchWin32Event(const WindowEventData& event)
	{
		DispatchWindowEvent(event);
	}
	void Win32Window::OnShutdown()
	{
		PlatformWindow::OnShutdown();

		ReleaseDC(mWindowHandle, mDeviceContext);
		mDeviceContext = NULL;

		DestroyWindow(mWindowHandle);
		mWindowHandle = NULL;
	}
	void Win32Window::SetTitleCore(const String& title)
	{
		SetWindowText(mWindowHandle, *title);
	}
	void Win32Window::SetSizeCore(const Vector2US size)
	{
		SetWindowPos(mWindowHandle, NULL, 0, 0, size.X, size.Y, SWP_NOMOVE | SWP_SHOWWINDOW);
	}
	void Win32Window::SetPositionCore(const Vector2I position)
	{
		SetWindowPos(mWindowHandle, NULL, position.X, position.Y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	}
	void Win32Window::SetModeCore(WindowMode mode)
	{
		switch (mode)
		{
			case Portakal::WindowMode::Windowed:
			default:
			{
				SetWindowLongPtr(mWindowHandle, GWL_STYLE, WS_OVERLAPPEDWINDOW);
				break;
			}
			case Portakal::WindowMode::WindowedBorderless:
			{
				SetWindowLongPtr(mWindowHandle, GWL_STYLE, WS_POPUP);
				break;
			}
			case Portakal::WindowMode::Fullscreen:
			{
				SetWindowLongPtr(mWindowHandle, GWL_STYLE, WS_POPUP);
				break;
			}
		}
	
	}
	void Win32Window::SwitchMonitorCore(const SharedHeap<PlatformMonitor>& pMonitor)
	{
	}
	void Win32Window::PollMessagesCore()
	{
		MSG msg = {};
		while (PeekMessage(&msg, mWindowHandle, NULL, NULL, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	void Win32Window::ShowCore()
	{
		ShowWindow(mWindowHandle, SW_SHOW);
	}
	void Win32Window::HideCore()
	{
		ShowWindow(mWindowHandle, SW_HIDE);
	}
}
