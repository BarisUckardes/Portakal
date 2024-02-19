#include "Swapchain.h"
#include <Runtime/Graphics/Device/GraphicsDevice.h>

namespace Portakal
{
	Swapchain::~Swapchain()
	{
		ClearTextures();
	}
	void Swapchain::Resize(const UInt32 width, const UInt32 height)
	{
		//Wait device idle
		GetDevice()->WaitDeviceIdle();

		//Clear the textures
		ClearTextures();

		//Resize
		ResizeCore(width, height);

		mWidth = width;
		mHeight = height;
	}
	void Swapchain::Present(Semaphore** ppWaitSemahpores, const UInt32 waitSemaphoreCount)
	{
		//First wait for target fence
		GetDevice()->WaitFences(mPresentFences[mImageIndex].GetHeapAddress(), 1);
		GetDevice()->ResetFences(mPresentFences[mImageIndex].GetHeapAddress(),1);

		//Present
		PresentCore(ppWaitSemahpores,waitSemaphoreCount);

		//Increment index
		mImageIndex = (mImageIndex + 1) % mBufferCount;
	}
	void Swapchain::WaitForPresent(const Byte index)
	{
		GetDevice()->WaitFences(mPresentFences[index].GetHeapAddress(), 1);
	}
	
	Swapchain::Swapchain(const SwapchainDesc& desc, GraphicsDevice* pDevice) :
		GraphicsDeviceObject(pDevice),mMode(desc.Mode),mBufferCount(desc.BufferCount),mColorBufferFormat(desc.ColorFormat),mDepthStencilBufferFormat(desc.DepthStencilFormat),mWindow(desc.pWindow),
		mImageIndex(0),mQueue(desc.pQueue)
	{
		mWidth = mWindow->GetSize().X;
		mHeight = mWindow->GetSize().Y;

		for (Byte i = 0; i < desc.BufferCount; i++)
			mPresentFences.Add(pDevice->CreateFence({ true }));
	}
	void Swapchain::SetCustomSize(const UInt32 width, const UInt32 height)
	{
		mWidth = width;
		mHeight = height;
	}
	void Swapchain::ClearTextures()
	{
		for (Byte i = 0; i < mColorTextures.GetSize(); i++)
		{
			mColorTextureViews[i].Shutdown();
			mColorTextures[i].Shutdown();
		}
		mColorTextureViews.Clear();
		mColorTextures.Clear();
	}
	void Swapchain::SetCustomSwapchainTextures(const Array<SharedHeap<Texture>>& textures)
	{
		mColorTextures = textures;
		for (const SharedHeap<Texture> pTexture : textures)
		{
			TextureViewDesc desc = {};
			desc.AspectFlags = TextureAspectFlags::Color;
			desc.pTexture = pTexture;
			desc.ArrayLevel = 0;
			desc.MipLevel = 0;

			mColorTextureViews.Add(GetDevice()->CreateTextureView(desc));
		}
	}
}
