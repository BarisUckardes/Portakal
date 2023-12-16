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

            bool OwnQueue(VkQueue& queueOut)
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

            bool HasFreeQueue() const noexcept
            {
                return FreeQueues.GetSize() > 0;
            }

            void ReturnQueue(VkQueue queue)
            {
                FreeQueues.Add(queue);
            }

            byte FamilyIndex;
            byte QueueCapacity;
            VkQueue DefaultQueue;
            Array<VkQueue> Queues;
            Array<VkQueue> FreeQueues;
            VkBool32 CanPresent;
        };
	public:
		VulkanDevice(const VulkanAdapter* pAdapter);
		~VulkanDevice() = default;
	private:
		// Inherited via GraphicsDevice
		void OnShutdown() override;
		GraphicsBackend GetBackend() const noexcept override { return GraphicsBackend::Vulkan; }
		Texture* CreateTextureCore(const TextureDesc& desc) override;
		TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		Framebuffer* CreateFramebufferCore(const FramebufferDesc& desc) override;
		CommandList* CreateCommandListCore(const CommandListDesc& desc) override;
		Pipeline* CreatePipelineCore(const PipelineDesc& desc) override;
		GraphicsMemoryHeap* CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc) override;
		GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override;
		Shader* CreateShaderCore(const ShaderDesc& desc) override;
		Sampler* CreateSamplerCore(const SamplerDesc& desc) override;
		ResourceTableLayout* CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc) override;
		ResourceTablePool* CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc) override;
		ResourceTable* CreateResourceTableCore(const ResourceTableDesc& desc) override;
	private:
        DeviceQueueFamily mGraphicsQueueFamily;
        DeviceQueueFamily mComputeQueueFamily;
        DeviceQueueFamily mTransferQueueFamily;
        DeviceQueueFamily mPresentQueueFamily;
        VkDevice mLogicalDevice;
	};
}
