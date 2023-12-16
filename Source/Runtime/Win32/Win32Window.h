#pragma once
#include <Runtime/Platform/PlatformWindow.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Window : public PlatformWindow
	{
	private:
		static LRESULT CALLBACK Win32WindowMessageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	public:
		Win32Window(const WindowDesc& desc);
		~Win32Window() = default;

		FORCEINLINE HWND GetWin32WindowHandle() const noexcept
		{
			return mWindowHandle;
		}
		FORCEINLINE HDC GetWin32DeviceContext() const noexcept
		{
			return mDeviceContext;
		}

		void DispatchWin32Event(const WindowEventData& event);
	private:
		void OnShutdown() override;
		void SetTitleCore(const String& title) override;
		void SetSizeCore(const Vector2US size) override;
		void SetPositionCore(const Vector2I position) override;
		void SetModeCore(const WindowMode mode) override;
		void SwitchMonitorCore(const SharedHeap<PlatformMonitor>& pMonitor) override;
		void PollMessagesCore() override;
		void ShowCore() override;
		void HideCore() override;
	private:
		HWND mWindowHandle;
		HDC mDeviceContext;
	};
}

