#pragma once
#include <Runtime/Window/WindowDesc.h>
#include <Runtime/Object/Object.h>
#include <Runtime/Window/WindowEventData.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class Swapchain;
	class RUNTIME_API PlatformWindow : public Object
	{
		friend class GraphicsDevice;
		friend class SharedHeap<PlatformWindow>;
	public:
		static SharedHeap<PlatformWindow> Create(const WindowDesc& desc);
	public:
		FORCEINLINE const Array<WindowEventData>& GetEvents() const noexcept
		{
			return mEvents;
		}
		FORCEINLINE const SharedHeap<PlatformMonitor>& GetMonitor() const noexcept
		{
			return mMonitor;
		}
		FORCEINLINE const SharedHeap<Swapchain>& GetSwapchain() const noexcept
		{
			return mSwapchain;
		}
		FORCEINLINE String GetTitle() const noexcept
		{
			return mTitle;
		}
		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE Vector2I GetPosition() const noexcept
		{
			return mPosition;
		
		}
		FORCEINLINE WindowMode GetMode() const noexcept
		{
			return mMode;
		}
		FORCEINLINE bool IsVisible() const noexcept
		{
			return mVisible;
		}

		void SetTitle(const String& title);
		void SetSize(const Vector2US size);
		void SetPosition(const Vector2I position);
		void SetMode(const WindowMode mode);
		void SwitchMonitor(const SharedHeap<PlatformMonitor>& pMonitor);
		void PollMessages();
		void Show();
		void Hide();
	protected:
		PlatformWindow(const WindowDesc& desc) : mVisible(false), mSwapchain(nullptr), mTitle(desc.Title), mSize(desc.Size), mPosition(desc.Position), mMode(desc.Mode), mMonitor(desc.pMonitor)
		{
			//Check if has no monitor
			if (mMonitor.IsShutdown())
			{
				DEV_LOG("Window", "No monitor is specified within the WindowDesc, choosing the primary monitor as a default behaviour");
				mMonitor = PlatformMonitor::GetPrimaryMonitor();
			}
			DEV_SUCCESS("Window", "Window created.");
		}
		~PlatformWindow() = default;

		void DispatchWindowEvent(const WindowEventData& data);
		virtual void OnShutdown() override;
		virtual void SetTitleCore(const String& title) = 0;
		virtual void SetSizeCore(const Vector2US size) = 0;
		virtual void SetPositionCore(const Vector2I position) = 0;
		virtual void SetModeCore(const WindowMode mode) = 0;
		virtual void SwitchMonitorCore(const SharedHeap<PlatformMonitor>& pMonitor) = 0;
		virtual void PollMessagesCore() = 0;
		virtual void ShowCore() = 0;
		virtual void HideCore() = 0;
	private:
		void OnWindowClosed();
		void OnWindowResize(const Vector2US size);
		void OnWindowMoved(const Vector2I position);
		void _SetSwapchain(const SharedHeap<Swapchain>& swapchain);
	private:
		Array<WindowEventData> mEvents;
		SharedHeap<PlatformMonitor> mMonitor;
		SharedHeap<Swapchain> mSwapchain;
		String mTitle;
		Vector2US mSize;
		Vector2I mPosition;
		WindowMode mMode;
		bool mVisible;
	};
}
