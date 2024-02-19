#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Swapchain/SwapchainDesc.h>
#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Graphics/Semaphore/Semaphore.h>


namespace Portakal
{
	class RUNTIME_API Swapchain : public GraphicsDeviceObject
	{
	public:
		~Swapchain();

		FORCEINLINE PresentMode GetMode() const noexcept
		{
			return mMode;
		}
		FORCEINLINE Byte GetBufferCount() const noexcept
		{
			return mBufferCount;
		}
		FORCEINLINE TextureFormat GetColorBufferFormat() const noexcept
		{
			return mColorBufferFormat;
		}
		FORCEINLINE TextureFormat GetDepthStencilBufferFormat() const noexcept
		{
			return mDepthStencilBufferFormat;
		}
		FORCEINLINE const Array<SharedHeap<Texture>>& GetColorTextures() const noexcept
		{
			return mColorTextures;
		}
		FORCEINLINE const Array<SharedHeap<TextureView>>& GetColorTextureViews() const noexcept
		{
			return mColorTextureViews;
		}
		FORCEINLINE const SharedHeap<PlatformWindow> GetWindow() const noexcept
		{
			return mWindow;
		}
		FORCEINLINE UInt32 GetWidth() const noexcept
		{
			return mWidth;
		}
		FORCEINLINE UInt32 GetHeight() const noexcept
		{
			return mHeight;
		}
		FORCEINLINE Byte GetCurrentImageIndex() const noexcept
		{
			return mImageIndex;
		}
		FORCEINLINE const GraphicsQueue* GetQueue() const noexcept
		{
			return mQueue;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Swapchain;
		}

		void Resize(const UInt32 width, const UInt32 height);
		void Present(Semaphore** ppWaitSemahpores,const UInt32 waitSemaphoreCount);
		void WaitForPresent(const Byte index);
	protected:
		Swapchain(const SwapchainDesc& desc, GraphicsDevice* pDevice);

		void SetCustomSize(const UInt32 width, const UInt32 height);
		void SetCustomSwapchainTextures(const Array<SharedHeap<Texture>>& textures);

		FORCEINLINE SharedHeap<Fence> GetPresentFence(const Byte index)
		{
			return mPresentFences[index];
		}

		virtual void ResizeCore(const UInt32 width, const UInt32 height) = 0;
		virtual void PresentCore(Semaphore** ppWaitSemahpores, const UInt32 waitSemaphoreCount) = 0;
	private:
		void ClearTextures();
	private:
		const PresentMode mMode;
		const Byte mBufferCount;
		const TextureFormat mColorBufferFormat;
		const TextureFormat mDepthStencilBufferFormat;
		const SharedHeap<PlatformWindow> mWindow;
		const GraphicsQueue* mQueue;
		Array<SharedHeap<Fence>> mPresentFences;
		Array<SharedHeap<Texture>> mColorTextures;
		Array<SharedHeap<TextureView>> mColorTextureViews;
		UInt32 mWidth;
		UInt32 mHeight;
		Byte mImageIndex;
	};
}
