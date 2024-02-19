#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanAdapter;
	class RUNTIME_API VulkanDevice final : public GraphicsDevice
	{
	private:
        struct DeviceQueueFamily
        {
            DeviceQueueFamily() : FamilyIndex(255), Capacity(0), RequestedCount(0)
            {

            }

            VkQueue OwnQueue()
            {
                if (FreeQueues.GetSize() == 0)
                    return VK_NULL_HANDLE;

                VkQueue queue = FreeQueues[0];
                FreeQueues.RemoveAt(0);
                return queue;
            }

            void ReturnQueue(VkQueue queue)
            {
                FreeQueues.Add(queue);
            }

            unsigned char FamilyIndex;
            unsigned char Capacity;
            unsigned char RequestedCount;
            Array<VkQueue> FreeQueues;
        };
	public:
		VulkanDevice(const GraphicsDeviceDesc* pDesc);
        ~VulkanDevice()
        {

        }

       
        FORCEINLINE VkDevice GetVkLogicalDevice() const noexcept { return mLogicalDevice; }
        VkQueue vkOwnQueue(const GraphicsQueueType type);
        void vkReturnQueue(const GraphicsQueueType type, const VkQueue queue);
        unsigned char vkGetQueueFamilyIndex(const GraphicsQueueType type) const noexcept;
        SharedHeap<Texture> CreateVkSwapchainTexture(const TextureDesc& desc, const VkImage image);
	private:
		// Inherited via GraphicsDevice
		void OnShutdown() override;
		Texture* CreateTextureCore(const TextureDesc& desc) override;
		TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		CommandList* CreateCommandListCore(const CommandListDesc& desc) override;
		GraphicsMemoryHeap* CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc) override;
		GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override;
		Shader* CreateShaderCore(const ShaderDesc& desc) override;
		Sampler* CreateSamplerCore(const SamplerDesc& desc) override;
		ResourceTableLayout* CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc) override;
		ResourceTablePool* CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc) override;
		ResourceTable* CreateResourceTableCore(const ResourceTableDesc& desc) override;
        Fence* CreateFenceCore(const bool bSignalled) override;
        Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
        RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override;
        GraphicsQueue* OwnQueueCore(const GraphicsQueueDesc& desc) override;

        // Inherited via GraphicsDevice
        CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
        Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override;
        SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) override;

        virtual void ResetFencesCore(Fence** ppFences, const Byte count) override;
        void WaitFencesCore(Fence** ppFences, const Byte count) override;
        void WaitDeviceIdleCore() override;
        void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) override;
        void UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc) override;
        void SubmitCommandListsCore(CommandList** ppCmdLists, const unsigned char cmdListCount,
            const GraphicsQueue* pTargetQueue,
            Semaphore** ppSignalSemaphores, const unsigned int signalSemaphoreCount,
            Semaphore** ppWaitSemaphores, const PipelineStageFlags* pWaitStageFlags, const unsigned int waitSemaphoreCount,
            const Fence* pSignalFence) override;
	private:
        DeviceQueueFamily mGraphicsQueueFamily;
        DeviceQueueFamily mComputeQueueFamily;
        DeviceQueueFamily mTransferQueueFamily;
        VkDevice mLogicalDevice;
        VkPhysicalDevice mPhysicalDevice;
    };
}
