#include "Swapchain.h"
#include <Runtime/Graphics/Device/GraphicsDevice.h>

namespace Portakal
{
    Swapchain::Swapchain(const SwapchainDesc& desc,GraphicsDevice* pDevice) : 
        GraphicsDeviceObject(pDevice),
        mColorFormat(desc.ColorFormat),mDepthStencilFormat(desc.DepthStencilFormat),mBufferCount(desc.BufferCount),mWindow(desc.pWindow),mPresentMode(desc.PresentMode), mSize(desc.pWindow->GetSize()), mIndex(0),mQueue(desc.pQueue)
    {
        //Create internal resources
        CreateInternalResources(desc.pDevice.GetHeap());
    }
    void Swapchain::Resize(const UInt16 width, const UInt16 height)
    {
        //Wait for all fences to be idle
        GetOwnerDevice()->WaitDeviceIdle();

        //First free former textures
        FreeTextures();

        //Call implementation
        ResizeCore(width, height);
    }
    Bool8 Swapchain::Present()
    {
        //First wait for the target fence
        GetOwnerDevice()->WaitFences(mPresentFences[mIndex].GetHeapAddress(), 1);
        GetOwnerDevice()->ResetFences(mPresentFences[mIndex].GetHeapAddress(), 1);

        //Present
        const Bool8 bState = PresentCore();

        //Increment the internal index
        IncrementIndex();

        return bState;
    }
    void Swapchain::WaitForPresent(const Byte index)
    {
        GetOwnerDevice()->WaitFences(mPresentFences[index].GetHeapAddress(), 1);
    }
   
    void Swapchain::SetTextures(const Array<SharedHeap<Texture>>& textures)
    {
        mTextures = textures;
        for (const SharedHeap<Texture>& pTexture : textures)
        {
            TextureViewDesc desc = {};
            desc.AspectFlags = TextureAspectFlags::Color;
            desc.pTexture = pTexture;
            desc.ArrayLevel = 0;
            desc.MipLevel = 0;
            desc.Format = pTexture->GetFormat();

            mViews.Add(GetOwnerDevice()->CreateTextureView(desc));
        }
    }
    void Swapchain::SetSize(const UInt16 width, const UInt16 height)
    {
        mSize = { width,height };
    }
    void Swapchain::OnShutdown()
    {
        //Free textures;
        FreeTextures();

        //Clear fencens
        mLayoutFence.Shutdown();
        for(Byte i = 0;i<mBufferCount;i++)
            mPresentFences[i].Shutdown();

    }
    void Swapchain::CreateInternalResources(GraphicsDevice* pDevice)
    {
        //Create layout fence
        mLayoutFence = pDevice->CreateFence(false);

        //Create present fences
        for (Byte i = 0; i < mBufferCount; i++)
            mPresentFences.Add(pDevice->CreateFence(true));
    }
    void Swapchain::IncrementIndex()
    {
        mIndex = (mIndex + 1) % mBufferCount;
    }
    void Swapchain::FreeTextures()
    {
        //Clear textures,views and present fences first
        for (Byte i = 0; i < mBufferCount; i++)
        {
            mViews[i].Shutdown();
            mTextures[i].Shutdown();
        }
        mViews.Clear();
        mTextures.Clear();
    }
}
