#include "VulkanDevice.h"
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Fence/VulkanFence.h>
#include <Runtime/Vulkan/Buffer/VulkanBuffer.h>
#include <Runtime/Vulkan/Command/VulkanCommandPool.h>
#include <Runtime/Vulkan/Command/VulkanCommandList.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryHeap.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipeline.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPass.h>
#include <Runtime/Vulkan/Resource/VulkanResourceTable.h>
#include <Runtime/Vulkan/Resource/VulkanResourceTableLayout.h>
#include <Runtime/Vulkan/Resource/VulkanResourcePool.h>
#include <Runtime/Vulkan/Sampler/VulkanSampler.h>
#include <Runtime/Vulkan/Shader/VulkanShader.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Texture/VulkanTextureView.h>
#include <Runtime/Vulkan/Resource/VulkanResourceUtils.h>
#include <string>
#include <Runtime/Vulkan/Queue/VulkanQueue.h>
#include <Runtime/Vulkan/Semaphore/VulkanSemaphore.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>

namespace Portakal
{
	VulkanDevice::VulkanDevice(const GraphicsDeviceDesc* pDesc) : GraphicsDevice(pDesc), mPhysicalDevice(((const VulkanAdapter*)pDesc->pAdapter)->GetVkPhysicalDevice())
	{
		//Get queue families
		UInt32 queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, nullptr);
		DEV_ASSERT(queueFamilyCount > 0, "VulkanDevice", "No queue families found!");

