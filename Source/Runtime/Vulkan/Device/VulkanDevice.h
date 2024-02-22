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
        VkQueue vkOwnQueue(const GraphicsQueueFamilyType type);
        void vkReturnQueue(const GraphicsQueueFamilyType type, const VkQueue queue);
        unsigned char vkGetQueueFamilyIndex(const GraphicsQueueFamilyType type) const noexcept;
        SharedHeap<Texture> CreateVkSwapchainTexture(const TextureDesc& desc, const VkImage image);

        virtual GraphicsBackend GetBackend() const noexcept override final
        {
            return GraphicsBackend::Vulkan;
        }
	private:
		// Inherited via GraphicsDevice
		void OnShutdown() override;
		Texture* CreateTextureCore(const TextureDesc& desc) override;
		TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		CommandList* CreateCommandListCore(const CommandListDesc& desc) override;
		GraphicsMemory* CreateMemoryHeapCore(const GraphicsMemoryDesc& desc) override;
		GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override;
		Shader* CreateShaderCore(const ShaderDesc& desc) override;
		Sampler* CreateSamplerCore(const SamplerDesc& desc) override;
		DescriptorSetLayout* CreateDescriptorSetLayoutCore(const DescriptorSetLayoutDesc& desc) override;
		DescriptorSetPool* CreateDescriptorSetPoolCore(const DescriptorSetPoolDesc& desc) override;
		DescriptorSet* CreateDescriptorSetCore(const DescriptorSetDesc& desc) override;
        Fence* CreateFenceCore(const bool bSignalled) override;
        Semaphore* CreateSyncObjectCore() override;
        Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
        RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override;
        GraphicsQueue* RentQueueCore(const GraphicsQueueDesc& desc) override;

        // Inherited via GraphicsDevice
        CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
        Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override;
        SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) override;

        virtual void ResetFencesCore(Fence** ppFences, const Byte count) override;
        void WaitFencesCore(Fence** ppFences, const Byte count) override;
        void WaitDeviceIdleCore() override;
        void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) override;
        void UpdateDescriptorSetCore(DescriptorSet* pTable, const DescriptorSetUpdateDesc& desc) override;
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
