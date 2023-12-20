#include "Swapchain.h"
#include <Runtime/Graphics/Device/GraphicsDevice.h>

namespace Portakal
{
    Swapchain::Swapchain(const SwapchainDesc& desc) : mColorFormat(desc.ColorFormat),mDepthStencilFormat(desc.DepthStencilFormat),mBufferCount(desc.BufferCount),mWindow(desc.pWindow),mSize(desc.pWindow->GetSize()),mIndex(0)
    {
        //Create internal resources
        CreateInternalResources(desc.pDevice.GetHeap());
    }
    void Swapchain::Resize(const uint16 width, const uint16 height)
    {
        //Wait for all fences to be idle
        GetOwnerDevice()->WaitDeviceIdle();

        //First free former textures
        FreeTextures();

        //Call implementation
        ResizeCore(width, height);
    }
    bool Swapchain::Present()
    {
        const bool bState = PresentCore();;
        IncrementIndex();
        return bState;
    }
    void Swapchain::WaitForPresent(const byte index)
    {
        GetOwnerDevice()->WaitFences(mPresentFences[index].GetHeapAddress(), 1);
    }
    void Swapchain::TransitionToPresent()
    {
        mCmdList->BeginRecording();
        for (byte i = 0; i < mBufferCount; i++)
        {
            CommandListTextureMemoryBarrierDesc barrierDesc = {};
            barrierDesc.MipIndex = 0;
            barrierDesc.ArrayIndex = 0;
            barrierDesc.AspectFlags = TextureAspectFlags::Color;

            barrierDesc.SourceLayout = TextureMemoryLayout::Unknown;
            barrierDesc.SourceQueue = GraphicsQueueType::Graphics;
            barrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::Unknown;
            barrierDesc.SourceStageFlags = PipelineStageFlags::TopOfPipe;

            barrierDesc.DestinationLayout = TextureMemoryLayout::Present;
            barrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
            barrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ColorAttachmentRead;
            barrierDesc.DestinationStageFlags = PipelineStageFlags::ColorAttachmentOutput;

            mCmdList->SetTextureMemoryBarrier(mTextures[i].GetHeap(), barrierDesc);
        }
        mCmdList->EndRecording();
        GetOwnerDevice()->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mLayoutFence.GetHeap());
        GetOwnerDevice()->WaitFences(mLayoutFence.GetHeapAddress(), 1);
    }
    bool Swapchain::SetMode(const WindowMode mode)
    {
        //Wait for idle
        GetOwnerDevice()->WaitDeviceIdle();

        //Set fullscreen
        const bool bSuccess = mode == WindowMode::Fullscreen ? SetFullScreen() : SetWindowed();

        return bSuccess;
    }
   
    void Swapchain::SetTextures(const Array<SharedHeap<Texture>>& textures, const Array<SharedHeap<TextureView>>& views)
    {
        DEV_LOG("Swapchain", "New set of textures&views arrived!");
        mTextures = textures;
        mViews = views;
    }
    void Swapchain::SetSize(const uint16 width, const uint16 height)
    {
        DEV_LOG("Swapchain", "Size: %d,%d", width, height);
        mSize = { width,height };
    }
    void Swapchain::OnShutdown()
    {
        //Free textures;
        FreeTextures();

        //Clear fencens
        mLayoutFence.Shutdown();
        for(byte i = 0;i<mBufferCount;i++)
            mPresentFences[i].Shutdown();

        //Clear cmds
        mCmdList.Shutdown();
        mCmdPool.Shutdown();
    }
    void Swapchain::CreateInternalResources(GraphicsDevice* pDevice)
    {
        //Create cmd pool
        CommandPoolDesc poolDesc = {};
        poolDesc.Type = CommandPoolType::Graphics;
        mCmdPool = pDevice->CreateCommandPool(poolDesc);

        //Create cmdlist
        CommandListDesc cmdListDesc = {};
        cmdListDesc.pPool = mCmdPool.GetHeap();
        mCmdList = pDevice->CreateCommandList(cmdListDesc);

        //Create layout fence
        mLayoutFence = pDevice->CreateFence();

        //Create present fences
        for (byte i = 0; i < mBufferCount; i++)
            mPresentFences.Add(pDevice->CreateFence());
    }
    void Swapchain::IncrementIndex()
    {
        mIndex = (mIndex + 1) % mBufferCount;
    }
    void Swapchain::FreeTextures()
    {
        //Clear textures,views and present fences first
        for (byte i = 0; i < mBufferCount; i++)
        {
            mViews[i].Shutdown();
            mTextures[i].Shutdown();
        }
        mViews.Clear();
        mTextures.Clear();
    }
}
