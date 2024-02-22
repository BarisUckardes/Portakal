#include "GraphicsDevice.h"
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
    GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc* pDesc) : mOwnerAdapter(pDesc->pAdapter)
    {

    }
  
    SharedHeap<Texture> GraphicsDevice::CreateTexture(const TextureDesc& desc)
    {
        /**
        * Validate depth
        */
        DEV_ASSERT(desc.Size.Z > 0, "GraphicsDevice", "A texture should always have it's depth value higher than 0");

        /**
        * Validate mip levels
        */
        DEV_ASSERT(desc.MipLevels > 0, "GraphicsDevice", "A texture should always have it's mip levels value higher than 0");

        const UInt16 maxDimension = Math::Max(desc.Size.X, desc.Size.Y);
        const UInt16 maxMipCount = Math::Log2(maxDimension) + 1;
        DEV_ASSERT(maxMipCount > desc.MipLevels, "Texture", "Requested mip levels are not possible with this texture, considering the dimensions the max mip levels can be %d while you requested %d",
            maxMipCount, desc.MipLevels);

        SharedHeap<Texture> Texture = CreateTextureCore(desc);
        RegisterChild(Texture.QueryAs<GraphicsDeviceObject>());
        return Texture;
    }
    SharedHeap<TextureView> GraphicsDevice::CreateTextureView(const TextureViewDesc& desc)
    {
        SharedHeap<TextureView> pView = CreateTextureViewCore(desc);
        RegisterChild(pView.QueryAs<GraphicsDeviceObject>());
        return pView;
    }
 
    SharedHeap<CommandList> GraphicsDevice::CreateCommandList(const CommandListDesc& desc)
    {
        SharedHeap<CommandList> pCmdList = CreateCommandListCore(desc);
        RegisterChild(pCmdList.QueryAs<GraphicsDeviceObject>());
        return pCmdList;
    }
    SharedHeap<CommandPool> GraphicsDevice::CreateCommandPool(const CommandPoolDesc& desc)
    {
        SharedHeap<CommandPool> pCmdPool = CreateCommandPoolCore(desc);
        RegisterChild(pCmdPool.QueryAs<GraphicsDeviceObject>());
        return pCmdPool;
    }
    SharedHeap<Pipeline> GraphicsDevice::CreateGraphicsPipeline(const GraphicsPipelineDesc& desc)
    {
        /**
        * Check pipeline shaders
        */
        DEV_ASSERT(desc.GraphicsShaders.GetSize() > 0, "GraphicsDevice", "Pipeline without shaders is invalid!");

        /**
        * Create and register pipeline
        */
        SharedHeap<Pipeline> pPipeline = CreateGraphicsPipelineCore(desc);
        RegisterChild(pPipeline.QueryAs<GraphicsDeviceObject>());
        return pPipeline;
    }
    SharedHeap<Pipeline> GraphicsDevice::CreateComputePipeline(const ComputePipelineDesc& desc)
    {
        /**
        * Check pipeline shaders
        */
        DEV_ASSERT(!desc.ComputeShader.IsShutdown(), "GraphicsDevice", "Pipeline without shaders is invalid!");

        /**
        * Create and register pipeline
        */
        SharedHeap<Pipeline> pPipeline = CreateComputePipeline(desc);
        RegisterChild(pPipeline.QueryAs<GraphicsDeviceObject>());
        return pPipeline;
    }
    SharedHeap<GraphicsMemory> GraphicsDevice::CreateMemoryHeap(const GraphicsMemoryDesc& desc)
    {
        SharedHeap<GraphicsMemory> pHeap = CreateMemoryHeapCore(desc);
        RegisterChild(pHeap.QueryAs<GraphicsDeviceObject>());
        return pHeap;
    }
    SharedHeap<GraphicsBuffer> GraphicsDevice::CreateBuffer(const GraphicsBufferDesc& desc)
    {
        SharedHeap<GraphicsBuffer> pBuffer = CreateBufferCore(desc);
        RegisterChild(pBuffer.QueryAs<GraphicsDeviceObject>());
        return pBuffer;
    }
    SharedHeap<Shader> GraphicsDevice::CreateShader(const ShaderDesc& desc)
    {
        SharedHeap<Shader> pShader = CreateShaderCore(desc);
        RegisterChild(pShader.QueryAs<GraphicsDeviceObject>());
        return pShader;
    }
    SharedHeap<Sampler> GraphicsDevice::CreateSampler(const SamplerDesc& desc)
    {
        SharedHeap<Sampler> pSampler = CreateSamplerCore(desc);
        RegisterChild(pSampler.QueryAs<GraphicsDeviceObject>());
        return pSampler;
    }
    SharedHeap<DescriptorSetLayout> GraphicsDevice::CreateDescriptorSetLayout(const DescriptorSetLayoutDesc& desc)
    {
        SharedHeap<DescriptorSetLayout> pDescriptorLayout = CreateDescriptorSetLayoutCore(desc);
        RegisterChild(pDescriptorLayout.QueryAs<GraphicsDeviceObject>());
        return pDescriptorLayout;
    }
    SharedHeap<DescriptorSetPool> GraphicsDevice::CreateDescriptorSetPool(const DescriptorSetPoolDesc& desc)
    {
        SharedHeap<DescriptorSetPool> pPool = CreateDescriptorSetPoolCore(desc);
        RegisterChild(pPool.QueryAs<GraphicsDeviceObject>());
        return pPool;
    }
    SharedHeap<DescriptorSet> GraphicsDevice::CreateDescriptorSet(const DescriptorSetDesc& desc)
    {
        SharedHeap<DescriptorSet> pResourceSet = CreateDescriptorSetCore(desc);
        RegisterChild(pResourceSet.QueryAs<GraphicsDeviceObject>());
        return pResourceSet;
    }
    SharedHeap<Fence> GraphicsDevice::CreateFence(const bool bSignalled)
    {
        //Create fence
        SharedHeap<Fence> pFence = CreateFenceCore(bSignalled);

        //Register
        RegisterChild(pFence.QueryAs<GraphicsDeviceObject>());

        return pFence;
    }
    SharedHeap<Semaphore> GraphicsDevice::CreateSyncObject()
    {
        SharedHeap<Semaphore> pSyncObject = CreateSyncObjectCore();

        RegisterChild(pSyncObject.QueryAs<GraphicsDeviceObject>());

        return pSyncObject;
    }
    SharedHeap<Swapchain> GraphicsDevice::CreateSwapchain(const SwapchainDesc& desc)
    {
        //Check if window has already a swapchain
        DEV_ASSERT(desc.pWindow->GetSwapchain().IsShutdown(), "GraphicsDevice", "Given window has already a swapchain");

        //Create swapchain
        SharedHeap<Swapchain> pSwapchain = CreateSwapchainCore(desc);

        //Register
        RegisterChild(pSwapchain.QueryAs<GraphicsDeviceObject>());

        //Set as main if no swapchain is available
        if (mMainSwapchain.IsShutdown())
            mMainSwapchain = pSwapchain;

        //Register swapchain to window
        desc.pWindow->_SetSwapchain(pSwapchain);

        return pSwapchain;
    }
    SharedHeap<RenderPass> GraphicsDevice::CreateRenderPass(const RenderPassDesc& desc)
    {
        SharedHeap<RenderPass> pResourceSet = CreateRenderPassCore(desc);
        RegisterChild(pResourceSet.QueryAs<GraphicsDeviceObject>());
        return pResourceSet;
    }
    SharedHeap<GraphicsQueue> GraphicsDevice::RentQueue(const GraphicsQueueDesc& desc)
    {
        SharedHeap<GraphicsQueue> pQueue = RentQueueCore(desc);

        RegisterChild(pQueue.QueryAs<GraphicsDeviceObject>());

        return pQueue;
    }
    void GraphicsDevice::ResetFences(Fence** ppFences, const Byte count)
    {
        ResetFencesCore(ppFences, count);
    }
    void GraphicsDevice::WaitFences(Fence** ppFences, const Byte count)
    {
        WaitFencesCore(ppFences, count);
    }
    void GraphicsDevice::WaitDeviceIdle()
    {
        WaitDeviceIdleCore();
    }
    void GraphicsDevice::UpdateHostBuffer(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc)
    {
        UpdateHostBufferCore(pBuffer, desc);
    }
    void GraphicsDevice::UpdateDescriptorSet(DescriptorSet* pTable, const DescriptorSetUpdateDesc& desc)
    {
        UpdateDescriptorSetCore(pTable, desc);
    }
    void GraphicsDevice::SubmitCommandLists(CommandList** ppCmdLists, const unsigned char cmdListCount,
        const GraphicsQueue* pTargetQueue,
        Semaphore** ppSignalSemaphores, const unsigned int signalSemaphoreCount,
        Semaphore** ppWaitSemaphores, const PipelineStageFlags* pWaitStageFlags, const unsigned int waitSemaphoreCount,
        const Fence* pSignalFence)
    {
        SubmitCommandListsCore(ppCmdLists, cmdListCount, pTargetQueue, ppSignalSemaphores, signalSemaphoreCount, ppWaitSemaphores, pWaitStageFlags, waitSemaphoreCount, pSignalFence);
    }
    void GraphicsDevice::RegisterChild(const SharedHeap<GraphicsDeviceObject>& pObject)
    {
        pObject->_SetOwnerDevice(this);
        mChilds.Add(pObject);
    }
    void GraphicsDevice::RemoveChild(const SharedHeap<GraphicsDeviceObject>& pObject)
    {
        mChilds.Remove(pObject);
    }
    void GraphicsDevice::OnShutdown()
    {
        //Unregister
        GraphicsAPI::_RemoveDevice();

        //Delete all device objects
    }
}