		Array<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, queueFamilyProperties.GetData());

		//Collect queue families
		for (UInt32 i = 0; i < queueFamilyCount; i++)
		{
			const VkQueueFamilyProperties& properties = queueFamilyProperties[i];
			if (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT && mGraphicsQueueFamily.FamilyIndex == 255)
			{
				mGraphicsQueueFamily.Capacity = properties.queueCount;
				mGraphicsQueueFamily.RequestedCount = pDesc->GraphicsQueueCount > properties.queueCount ? properties.queueCount : pDesc->GraphicsQueueCount;
				mGraphicsQueueFamily.FamilyIndex = i;
			}
			else if (properties.queueFlags & VK_QUEUE_COMPUTE_BIT && mComputeQueueFamily.FamilyIndex == 255)
			{
				mComputeQueueFamily.Capacity = properties.queueCount;
				mComputeQueueFamily.RequestedCount = pDesc->ComputeQueueCount > properties.queueCount ? properties.queueCount : pDesc->ComputeQueueCount;
				mComputeQueueFamily.FamilyIndex = i;
			}
			else if (properties.queueFlags & VK_QUEUE_TRANSFER_BIT && mTransferQueueFamily.FamilyIndex == 255)
			{
				mTransferQueueFamily.Capacity = properties.queueCount;
				mTransferQueueFamily.RequestedCount = pDesc->TransferQueueCount > properties.queueCount ? properties.queueCount : pDesc->TransferQueueCount;
				mTransferQueueFamily.FamilyIndex = i;
			}
		}

		//Get queues
		constexpr float queuePriorities[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		Array<VkDeviceQueueCreateInfo> queueCreateInformations;
		{
			VkDeviceQueueCreateInfo graphicsQueueCreateInfo = {};
			graphicsQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			graphicsQueueCreateInfo.queueFamilyIndex = mGraphicsQueueFamily.FamilyIndex;
			graphicsQueueCreateInfo.queueCount = mGraphicsQueueFamily.RequestedCount;
			graphicsQueueCreateInfo.pQueuePriorities = queuePriorities;
			graphicsQueueCreateInfo.pNext = nullptr;

			VkDeviceQueueCreateInfo computeQueueCreateInfo = {};
			computeQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			computeQueueCreateInfo.queueFamilyIndex = mComputeQueueFamily.FamilyIndex;
			computeQueueCreateInfo.queueCount = mComputeQueueFamily.RequestedCount;
			computeQueueCreateInfo.pQueuePriorities = queuePriorities;
			computeQueueCreateInfo.pNext = nullptr;

			VkDeviceQueueCreateInfo transferQueueCreateInfo = {};
			transferQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			transferQueueCreateInfo.queueFamilyIndex = mTransferQueueFamily.FamilyIndex;
			transferQueueCreateInfo.queueCount = mTransferQueueFamily.RequestedCount;
			transferQueueCreateInfo.pQueuePriorities = queuePriorities;
			transferQueueCreateInfo.pNext = nullptr;

			if (mGraphicsQueueFamily.RequestedCount > 0)
				queueCreateInformations.Add(graphicsQueueCreateInfo);
			if (mComputeQueueFamily.RequestedCount > 0)
				queueCreateInformations.Add(computeQueueCreateInfo);
			if (mTransferQueueFamily.RequestedCount > 0)
				queueCreateInformations.Add(transferQueueCreateInfo);
		}

		//Get logical device extensions
		Array<const Char*> logicalDeviceExtensions;
		logicalDeviceExtensions.Add(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
		logicalDeviceExtensions.Add(VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME);
		logicalDeviceExtensions.Add(VK_KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME);
		logicalDeviceExtensions.Add(VK_KHR_CREATE_RENDERPASS_2_EXTENSION_NAME);
		logicalDeviceExtensions.Add(VK_KHR_MULTIVIEW_EXTENSION_NAME);
		logicalDeviceExtensions.Add(VK_KHR_MAINTENANCE2_EXTENSION_NAME);

		//Create logical device
		VkDeviceCreateInfo logicalDeviceInfo = {};
		logicalDeviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		logicalDeviceInfo.pNext = nullptr;
		logicalDeviceInfo.queueCreateInfoCount = queueCreateInformations.GetSize();
		logicalDeviceInfo.pQueueCreateInfos = queueCreateInformations.GetData();
		logicalDeviceInfo.enabledExtensionCount = logicalDeviceExtensions.GetSize();
		logicalDeviceInfo.ppEnabledExtensionNames = logicalDeviceExtensions.GetData();
		logicalDeviceInfo.enabledLayerCount = 0;
		logicalDeviceInfo.ppEnabledLayerNames = nullptr;

		DEV_ASSERT(vkCreateDevice(mPhysicalDevice, &logicalDeviceInfo, nullptr, &mLogicalDevice) == VK_SUCCESS, "VulkanDevice", "Failed to create logical device!");

		//Get queues
		for (unsigned int i = 0; i < mGraphicsQueueFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mGraphicsQueueFamily.FamilyIndex, i, &queue);
			mGraphicsQueueFamily.FreeQueues.Add(queue);
		}

		for (unsigned int i = 0; i < mComputeQueueFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mComputeQueueFamily.FamilyIndex, i, &queue);
			mComputeQueueFamily.FreeQueues.Add(queue);
		}

		for (unsigned int i = 0; i < mTransferQueueFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mTransferQueueFamily.FamilyIndex, i, &queue);
			mTransferQueueFamily.FreeQueues.Add(queue);
		}

		DEV_LOG("VulkanDevice", "Initialized");
	}
	
	VkQueue VulkanDevice::vkOwnQueue(const GraphicsQueueType type)
	{
		switch (type)
		{
			default:
			case Portakal::GraphicsQueueType::Graphics:
				return mGraphicsQueueFamily.OwnQueue();
			case Portakal::GraphicsQueueType::Compute:
				return mComputeQueueFamily.OwnQueue();
			case Portakal::GraphicsQueueType::Transfer:
				return mTransferQueueFamily.OwnQueue();
		}
	}

	void VulkanDevice::vkReturnQueue(const GraphicsQueueType type, const VkQueue queue)
	{
		switch (type)
		{
			default:
			case Portakal::GraphicsQueueType::Graphics:
			{
				mGraphicsQueueFamily.ReturnQueue(queue);
				break;
			}
			case Portakal::GraphicsQueueType::Compute:
			{
				mComputeQueueFamily.ReturnQueue(queue);
				break;
			}
			case Portakal::GraphicsQueueType::Transfer:
			{
				mTransferQueueFamily.ReturnQueue(queue);
				break;
			}
		}
	}

	unsigned char VulkanDevice::vkGetQueueFamilyIndex(const GraphicsQueueType type) const noexcept
	{
		switch (type)
		{
			case Portakal::GraphicsQueueType::Graphics:
				return mGraphicsQueueFamily.FamilyIndex;
			case Portakal::GraphicsQueueType::Compute:
				return mComputeQueueFamily.FamilyIndex;
			case Portakal::GraphicsQueueType::Transfer:
				return mTransferQueueFamily.FamilyIndex;
			default:
				return 255;
		}
	}

	SharedHeap<Texture> VulkanDevice::CreateVkSwapchainTexture(const TextureDesc& desc, const VkImage image)
	{
		SharedHeap<Texture> pTexture = new VulkanTexture(desc, image, this);
		RegisterChild(pTexture.QueryAs<GraphicsDeviceObject>());
		return pTexture;
	}
	void VulkanDevice::OnShutdown()
	{
		vkDestroyDevice(mLogicalDevice, nullptr);
		DEV_LOG("VulkanDevice", "Shutdown");
	}
	Texture* VulkanDevice::CreateTextureCore(const TextureDesc& desc)
	{
		return new VulkanTexture(desc, this);
	}
	TextureView* VulkanDevice::CreateTextureViewCore(const TextureViewDesc& desc)
	{
		return new VulkanTextureView(desc, this);
	}

	CommandList* VulkanDevice::CreateCommandListCore(const CommandListDesc& desc)
	{
		return new VulkanCommandList(desc, this);
	}

	GraphicsMemoryHeap* VulkanDevice::CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc)
	{
		return new VulkanMemoryHeap(desc, this);
	}
	GraphicsBuffer* VulkanDevice::CreateBufferCore(const GraphicsBufferDesc& desc)
	{
		return new VulkanBuffer(desc, this);
	}
	Shader* VulkanDevice::CreateShaderCore(const ShaderDesc& desc)
	{
		return new VulkanShader(desc, this);
	}
	Sampler* VulkanDevice::CreateSamplerCore(const SamplerDesc& desc)
	{
		return new VulkanSampler(desc, this);
	}
	ResourceTableLayout* VulkanDevice::CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc)
	{
		return new VulkanResourceTableLayout(desc, this);
	}
	ResourceTablePool* VulkanDevice::CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc)
	{
		return new VulkanResourcePool(desc, this);
	}
	ResourceTable* VulkanDevice::CreateResourceTableCore(const ResourceTableDesc& desc)
	{
		return new VulkanResourceTable(desc, this);
	}
	Fence* VulkanDevice::CreateFenceCore(const bool bSignalled)
	{
		return new VulkanFence(this, bSignalled);
	}
	Swapchain* VulkanDevice::CreateSwapchainCore(const SwapchainDesc& desc)
	{
		return new VulkanSwapchain(desc, this);
	}
	RenderPass* VulkanDevice::CreateRenderPassCore(const RenderPassDesc& desc)
	{
		return new VulkanRenderPass(desc, this);
	}
	GraphicsQueue* VulkanDevice::OwnQueueCore(const GraphicsQueueDesc& desc)
	{
		return new VulkanQueue(desc, this);
	}
	CommandPool* VulkanDevice::CreateCommandPoolCore(const CommandPoolDesc& desc)
	{
		return new VulkanCommandPool(desc, this);
	}
	Pipeline* VulkanDevice::CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc)
	{
		return new VulkanPipeline(desc, this);
	}
	SharedHeap<Pipeline> VulkanDevice::CreateComputePipelineCore(const ComputePipelineDesc& desc)
	{
		return new VulkanPipeline(desc, this);
	}
	void VulkanDevice::ResetFencesCore(Fence** ppFences, const Byte count)
	{
		VkFence vkFences[128];
		for (UInt32 fenceIndex = 0; fenceIndex < count; fenceIndex++)
		{
			const VulkanFence* pVkFence = (const VulkanFence*)ppFences[fenceIndex];

			vkFences[fenceIndex] = pVkFence->GetVkFence();
		}

		DEV_ASSERT(vkResetFences(mLogicalDevice, count, vkFences) == VK_SUCCESS, "VulkanGraphicsDevice", "Failed to reset the given fences");
	}
	void VulkanDevice::WaitFencesCore(Fence** ppFences, const Byte count)
	{
		VkFence vkFences[128];
		for (UInt32 fenceIndex = 0; fenceIndex < count; fenceIndex++)
		{
			const VulkanFence* pVkFence = (const VulkanFence*)ppFences[fenceIndex];

			vkFences[fenceIndex] = pVkFence->GetVkFence();
		}

		DEV_ASSERT(vkWaitForFences(mLogicalDevice, count, vkFences, VK_TRUE, UINT64_MAX) == VK_SUCCESS, "VulkanGraphicsDevice", "Failed to wait fences[%d]", count);
		//DEV_ASSERT(vkResetFences(mLogicalDevice, count, vkFences) == VK_SUCCESS, "VulkanGraphicsDevice", "Failed to reset fences[%hhu]", count);
	}
	void VulkanDevice::WaitDeviceIdleCore()
	{
		vkDeviceWaitIdle(mLogicalDevice);
	}
	
	void VulkanDevice::UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc)
	{
		const VulkanMemoryHeap* pHeap = (const VulkanMemoryHeap*)pBuffer->GetMemory().GetHeap();
		const VulkanBuffer* pVkBuffer = (const VulkanBuffer*)pBuffer;

		Byte* pTargetHostData = nullptr;
		DEV_ASSERT(vkMapMemory(mLogicalDevice, pHeap->GetVkMemory(), pVkBuffer->GetVkMemoryAlignedOffset() + desc.OffsetInBytes, desc.View.GetSize(), 0, (void**)&pTargetHostData) == VK_SUCCESS, "VulkanDevice", "Failed to map the host buffer");
		Memory::Copy(pTargetHostData, (void*)desc.View.GetMemory(), desc.View.GetSize());
		vkUnmapMemory(mLogicalDevice, pHeap->GetVkMemory());
	}
	void VulkanDevice::UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc)
	{
		Array<VkWriteDescriptorSet> writeInformation(desc.Entries.GetSize());
		Array<VkDescriptorBufferInfo> writeBufferInformation(desc.Entries.GetSize());
		Array<VkDescriptorImageInfo> writeImageInformation(desc.Entries.GetSize());

		const VulkanResourceTable* pVkSet = (const VulkanResourceTable*)pTable;

		for (Byte entryIndex = 0; entryIndex < desc.Entries.GetSize(); entryIndex++)
		{
			const ResourceTableUpdateEntry& entry = desc.Entries[entryIndex];

			VkWriteDescriptorSet writeInfo = {};
			writeInfo.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			writeInfo.pNext = nullptr;
			writeInfo.pBufferInfo = nullptr;
			writeInfo.pImageInfo = nullptr;
			writeInfo.descriptorType = VulkanResourceUtils::GetDescriptorType(entry.Type);
			writeInfo.descriptorCount = 1;
			writeInfo.dstArrayElement = entry.ArrayElement;
			writeInfo.dstBinding = entry.Binding;
			writeInfo.dstSet = pVkSet->GetVkDescriptorSet();

			switch (entry.Type)
			{
			case GraphicsResourceType::Sampler:
			{
				const VulkanSampler* pSampler = (const VulkanSampler*)entry.pResource.GetHeap();

				VkDescriptorImageInfo samplerImageInfo = {};
				samplerImageInfo.imageView = VK_NULL_HANDLE;
				samplerImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
				samplerImageInfo.sampler = pSampler->GetVkSampler();
				writeImageInformation[entryIndex] = samplerImageInfo;
				writeInfo.pImageInfo = &samplerImageInfo;
				writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
				break;
			}
			case GraphicsResourceType::SampledTexture:
			{
				const VulkanTextureView* Texture = (const VulkanTextureView*)entry.pResource.GetHeap();

				VkDescriptorImageInfo samplerImageInfo = {};
				samplerImageInfo.imageView = Texture->GetVkImageView();
				samplerImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
				samplerImageInfo.sampler = VK_NULL_HANDLE;
				writeImageInformation[entryIndex] = samplerImageInfo;
				writeInfo.pImageInfo = &samplerImageInfo;
				writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
				break;
			}
			case GraphicsResourceType::StorageTexture:
			{
				const VulkanTextureView* Texture = (const VulkanTextureView*)entry.pResource.GetHeap();

				VkDescriptorImageInfo samplerImageInfo = {};
				samplerImageInfo.imageView = Texture->GetVkImageView();
				samplerImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
				samplerImageInfo.sampler = VK_NULL_HANDLE;
				writeImageInformation[entryIndex] = samplerImageInfo;
				writeInfo.pImageInfo = &samplerImageInfo;
				writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
				break;
			}
			case GraphicsResourceType::ConstantBuffer:
			{
				const VulkanBuffer* pBuffer = (const VulkanBuffer*)entry.pResource.GetHeap();

				VkDescriptorBufferInfo bufferInfo = {};
				bufferInfo.buffer = pBuffer->GetVkBuffer();
				bufferInfo.offset = entry.BufferOffsetInBytes;
				bufferInfo.range = pBuffer->GetTotalSize();
				writeBufferInformation[entryIndex] = bufferInfo;
				writeInfo.pBufferInfo = &bufferInfo;
				writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
				break;
			}
			case GraphicsResourceType::StorageBuffer:
			{
				const VulkanBuffer* pBuffer = (const VulkanBuffer*)entry.pResource.GetHeap();

				VkDescriptorBufferInfo bufferInfo = {};
				bufferInfo.buffer = pBuffer->GetVkBuffer();
				bufferInfo.offset = entry.BufferOffsetInBytes;
				bufferInfo.range = pBuffer->GetTotalSize();
				writeBufferInformation[entryIndex] = bufferInfo;
				writeInfo.pBufferInfo = &bufferInfo;
				writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
				break;
			}
			}

			writeInformation[entryIndex] = writeInfo;
		}

		vkUpdateDescriptorSets(mLogicalDevice, desc.Entries.GetSize(), writeInformation.GetDataConst(), 0, nullptr);
	}
	void VulkanDevice::SubmitCommandListsCore(CommandList** ppCmdLists, const unsigned char cmdListCount,
		const GraphicsQueue* pTargetQueue,
		Semaphore** ppSignalSemaphores, const unsigned int signalSemaphoreCount,
		Semaphore** ppWaitSemaphores, const PipelineStageFlags* pWaitStageFlags, const unsigned int waitSemaphoreCount,
		const Fence* pSignalFence)
	{
		const VulkanFence* pVkFence = (const VulkanFence*)pSignalFence;
		const VulkanQueue* pVkQueue = (const VulkanQueue*)pTargetQueue;

		//Get cmd buffers
		VkCommandBuffer vkCmdBuffers[32];
		for (unsigned int cmdListIndex = 0; cmdListIndex < cmdListCount; cmdListIndex++)
		{
			const VulkanCommandList* pCmdList = (const VulkanCommandList*)ppCmdLists[cmdListIndex];
			vkCmdBuffers[cmdListIndex] = pCmdList->GetVkCommandBuffer();
		}

		//Get wait semaphores
		VkSemaphore vkSignalSemahpores[32];
		for (unsigned int i = 0; i < signalSemaphoreCount; i++)
		{
			const VulkanSemaphore* pSemaphore = (const VulkanSemaphore*)ppSignalSemaphores[i];
			vkSignalSemahpores[i] = pSemaphore->GetVkSemaphore();
		}

		//Get wait semaphores
		VkSemaphore vkWaitSemahpores[32];
		for (unsigned int i = 0; i < waitSemaphoreCount; i++)
		{
			const VulkanSemaphore* pSemaphore = (const VulkanSemaphore*)ppWaitSemaphores[i];
			vkWaitSemahpores[i] = pSemaphore->GetVkSemaphore();
		}

		//Get wait semaphore stage flags
		VkPipelineStageFlags vkStageWaitFlags[32];
		for (unsigned int i = 0; i < waitSemaphoreCount; i++)
		{
			vkStageWaitFlags[i] = VulkanPipelineUtils::GetStageFlags(pWaitStageFlags[i]);
		}

		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.pNext = nullptr;

		submitInfo.waitSemaphoreCount = waitSemaphoreCount;
		submitInfo.pWaitSemaphores = vkWaitSemahpores;
		submitInfo.pWaitDstStageMask = vkStageWaitFlags;

		submitInfo.signalSemaphoreCount = signalSemaphoreCount;
		submitInfo.pSignalSemaphores = vkSignalSemahpores;

		submitInfo.commandBufferCount = cmdListCount;
		submitInfo.pCommandBuffers = vkCmdBuffers;

		DEV_ASSERT(vkQueueSubmit(pVkQueue->GetVkQueue(), cmdListCount, &submitInfo, pVkFence != nullptr ? pVkFence->GetVkFence() : VK_NULL_HANDLE) == VK_SUCCESS, "VulkanDevice", "Failed to submit the command lists");
	}
}
