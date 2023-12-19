#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Swapchain/SwapchainDesc.h>
#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Graphics/Command/CommandPool.h>
#include <Runtime/Graphics/Command/CommandList.h>
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
		FORCEINLINE SharedHeap<Fence> GetPresentFence(const byte index = 0) const noexcept
		{
			return mPresentFences[index];
		}
		FORCEINLINE SharedHeap<Fence> GetLayoutFence() const noexcept
		{
			return mLayoutFence;
		}
		FORCEINLINE Array<SharedHeap<Texture>> GetTextures() const noexcept
		{
			return mTextures;
		}
		FORCEINLINE Array<SharedHeap<TextureView>> GetTextureViews() const noexcept
		{
			return mViews;
		}
		FORCEINLINE byte GetImageIndex() const noexcept
		{
			return mIndex;
		}
		FORCEINLINE SharedHeap<Texture> GetCurrentTexture() const noexcept
		{
			return mTextures[mIndex];
		}
		FORCEINLINE SharedHeap<TextureView> GetCurrentView() const noexcept
		{
			return mViews[mIndex];
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::Swapchain; }
	
		void Present();
		void WaitForPresent(const byte index);
		void TransitionToPresent();
	protected:
		void SetTextures(const Array<SharedHeap<Texture>>& textures, const Array<SharedHeap<TextureView>>& views);
		void SetSize(const uint16 width, const uint16 height);

		virtual void OnShutdown() override;
		virtual void PresentCore() = 0;
	private:
		void CreateInternalResources(GraphicsDevice* pDevice);
		void IncrementIndex();
	private:
		const byte mBufferCount;
		const TextureFormat mColorFormat;
		const TextureFormat mDepthStencilFormat;
		const SharedHeap<PlatformWindow> mWindow;
		Array<SharedHeap<Texture>> mTextures;
		Array<SharedHeap<TextureView>> mViews;
		Array<SharedHeap<Fence>> mPresentFences;
		SharedHeap<Fence> mLayoutFence;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<CommandList> mCmdList;
		Vector2US mSize;
		byte mIndex;
	};
}
