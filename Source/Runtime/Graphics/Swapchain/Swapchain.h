#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Swapchain/SwapchainDesc.h>
#include <Runtime/Graphics/Fence/Fence.h>

namespace Portakal
{
	class RUNTIME_API Swapchain : public GraphicsDeviceObject
	{
	public:
		Swapchain(const SwapchainDesc& desc);
		~Swapchain() = default;

		FORCEINLINE byte GetBufferCount() const noexcept
		{
			return mBufferCount;
		}
		FORCEINLINE TextureFormat GetColorFormat() const noexcept
		{
			return mColorFormat;
		}
		FORCEINLINE TextureFormat GetDepthStencilFormat() const noexcept
		{
			return mDepthStencilFormat;
		}
		FORCEINLINE SharedHeap<PlatformWindow> GetWindow() const noexcept
		{
			return mWindow;
		}
		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE SharedHeap<Fence> GetFence() const noexcept
		{
			return mFence;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::Swapchain; }
		virtual void Present() = 0;
	private:
		const byte mBufferCount;
		const TextureFormat mColorFormat;
		const TextureFormat mDepthStencilFormat;
		const SharedHeap<PlatformWindow> mWindow;
		SharedHeap<Fence> mFence;
		Vector2US mSize;
	};
}
