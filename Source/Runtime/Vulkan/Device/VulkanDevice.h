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
            DeviceQueueFamily() : FamilyIndex(255), QueueCapacity(0), DefaultQueue(VK_NULL_HANDLE), CanPresent(false)
            {

            }

            Bool8 OwnQueue(VkQueue& queueOut)
            {
                if (FreeQueues.GetSize() == 0)
                {
                    queueOut = VK_NULL_HANDLE;
                    return false;
                }

                queueOut = FreeQueues[0];
                FreeQueues.RemoveAt(0);
                return true;
            }

            Bool8 HasFreeQueue() const noexcept
            {
                return FreeQueues.GetSize() > 0;
            }

            void ReturnQueue(VkQueue queue)
            {
                FreeQueues.Add(queue);
            }

            Byte FamilyIndex;
            Byte QueueCapacity;
            VkQueue DefaultQueue;
            Array<VkQueue> Queues;
            Array<VkQueue> FreeQueues;
            VkBool32 CanPresent;
        };
    public:
        static PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
        static PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
	public:
		VulkanDevice(const GraphicsDeviceDesc& desc);
        ~VulkanDevice()
        {

        }

        FORCEINLINE Int32 GetPresentQueueFamilyIndex(const VkSurfaceKHR surface) const noexcept;
        FORCEINLINE VkQueue GetPresentQueue(const VkSurfaceKHR surface) const noexcept;
        FORCEINLINE Int32 GetGraphicsQueueFamilyIndex()
        {
            return mGraphicsQueueFamily.FamilyIndex;
        }
        FORCEINLINE Int32 GetComputeQueueFamilyIndex()
        {
            return mComputeQueueFamily.FamilyIndex;
        }
        FORCEINLINE Int32 GetTransfersQueueFamilyIndex()
        {
            return mTransferQueueFamily.FamilyIndex;
        }
        FORCEINLINE VkDevice GetVkLogicalDevice() const noexcept { return mLogicalDevice; }

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
        Fence* CreateFenceCore() override;
        Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
        RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override;

        // Inherited via GraphicsDevice
        CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
        Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override;
        SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) override;
        void WaitFencesCore(Fence** ppFences, const Byte count) override;
        void WaitDeviceIdleCore() override;
        void WaitQueueDefaultCore(const GraphicsQueueType type) override;
        void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) override;
        void UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc) override;
        void SubmitCommandListsCore(CommandList** ppCmdLists, const Byte cmdListCount, const GraphicsQueueType type, const Fence* pFence) override;
	private:
        DeviceQueueFamily mGraphicsQueueFamily;
        DeviceQueueFamily mComputeQueueFamily;
        DeviceQueueFamily mTransferQueueFamily;
        VkDevice mLogicalDevice;
        VkPhysicalDevice mPhysicalDevice;
    };
}
