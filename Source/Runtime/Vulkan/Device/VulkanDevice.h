#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Vulkan/Device/VulkanDeviceDesc.h>
#include <vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanDevice : public GraphicsDevice
	{
        struct DeviceQueueFamily
        {
            DeviceQueueFamily() : FamilyIndex(255), Capacity(0),RequestedCount(0)
            {

            }

			VkQueue OwnQueue()
			{
				if (FreeQueues.size() == 0)
					return VK_NULL_HANDLE;

				VkQueue queue = FreeQueues[0];
				FreeQueues.erase(FreeQueues.begin());
				return queue;
			}

			void ReturnQueue(VkQueue queue)
			{
				FreeQueues.push_back(queue);
			}

            Byte FamilyIndex;
            Byte Capacity;
			Byte RequestedCount;
            std::vector<VkQueue> FreeQueues;
        };
	public:
		VulkanDevice(const VulkanDeviceDesc* pDesc);
		~VulkanDevice();

		FORCEINLINE VkDevice GetVkLogicalDevice() const noexcept
		{
			return mLogicalDevice;
		}
		VkQueue vkOwnQueue(const GraphicsQueueType type);
		void vkReturnQueue(const GraphicsQueueType type,const VkQueue queue);
		Byte vkGetQueueFamilyIndex(const GraphicsQueueType type) const noexcept;
		Texture* vkCreateSwapchainTexture(const TextureDesc& desc,const VkImage image);
		TextureView* vkCreateSwapchainTextureView(const TextureViewDesc& desc, const VkImageView view);
	private:
		virtual GraphicsBackend GetBackend() const noexcept
		{
			return GraphicsBackend::Vulkan;
		}

		virtual bool HasQueue(const GraphicsQueueType type) const noexcept override;
		virtual GraphicsQueue* CreateQueueCore(const GraphicsQueueDesc& desc) override;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override;
		virtual DescriptorSet* CreateDescriptorSetCore(const DescriptorSetDesc& desc) override;
		virtual DescriptorPool* CreateDescriptorPoolCore(const DescriptorPoolDesc& desc) override;
		virtual DescriptorSetLayout* CreateDescriptorSetLayoutCore(const DescriptorSetLayoutDesc& desc) override;
		virtual Fence* CreateFenceCore(const FenceDesc& desc) override;
		virtual Semaphore* CreateSyncObjectCore(const SemaphoreDesc& desc) override;
		virtual GraphicsMemory* AllocateMemoryCore(const GraphicsMemoryDesc& desc) override;
		virtual Sampler* CreateSamplerCore(const SamplerDesc& desc) override;
		virtual Shader* CreateShaderCore(const ShaderDesc& desc) override;
		virtual Texture* CreateTextureCore(const TextureDesc& desc) override;
		virtual TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		virtual Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
		virtual Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override;
		virtual Pipeline* CreateComputePipelineCore(const ComputePipelineDesc& desc) override;
		virtual RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override;
		virtual CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
		virtual CommandList* CreateCommandListCore(const CommandListDesc& desc) override;

		virtual void UpdateDescriptorSetCore(DescriptorSet* pSet, const DescriptorSetUpdateDesc& desc) override;
		virtual void CopyDescriptorSetCore(DescriptorSet* pSourceSet, DescriptorSet* pDestinationSet, const DescriptorSetCopyDesc& desc) override;
		virtual void UpdateHostBufferCore(GraphicsBuffer* pTargetBuffer, const HostBufferUpdateDesc& desc) override;
		virtual void SubmitCommandsCore(CommandList** ppCmdLists, const Byte cmdListCount, const GraphicsQueue* pTargetQueue, Semaphore** ppSignalSemaphores, const UInt32 signalSemaphoreCount, Semaphore** ppWaitSemaphores,const  PipelineStageFlags* pWaitStageFlags, const UInt32 waitSemaphoreCount, const Fence* pSignalFence) override;
		virtual void ResetFencesCore(Fence** ppFences, const UInt32 count) override;
		virtual void WaitFencesCore(Fence** ppFences, const UInt32 count) override;
		virtual void WaitDeviceIdleCore() override;
		virtual void WaitQueueIdleCore(GraphicsQueue* pQueue) override;
	private:
		VkDevice mLogicalDevice;
        DeviceQueueFamily mGraphicsFamily;
        DeviceQueueFamily mComputeFamily;
        DeviceQueueFamily mTransferFamily;
	};
}
