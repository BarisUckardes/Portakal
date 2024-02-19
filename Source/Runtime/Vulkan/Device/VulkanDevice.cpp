#include "VulkanDevice.h"
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Device/VulkanDeviceFeatures.h>
#include <Runtime/Vulkan/Queue/VulkanQueue.h>
#include <Runtime/Vulkan/Buffer/VulkanBuffer.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorPool.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSetLayout.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSet.h>
#include <Runtime/Vulkan/Memory/VulkanMemory.h>
#include <Runtime/Vulkan/Fence/VulkanFence.h>
#include <Runtime/Vulkan/Sampler/VulkanSampler.h>
#include <Runtime/Vulkan/Shader/VulkanShader.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Texture/VulkanTextureView.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipeline.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPass.h>
#include <Runtime/Vulkan/Command/VulkanCommandPool.h>
#include <Runtime/Vulkan/Command/VulkanCommandList.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorUtils.h>
#include <Runtime/Vulkan/Semaphore/VulkanSemaphore.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>

namespace Portakal
{
	VulkanDevice::VulkanDevice(const VulkanDeviceDesc* pDesc) : GraphicsDevice(pDesc)
	{
		VulkanAdapter* pVkAdapter = (VulkanAdapter*)pDesc->pOwnerAdapter.GetHeap();

		//Get queue family count
		UInt32 familyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(pVkAdapter->GetVkPhysicalDevice(), &familyCount, nullptr);
		DEV_ASSERT(familyCount > 0, "VulkanDevice", "Family count should be higher than 0");

		//Get queue family properties
		std::vector<VkQueueFamilyProperties> families(familyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(pVkAdapter->GetVkPhysicalDevice(), &familyCount, families.data());

		//Get queue families
		for (UInt32 i = 0; i < familyCount; i++)
		{
			const VkQueueFamilyProperties& properties = families[i];

			if (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT && mGraphicsFamily.FamilyIndex == 255)
			{
				mGraphicsFamily.Capacity = properties.queueCount;
				mGraphicsFamily.RequestedCount = pDesc->GraphicsQueueCount > properties.queueCount ? properties.queueCount : pDesc->GraphicsQueueCount;
				mGraphicsFamily.FamilyIndex = i;
			}
			else if (properties.queueFlags & VK_QUEUE_COMPUTE_BIT && mComputeFamily.FamilyIndex == 255)
			{
				mComputeFamily.Capacity = properties.queueCount;
				mComputeFamily.RequestedCount = pDesc->ComputeQueueCount > properties.queueCount ? properties.queueCount : pDesc->ComputeQueueCount;
				mComputeFamily.FamilyIndex = i;
			}
			else if (properties.queueFlags & VK_QUEUE_TRANSFER_BIT && mTransferFamily.FamilyIndex == 255)
			{
				mTransferFamily.Capacity = properties.queueCount;
				mTransferFamily.RequestedCount = pDesc->TransferQueueCount > properties.queueCount ? properties.queueCount : pDesc->TransferQueueCount;
				mTransferFamily.FamilyIndex = i;
			}
		}
		
		//Get queue create informations
		constexpr Float32 queuePriorities[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
		std::vector<VkDeviceQueueCreateInfo> queueCreateInformations;
		{
			VkDeviceQueueCreateInfo graphicsQueueCreateInfo = {};
			graphicsQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			graphicsQueueCreateInfo.queueFamilyIndex = mGraphicsFamily.FamilyIndex;
			graphicsQueueCreateInfo.queueCount = mGraphicsFamily.RequestedCount;
			graphicsQueueCreateInfo.pQueuePriorities = queuePriorities;
			graphicsQueueCreateInfo.pNext = nullptr;

			VkDeviceQueueCreateInfo computeQueueCreateInfo = {};
			computeQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			computeQueueCreateInfo.queueFamilyIndex = mComputeFamily.FamilyIndex;
			computeQueueCreateInfo.queueCount = mComputeFamily.RequestedCount;
			computeQueueCreateInfo.pQueuePriorities = queuePriorities;
			computeQueueCreateInfo.pNext = nullptr;

			VkDeviceQueueCreateInfo transferQueueCreateInfo = {};
			transferQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			transferQueueCreateInfo.queueFamilyIndex = mTransferFamily.FamilyIndex;
			transferQueueCreateInfo.queueCount = mTransferFamily.RequestedCount;
			transferQueueCreateInfo.pQueuePriorities = queuePriorities;
			transferQueueCreateInfo.pNext = nullptr;

			if(mGraphicsFamily.RequestedCount > 0)
				queueCreateInformations.push_back(graphicsQueueCreateInfo);
			if(mComputeFamily.RequestedCount > 0)
				queueCreateInformations.push_back(computeQueueCreateInfo);
			if(mTransferFamily.RequestedCount > 0)
				queueCreateInformations.push_back(transferQueueCreateInfo);
		}

		//Make queue validations
		DEV_ASSERT(queueCreateInformations.size() > 0, "VulkanDevice", "No queue requested!");

		//Get logical device extensions
		Array<const char*> extensions;
		for (const String& extension : pDesc->Extensions)
			extensions.Add(*extension);

		//Get logical device layers
		Array<const char*> layers;
		for (const String& layer : pDesc->Layers)
			layers.Add(*layer);

		//Create logical device
		VkPhysicalDeviceFeatures* pFeatures = nullptr;
		if (pDesc->pRequestedFeatures != nullptr)
			pFeatures = &(((VulkanDeviceFeatures*)pDesc->pRequestedFeatures)->Features);

		VkDeviceCreateInfo deviceInfo = {};
		deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		deviceInfo.queueCreateInfoCount = queueCreateInformations.size();
		deviceInfo.pQueueCreateInfos = queueCreateInformations.data();
		deviceInfo.enabledExtensionCount = extensions.GetSize();
		deviceInfo.ppEnabledExtensionNames = extensions.GetData();
		deviceInfo.enabledLayerCount = layers.GetSize();
		deviceInfo.ppEnabledLayerNames = layers.GetData();
		deviceInfo.pEnabledFeatures = pFeatures;
		deviceInfo.flags = VkDeviceCreateFlags();
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT descriptorFeatures = {};
		descriptorFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		descriptorFeatures.mutableDescriptorType = true;
		descriptorFeatures.pNext = nullptr;
		deviceInfo.pNext = &descriptorFeatures;

		DEV_ASSERT(vkCreateDevice(pVkAdapter->GetVkPhysicalDevice(), &deviceInfo, nullptr, &mLogicalDevice) == VK_SUCCESS, "VulkanDevice", "Failed to create logical device");

		//Get queues
		mGraphicsFamily.FreeQueues.reserve(mGraphicsFamily.RequestedCount);
		for (UInt32 i = 0; i < mGraphicsFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mGraphicsFamily.FamilyIndex, i, &queue);
			mGraphicsFamily.FreeQueues.push_back(queue);
		}

		mComputeFamily.FreeQueues.reserve(mComputeFamily.RequestedCount);
		for (UInt32 i = 0; i < mComputeFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mComputeFamily.FamilyIndex, i, &queue);
			mComputeFamily.FreeQueues.push_back(queue);
		}

		mTransferFamily.FreeQueues.reserve(mTransferFamily.RequestedCount);
		for (UInt32 i = 0; i < mTransferFamily.RequestedCount; i++)
		{
			VkQueue queue = VK_NULL_HANDLE;
			vkGetDeviceQueue(mLogicalDevice, mTransferFamily.FamilyIndex, i, &queue);
			mTransferFamily.FreeQueues.push_back(queue);
		}
	}
	VulkanDevice::~VulkanDevice()
	{
		
	}
	VkQueue VulkanDevice::vkOwnQueue(const GraphicsQueueType type)
	{
		switch (type)
		{
			default:
			case Portakal::GraphicsQueueType::Graphics:
				return mGraphicsFamily.OwnQueue();
			case Portakal::GraphicsQueueType::Compute:
				return mComputeFamily.OwnQueue();
			case Portakal::GraphicsQueueType::Transfer:
				return mTransferFamily.OwnQueue();
		}
	}
	void VulkanDevice::vkReturnQueue(const GraphicsQueueType type, const VkQueue queue)
	{
		switch (type)
		{
			default:
			case Portakal::GraphicsQueueType::Graphics:
			{
				mGraphicsFamily.ReturnQueue(queue);
				break;
			}
			case Portakal::GraphicsQueueType::Compute:
			{
				mComputeFamily.ReturnQueue(queue);
				break;
			}
			case Portakal::GraphicsQueueType::Transfer:
			{
				mTransferFamily.ReturnQueue(queue);
				break;
			}
		}
	}
	Byte VulkanDevice::vkGetQueueFamilyIndex(const GraphicsQueueType type) const noexcept
	{
		switch (type)
		{
			case Portakal::GraphicsQueueType::Graphics:
				return mGraphicsFamily.FamilyIndex;
			case Portakal::GraphicsQueueType::Compute:
				return mComputeFamily.FamilyIndex;
			case Portakal::GraphicsQueueType::Transfer:
				return mTransferFamily.FamilyIndex;
			default:
				return 255;
		}
	}
	Texture* VulkanDevice::vkCreateSwapchainTexture(const TextureDesc& desc, const VkImage image)
	{
		Texture* pTexture = new VulkanTexture(desc, image, this);
		RegisterObject(pTexture);
		return pTexture;
	}
	TextureView* VulkanDevice::vkCreateSwapchainTextureView(const TextureViewDesc& desc, const VkImageView view)
	{
		TextureView* pView = new VulkanTextureView(desc, view, this);
		RegisterObject(pView);
		return pView;
	}
	bool VulkanDevice::HasQueue(const GraphicsQueueType type) const noexcept
	{
		switch (type)
		{
			case Portakal::GraphicsQueueType::Graphics:
				return mGraphicsFamily.FreeQueues.size() > 0;
			case Portakal::GraphicsQueueType::Compute:
				return mComputeFamily.FreeQueues.size() > 0;
			case Portakal::GraphicsQueueType::Transfer:
				return mTransferFamily.FreeQueues.size() > 0;
			default:
				return false;
		}
	}
	GraphicsQueue* VulkanDevice::CreateQueueCore(const GraphicsQueueDesc& desc)
	{
		const VkQueue queue = vkOwnQueue(desc.Type);
		const Byte familyIndex = vkGetQueueFamilyIndex(desc.Type);
		DEV_ASSERT(familyIndex != 255, "VulkanDevice", "Requested invalid queue family index!");

		return new VulkanQueue(desc,queue,familyIndex,this);
	}
	GraphicsBuffer* VulkanDevice::CreateBufferCore(const GraphicsBufferDesc& desc)
	{
		return new VulkanBuffer(desc,this);
	}
	DescriptorSet* VulkanDevice::CreateDescriptorSetCore(const DescriptorSetDesc& desc)
	{
		return new VulkanDescriptorSet(desc,this);
	}
	DescriptorPool* VulkanDevice::CreateDescriptorPoolCore(const DescriptorPoolDesc& desc)
	{
		return new VulkanDescriptorPool(desc,this);
	}
	DescriptorSetLayout* VulkanDevice::CreateDescriptorSetLayoutCore(const DescriptorSetLayoutDesc& desc)
	{
		return new VulkanDescriptorSetLayout(desc,this);
	}
	Fence* VulkanDevice::CreateFenceCore(const FenceDesc& desc)
	{
		return new VulkanFence(desc,this);
	}
	Semaphore* VulkanDevice::CreateSyncObjectCore(const SemaphoreDesc& desc)
	{
		return new VulkanSemaphore(desc,this);
	}
	GraphicsMemory* VulkanDevice::AllocateMemoryCore(const GraphicsMemoryDesc& desc)
	{
		return new VulkanMemory(desc,this);
	}
	Sampler* VulkanDevice::CreateSamplerCore(const SamplerDesc& desc)
	{
		return new VulkanSampler(desc,this);
	}
	Shader* VulkanDevice::CreateShaderCore(const ShaderDesc& desc)
	{
		return new VulkanShader(desc,this);
	}
	Texture* VulkanDevice::CreateTextureCore(const TextureDesc& desc)
	{
		return new VulkanTexture(desc,this);
	}
	TextureView* VulkanDevice::CreateTextureViewCore(const TextureViewDesc& desc)
	{
		return new VulkanTextureView(desc,this);
	}
	Swapchain* VulkanDevice::CreateSwapchainCore(const SwapchainDesc& desc)
	{
		return new VulkanSwapchain(desc,this);
	}
	void VulkanDevice::SubmitCommandsCore(CommandList** ppCmdLists, const Byte cmdListCount, const GraphicsQueue* pTargetQueue, Semaphore** ppSignalSemaphores, const UInt32 signalSemaphoreCount, Semaphore** ppWaitSemaphores,const PipelineStageFlags* pWaitStageFlags, const UInt32 waitSemaphoreCount, const Fence* pSignalFence)
	{
		const VulkanFence* pVkFence = (const VulkanFence*)pSignalFence;
		const VulkanQueue* pVkQueue = (const VulkanQueue*)pTargetQueue;

		//Get cmd buffers
		VkCommandBuffer vkCmdBuffers[32];
		for (UInt32 cmdListIndex = 0; cmdListIndex < cmdListCount; cmdListIndex++)
		{
			const VulkanCommandList* pCmdList = (const VulkanCommandList*)ppCmdLists[cmdListIndex];
			vkCmdBuffers[cmdListIndex] = pCmdList->GetVkCmdBuffer();
		}
		
		//Get wait semaphores
		VkSemaphore vkSignalSemahpores[32];
		for (UInt32 i = 0; i < signalSemaphoreCount; i++)
		{
			const VulkanSemaphore* pSemaphore = (const VulkanSemaphore*)ppSignalSemaphores[i];
			vkSignalSemahpores[i] = pSemaphore->GetVkSemaphore();
		}

		//Get wait semaphores
		VkSemaphore vkWaitSemahpores[32];
		for (UInt32 i = 0; i < waitSemaphoreCount; i++)
		{
			const VulkanSemaphore* pSemaphore = (const VulkanSemaphore*)ppWaitSemaphores[i];
			vkWaitSemahpores[i] = pSemaphore->GetVkSemaphore();
		}

		//Get wait semaphore stage flags
		VkPipelineStageFlags vkStageWaitFlags[32];
		for (UInt32 i = 0; i < waitSemaphoreCount; i++)
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

		DEV_ASSERT(vkQueueSubmit(pVkQueue->GetVkQueue(), cmdListCount, &submitInfo, pVkFence != nullptr ? pVkFence->GetVkFence() :VK_NULL_HANDLE) == VK_SUCCESS, "VulkanDevice", "Failed to submit the command lists");
	}
	void VulkanDevice::ResetFencesCore(Fence** ppFences, const UInt32 count)
	{
		VkFence fences[512];
		for (UInt32 i = 0; i < count; i++)
		{
			const VulkanFence* pFence = (const VulkanFence*)ppFences[i];
			fences[i] = pFence->GetVkFence();
		}

		DEV_ASSERT(vkResetFences(mLogicalDevice, count, fences) == VK_SUCCESS, "VulkanDevice", "Failed to reset the fences");
	}
	void VulkanDevice::WaitFencesCore(Fence** ppFences, const UInt32 count)
	{
		VkFence fences[512];
		for (UInt32 i = 0; i < count; i++)
		{
			const VulkanFence* pFence = (const VulkanFence*)ppFences[i];
			fences[i] = pFence->GetVkFence();
		}

		DEV_ASSERT(vkWaitForFences(mLogicalDevice, count, fences, VK_TRUE, UINT64_MAX) == VK_SUCCESS, "VulkanDevice", "Failed to wait for fences");
	}
	void VulkanDevice::WaitDeviceIdleCore()
	{
		DEV_ASSERT(vkDeviceWaitIdle(mLogicalDevice) == VK_SUCCESS, "VulkanDevice", "Failed to wait device idle");
	}
	void VulkanDevice::WaitQueueIdleCore(GraphicsQueue* pQueue)
	{
		const VulkanQueue* pVkQueue = (const VulkanQueue*)pQueue;

		DEV_ASSERT(vkQueueWaitIdle(pVkQueue->GetVkQueue()) == VK_SUCCESS, "VulkanDevice", "Failed to wait for queue");
	}
	void VulkanDevice::UpdateDescriptorSetCore(DescriptorSet* pSet, const DescriptorSetUpdateDesc& desc)
	{
		const VulkanDescriptorSet* pVkSet = (const VulkanDescriptorSet*)pSet;

		VkWriteDescriptorSet writeInformations[32];
		VkDescriptorBufferInfo writeBufferInformations[32];
		VkDescriptorImageInfo writeImageInformations[32];
		UInt32 bufferIndex = 0;
		UInt32 imageIndex = 0;

		for (Byte i = 0; i < desc.Entries.GetSize(); i++)
		{
			const DescriptorSetUpdateEntry& entry = desc.Entries[i];

			VkWriteDescriptorSet writeInfo = {};
			writeInfo.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			writeInfo.descriptorType = VulkanDescriptorUtils::GetDescriptorType(entry.Type);
			writeInfo.descriptorCount = 1;
			writeInfo.dstArrayElement = entry.ArrayElement;
			writeInfo.dstBinding = entry.Binding;
			writeInfo.dstSet = pVkSet->GetVkSet();
			writeInfo.pNext = nullptr;
			writeInfo.pBufferInfo = nullptr;
			writeInfo.pImageInfo = nullptr;

			switch (entry.Type)
			{
				case Portakal::DescriptorResourceType::Sampler:
				{
					const VulkanSampler* pSampler = (const VulkanSampler*)entry.pResource;

					VkDescriptorImageInfo samplerImageInfo = {};
					samplerImageInfo.imageView = VK_NULL_HANDLE;
					samplerImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
					samplerImageInfo.sampler = pSampler->GetVkSampler();
					writeImageInformations[imageIndex] = samplerImageInfo;
					writeInfo.pImageInfo = &writeImageInformations[imageIndex];
					writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLER;
					imageIndex++;
					break;
				}
				case Portakal::DescriptorResourceType::SampledTexture:
				{
					const VulkanTextureView* pView = (const VulkanTextureView*)entry.pResource;

					VkDescriptorImageInfo imageInfo = {};
					imageInfo.imageView = pView->GetVkView();
					imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
					imageInfo.sampler = VK_NULL_HANDLE;
					writeImageInformations[imageIndex] = imageInfo;
					writeInfo.pImageInfo = &writeImageInformations[imageIndex];
					writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
					imageIndex++;
					break;
				}
				case Portakal::DescriptorResourceType::StorageTexture:
				{
					const VulkanTextureView* pView = (const VulkanTextureView*)entry.pResource;

					VkDescriptorImageInfo imageInfo = {};
					imageInfo.imageView = pView->GetVkView();
					imageInfo.imageLayout = VK_IMAGE_LAYOUT_GENERAL;
					imageInfo.sampler = VK_NULL_HANDLE;
					writeImageInformations[imageIndex] = imageInfo;
					writeInfo.pImageInfo = &writeImageInformations[imageIndex];
					writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
					imageIndex++;
					break;
				}
				case Portakal::DescriptorResourceType::ConstantBuffer:
				{
					const VulkanBuffer* pBuffer = (const VulkanBuffer*)entry.pResource;

					VkDescriptorBufferInfo bufferInfo = {};
					bufferInfo.buffer = pBuffer->GetVkBuffer();
					bufferInfo.offset = entry.BufferOffsetInBytes;
					bufferInfo.range = pBuffer->GetTotalSize();
					writeBufferInformations[bufferIndex] = bufferInfo;
					writeInfo.pBufferInfo = &writeBufferInformations[bufferIndex];
					writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
					bufferIndex++;
					break;
				}
				case Portakal::DescriptorResourceType::StorageBuffer:
				{
					const VulkanBuffer* pBuffer = (const VulkanBuffer*)entry.pResource;

					VkDescriptorBufferInfo bufferInfo = {};
					bufferInfo.buffer = pBuffer->GetVkBuffer();
					bufferInfo.offset = entry.BufferOffsetInBytes;
					bufferInfo.range = pBuffer->GetTotalSize();
					writeBufferInformations[bufferIndex] = bufferInfo;
					writeInfo.pBufferInfo = &writeBufferInformations[bufferIndex];
					writeInfo.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
					bufferIndex++;
					break;
				}
				default:
					break;
			}

			writeInformations[i] = writeInfo;
		}

		vkUpdateDescriptorSets(mLogicalDevice, desc.Entries.GetSize(), writeInformations, 0, nullptr);
	}
	void VulkanDevice::CopyDescriptorSetCore(DescriptorSet* pSourceSet, DescriptorSet* pDestinationSet, const DescriptorSetCopyDesc& desc)
	{
		const VulkanDescriptorSet* pVkSourceSet = (const VulkanDescriptorSet*)pSourceSet;
		const VulkanDescriptorSet* pVkDestinationSet = (const VulkanDescriptorSet*)pDestinationSet;

		VkCopyDescriptorSet informations[32];

		for (Byte i = 0;i<desc.Entries.GetSize();i++)
		{
			const DescriptorSetCopyEntry& entry = desc.Entries[i];

			VkCopyDescriptorSet info = {};
			info.sType = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
			info.srcSet = pVkSourceSet->GetVkSet();
			info.srcBinding = entry.SourceBinding;
			info.srcArrayElement = entry.SourceArrayElement;

			info.dstSet = pVkDestinationSet->GetVkSet();
			info.dstBinding = entry.DestinationBinding;
			info.dstArrayElement = entry.DestinationArrayElement;

			info.descriptorCount = entry.DescriptorCount;
			
			info.pNext = nullptr;
			informations[i] = info;
		}
		
		vkUpdateDescriptorSets(mLogicalDevice, 0, nullptr, desc.Entries.GetSize(), informations);
	}
	void VulkanDevice::UpdateHostBufferCore(GraphicsBuffer* pTargetBuffer, const HostBufferUpdateDesc& desc)
	{
		const VulkanMemory* pMemory = (const VulkanMemory*)pTargetBuffer->GetMemory().GetHeap();
		const VulkanBuffer* pBuffer = (const VulkanBuffer*)pTargetBuffer;

		Byte* pTargetHostData = nullptr;
		DEV_ASSERT(vkMapMemory(mLogicalDevice, pMemory->GetVkMemory(), pBuffer->GetVkMemoryAlignedOffset() + desc.OffsetInBytes, desc.SizeInBytes, VkMemoryMapFlags(), (void**)&pTargetHostData) == VK_SUCCESS, "VulkanDevice", "Failed to map memory");
		memcpy(pTargetHostData, desc.pBuffer, desc.SizeInBytes);
		vkUnmapMemory(mLogicalDevice, pMemory->GetVkMemory());
	}
	CommandPool* VulkanDevice::CreateCommandPoolCore(const CommandPoolDesc& desc)
	{
		return new VulkanCommandPool(desc,this);
	}
	CommandList* VulkanDevice::CreateCommandListCore(const CommandListDesc& desc)
	{
		return new VulkanCommandList(desc,this);
	}
	Pipeline* VulkanDevice::CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc)
	{
		return new VulkanPipeline(desc,this);
	}
	Pipeline* VulkanDevice::CreateComputePipelineCore(const ComputePipelineDesc& desc)
	{
		return new VulkanPipeline(desc,this);
	}
	RenderPass* VulkanDevice::CreateRenderPassCore(const RenderPassDesc& desc)
	{
		return new VulkanRenderPass(desc,this);
	}
}
