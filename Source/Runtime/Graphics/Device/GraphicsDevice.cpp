#include "GraphicsDevice.h"

namespace Portakal
{
    GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : mOwnerAdapter(desc.pAdapter)
    {
    }
  
    SharedHeap<Texture> GraphicsDevice::CreateTexture(const TextureDesc& desc)
    {
        return SharedHeap<Texture>();
    }
    SharedHeap<TextureView> GraphicsDevice::CreateTextureView(const TextureViewDesc& desc)
    {
        return SharedHeap<TextureView>();
    }
    SharedHeap<Framebuffer> GraphicsDevice::CreateFramebuffer(const FramebufferDesc& desc)
    {
        return SharedHeap<Framebuffer>();
    }
    SharedHeap<CommandList> GraphicsDevice::CreateCommandList(const CommandListDesc& desc)
    {
        return SharedHeap<CommandList>();
    }
    SharedHeap<CommandPool> GraphicsDevice::CreateCommandPool(const CommandPoolDesc& desc)
    {
        return SharedHeap<CommandPool>();
    }
    SharedHeap<Pipeline> GraphicsDevice::CreatePipeline(const PipelineDesc& desc)
    {
        return SharedHeap<Pipeline>();
    }
    SharedHeap<GraphicsMemoryHeap> GraphicsDevice::CreateMemoryHeap(const GraphicsMemoryHeapDesc& desc)
    {
        return SharedHeap<GraphicsMemoryHeap>();
    }
    SharedHeap<GraphicsBuffer> GraphicsDevice::CreateBuffer(const GraphicsBufferDesc& desc)
    {
        return SharedHeap<GraphicsBuffer>();
    }
    SharedHeap<Shader> GraphicsDevice::CreateShader(const ShaderDesc& desc)
    {
        return SharedHeap<Shader>();
    }
    SharedHeap<Sampler> GraphicsDevice::CreateSampler(const SamplerDesc& desc)
    {
        return SharedHeap<Sampler>();
    }
    SharedHeap<ResourceTableLayout> GraphicsDevice::CreateResourceTableLayout(const ResourceTableLayoutDesc& desc)
    {
        return SharedHeap<ResourceTableLayout>();
    }
    SharedHeap<ResourceTablePool> GraphicsDevice::CreateResourceTablePooLDesc(const ResourceTablePoolDesc& desc)
    {
        return SharedHeap<ResourceTablePool>();
    }
    SharedHeap<ResourceTable> GraphicsDevice::CreateResourceTable(const ResourceTableDesc& desc)
    {
        return SharedHeap<ResourceTable>();
    }
    SharedHeap<GraphicsQueue> GraphicsDevice::CreateQueue(const GraphicsQueueDesc& desc)
    {
        return SharedHeap<GraphicsQueue>();
    }
    SharedHeap<Fence> GraphicsDevice::CreateFence()
    {
        //Create fence
        SharedHeap<Fence> pFence = CreateFenceCore();

        //Register
        RegisterChild(pFence.QueryAs<GraphicsDeviceObject>());

        return pFence;
    }
    SharedHeap<Swapchain> GraphicsDevice::CreateSwapchain(const SwapchainDesc& desc)
    {
        //Create swapchain
        SharedHeap<Swapchain> pSwapchain = CreateSwapchainCore(desc);

        //Register
        RegisterChild(pSwapchain.QueryAs<GraphicsDeviceObject>());

        //Set as main if no swapchain is available
        if (mMainSwapchain.IsShutdown())
            mMainSwapchain = pSwapchain;

        return pSwapchain;
    }
    void GraphicsDevice::WaitFences(Fence* ppFences, const byte count)
    {
    }
    void GraphicsDevice::WaitQueueIdle(GraphicsQueue* pQueue)
    {
    }
    void GraphicsDevice::WaitDeviceIdle()
    {
    }
    void GraphicsDevice::WaitQueueDefault(const GraphicsQueueType type)
    {
    }
    void GraphicsDevice::UpdateHostBuffer(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc)
    {
    }
    void GraphicsDevice::UpdateResourceTable(ResourceTable* pTable, const ResourceTableUpdateDesc& desc)
    {
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
}
