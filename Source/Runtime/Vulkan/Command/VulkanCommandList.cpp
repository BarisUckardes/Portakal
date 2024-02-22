#include "VulkanCommandList.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Buffer/VulkanBuffer.h>
#include <Runtime/Vulkan/Command/VulkanCommandPool.h>
#include <Runtime/Vulkan/Fence/VulkanFence.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipeline.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSetPool.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSet.h>
#include <Runtime/Vulkan/Sampler/VulkanSampler.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTextureView.h>
#include <Runtime/Vulkan/Command/VulkanCommandListUtils.h>
#include <Runtime/Vulkan/Sampler/VulkanSamplerUtils.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPass.h>

namespace Portakal
{

	VulkanCommandList::VulkanCommandList(const CommandListDesc& desc, VulkanDevice* pDevice) : CommandList(desc,pDevice), mCommandBuffer(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice())
	{
		VulkanCommandPool* pCmdPool = (VulkanCommandPool*)desc.pPool.GetHeap();
		mCommandPool = pCmdPool->GetVkCmdPool();

		/**
		* Create command buffer
		*/
		VkCommandBufferAllocateInfo allocateInfo = {};
		allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocateInfo.commandPool = pCmdPool->GetVkCmdPool();
		allocateInfo.commandBufferCount = 1;
		allocateInfo.pNext = nullptr;

		DEV_ASSERT(vkAllocateCommandBuffers(pDevice->GetVkLogicalDevice(), &allocateInfo, &mCommandBuffer) == VK_SUCCESS, "VulkanCommandList", "Failed to allocate command buffer");
	}
	void VulkanCommandList::BeginRecordingCore()
	{
		DEV_ASSERT(vkResetCommandBuffer(mCommandBuffer, VkCommandPoolResetFlags()) == VK_SUCCESS, "VulkanCommandList", "Failed to reset cmd buffer");

		VkCommandBufferBeginInfo beginInfo = {};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = 0;
		beginInfo.pInheritanceInfo = nullptr;
		beginInfo.pNext = nullptr;

		DEV_ASSERT(vkBeginCommandBuffer(mCommandBuffer, &beginInfo) == VK_SUCCESS, "VulkanCommandList", "Failed to begin command buffer");
	}
	void VulkanCommandList::EndRecordingCore()
	{
		DEV_ASSERT(vkEndCommandBuffer(mCommandBuffer) == VK_SUCCESS, "VulkanCommandList", "Failed to end command buffer");
	}

	void VulkanCommandList::SetVertexBuffersCore(GraphicsBuffer** ppBuffers, const Byte count)
	{
		VkDeviceSize offsets[32];
		VkBuffer buffers[32];
		unsigned long long offset = 0;
		for (unsigned char i = 0; i < count; i++)
		{
			const VulkanBuffer* pBuffer = (const VulkanBuffer*)ppBuffers[i];

			buffers[i] = pBuffer->GetVkBuffer();
			offsets[i] = offset;
			offset += pBuffer->GetTotalSize();
		}

		vkCmdBindVertexBuffers(mCommandBuffer, 0, count, buffers, offsets);
	}
	void VulkanCommandList::SetIndexBufferCore(const GraphicsBuffer* pBuffer, const IndexBufferType type)
	{
		VulkanBuffer* pVkBuffer = (VulkanBuffer*)pBuffer;
		vkCmdBindIndexBuffer(mCommandBuffer, pVkBuffer->GetVkBuffer(), 0, type == IndexBufferType::UInt16 ? VK_INDEX_TYPE_UINT16 : VK_INDEX_TYPE_UINT32);
	}
	void VulkanCommandList::DrawIndexedCore(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceCount, const UInt32 instanceOffset)
	{
		vkCmdDrawIndexed(mCommandBuffer, indexCount, instanceCount, indexOffset, vertexOffset, instanceOffset);
	}
	void VulkanCommandList::DispatchComputeCore(const UInt32 groupX, const UInt32 groupY, const UInt32 groupZ)
	{
		vkCmdDispatch(mCommandBuffer, groupX, groupY, groupZ);
	}

	void VulkanCommandList::CopyBufferToTextureCore(const GraphicsBuffer* pBuffer, const Texture* Texture, const BufferTextureCopyDesc& desc)
	{
		const VulkanBuffer* pVkBuffer = (const VulkanBuffer*)pBuffer;
		const VulkanTexture* pVkTexture = (const VulkanTexture*)Texture;

		VkBufferImageCopy copyDesc = {};
		copyDesc.bufferOffset = desc.BufferOffsetInBytes;
		copyDesc.bufferRowLength = 0;
		copyDesc.bufferImageHeight = 0;

		copyDesc.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		copyDesc.imageSubresource.mipLevel = desc.TextureMipIndex;
		copyDesc.imageSubresource.baseArrayLayer = desc.TextureArrayIndex;
		copyDesc.imageSubresource.layerCount = Texture->GetMipLevels();

		copyDesc.imageOffset = { (int)desc.TextureOffsetInPixels.X,(int)desc.TextureOffsetInPixels.Y,(int)desc.TextureOffsetInPixels.Z };
		copyDesc.imageExtent = { Texture->GetSize().X,Texture->GetSize().Y ,static_cast<uint32_t>(Texture->GetSize().Z) };

		vkCmdCopyBufferToImage(mCommandBuffer, pVkBuffer->GetVkBuffer(), pVkTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &copyDesc);
	}

	void VulkanCommandList::CopyBufferToBufferCore(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc)
	{
		const VulkanBuffer* pVkSourceBuffer = (const VulkanBuffer*)pSourceBuffer;
		const VulkanBuffer* pVkDestinationBuffer = (const VulkanBuffer*)pDestinationBuffer;

		VkBufferCopy copyDesc = {};
		copyDesc.srcOffset = desc.SourceOffsetInBytes;
		copyDesc.dstOffset = desc.DestinationOffsetInBytes;
		copyDesc.size = desc.SizeInBytes;

		vkCmdCopyBuffer(mCommandBuffer, pVkSourceBuffer->GetVkBuffer(), pVkDestinationBuffer->GetVkBuffer(), 1, &copyDesc);
	}
	void VulkanCommandList::CopyTextureToTextureCore(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc)
	{
		const VulkanTexture* pVkSourceTexture = (const VulkanTexture*)pSourceTexture;
		const VulkanTexture* pVkDestinationTexture = (const VulkanTexture*)pDestinationTexture;

		VkImageBlit blitInfo = {};

		blitInfo.srcOffsets[0] = { (int)desc.SourceOffset.X,(int)desc.SourceOffset.Y,(int)desc.SourceOffset.Z };
		blitInfo.srcSubresource.aspectMask = VulkanTextureUtils::GetImageAspects(desc.SourceAspect);
		blitInfo.srcSubresource.baseArrayLayer = desc.SourceArrayIndex;
		blitInfo.srcSubresource.layerCount = pSourceTexture->GetMipLevels();
		blitInfo.srcSubresource.mipLevel = desc.SourceMipIndex;

		blitInfo.dstOffsets[0] = { (int)desc.DestinationOffset.X,(int)desc.DestinationOffset.Y,(int)desc.DestinationOffset.Z };
		blitInfo.dstSubresource.aspectMask = VulkanTextureUtils::GetImageAspects(desc.DestinationAspect);
		blitInfo.dstSubresource.baseArrayLayer = desc.DestinationArrayIndex;
		blitInfo.dstSubresource.layerCount = pDestinationTexture->GetMipLevels();
		blitInfo.dstSubresource.mipLevel = desc.DestinationMipIndex;

		vkCmdBlitImage(mCommandBuffer, pVkSourceTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, pVkDestinationTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blitInfo, VulkanSamplerUtils::GetFilter(desc.Filtering));
	}
	void VulkanCommandList::SetTextureMemoryBarrierCore(const Texture* Texture, const TextureMemoryBarrierDesc& desc)
	{
		const VulkanDevice* pDevice = (const VulkanDevice*)GetOwnerDevice();
		const VulkanTexture* pVkTexture = (const VulkanTexture*)Texture;
		const VkImage image = pVkTexture->GetVkImage();

		VkImageMemoryBarrier memoryBarrier = {};
		memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		memoryBarrier.pNext = nullptr;
		memoryBarrier.image = image;
		memoryBarrier.oldLayout = VulkanTextureUtils::GetImageLayout(desc.SourceLayout);
		memoryBarrier.newLayout = VulkanTextureUtils::GetImageLayout(desc.DestinationLayout);
		memoryBarrier.srcQueueFamilyIndex = pDevice->vkGetQueueFamilyIndex(desc.SourceQueue);
		memoryBarrier.dstQueueFamilyIndex = pDevice->vkGetQueueFamilyIndex(desc.DestinationQueue);
		memoryBarrier.subresourceRange.aspectMask = VulkanTextureUtils::GetImageAspects(desc.AspectFlags);
		memoryBarrier.subresourceRange.baseMipLevel = desc.MipIndex;
		memoryBarrier.subresourceRange.levelCount = Texture->GetMipLevels();
		memoryBarrier.subresourceRange.baseArrayLayer = desc.ArrayIndex;
		memoryBarrier.subresourceRange.layerCount = Texture->GetArrayLevels();
		memoryBarrier.srcAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.SourceAccessFlags);
		memoryBarrier.dstAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.DestinationAccessFlags);

		vkCmdPipelineBarrier(mCommandBuffer,
							 VulkanPipelineUtils::GetStageFlags(desc.SourceStageFlags), VulkanPipelineUtils::GetStageFlags(desc.DestinationStageFlags),
							 0,
							 0, nullptr,
							 0, nullptr,
							 1, &memoryBarrier);
	}
	void VulkanCommandList::SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferMemoryBarrierDesc& desc)
	{
		const VulkanDevice* pDevice = (const VulkanDevice*)GetOwnerDevice();
		const VulkanBuffer* pVkBuffer = (const VulkanBuffer*)pBuffer;

		VkBufferMemoryBarrier barrier = {};
		barrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
		barrier.buffer = pVkBuffer->GetVkBuffer();
		barrier.srcAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.SourceAccessFlags);
		barrier.srcQueueFamilyIndex = pDevice->vkGetQueueFamilyIndex(desc.SourceQueue);
		barrier.dstAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.DestinationAccessFlags);
		barrier.dstAccessMask = pDevice->vkGetQueueFamilyIndex(desc.DestinationQueue);
		barrier.offset = desc.OffsetInBytes;
		barrier.size = desc.SizeInBytes;

		vkCmdPipelineBarrier(mCommandBuffer,
							 VulkanPipelineUtils::GetStageFlags(desc.SourceStageFlags), VulkanPipelineUtils::GetStageFlags(desc.DestinationStageFlags),
							 0,
							 0, nullptr,
							 1, &barrier,
							 0, nullptr);
	}
	
	void VulkanCommandList::OnShutdown()
	{
		vkFreeCommandBuffers(mLogicalDevice, mCommandPool, 1, &mCommandBuffer);
	}
	void VulkanCommandList::ClearTextureCore(const Texture* pTexture,const Byte arrayIndex,const Byte mipIndex, const Color4F clearColor)
	{
		VulkanTexture* pVkTexture = (VulkanTexture*)pTexture;
		VkClearColorValue clearValue = {};
		clearValue.float32[0] = clearColor.R;
		clearValue.float32[1] = clearColor.G;
		clearValue.float32[2] = clearColor.B;
		clearValue.float32[3] = clearColor.A;

		VkImageSubresourceRange range = {};
		range.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		range.baseArrayLayer = arrayIndex;
		range.baseMipLevel = mipIndex;
		range.layerCount = pTexture->GetArrayLevels();
		range.levelCount = pTexture->GetMipLevels();
		vkCmdClearColorImage(mCommandBuffer, pVkTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,&clearValue,1,&range);
	}
	void VulkanCommandList::BeginRenderPassCore(const RenderPass* pRenderPass, const Color4F& clearColor)
	{
		//Get framebuffer
		const VulkanRenderPass* pVkPass = (const VulkanRenderPass*)pRenderPass;
		const VkFramebuffer framebuffer = pVkPass->GetVkFramebuffer();

		//Create render pass begin info
		VkRenderPassBeginInfo renderPassInfo = {};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = pVkPass->GetVkRenderPass();
		renderPassInfo.framebuffer = framebuffer;
		renderPassInfo.renderArea.offset = { 0,0 };
		renderPassInfo.renderArea.extent = { pRenderPass->GetRenderRegion().X,pRenderPass->GetRenderRegion().Y };
		VkClearValue color = {};
		color.color.float32[0] = clearColor.R;
		color.color.float32[1] = clearColor.G;
		color.color.float32[2] = clearColor.B;
		color.color.float32[3] = clearColor.A;
		renderPassInfo.clearValueCount = 1;
		renderPassInfo.pClearValues = &color;

		//Start render pass
		vkCmdBeginRenderPass(mCommandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
	}
	void VulkanCommandList::EndRenderPassCore()
	{
		vkCmdEndRenderPass(mCommandBuffer);
	}
	void VulkanCommandList::SetViewportsCore(const ViewportDesc* pViewports, const Byte count)
	{
		VkViewport vkViewports[32];

		for (Byte viewportIndex = 0; viewportIndex < count; viewportIndex++)
		{
			const ViewportDesc& viewport = pViewports[viewportIndex];

			VkViewport vkViewport = {};
			vkViewport.x = viewport.X;
			vkViewport.y = viewport.Y;
			vkViewport.width = viewport.Width;
			vkViewport.height = viewport.Height;
			vkViewport.minDepth = viewport.DepthMin;
			vkViewport.maxDepth = viewport.DepthMax;

			vkViewports[viewportIndex] = vkViewport;
		}
		vkCmdSetViewport(mCommandBuffer, 0, count, vkViewports);
	}
	void VulkanCommandList::SetScissorsCore(const ScissorDesc* pScissorss, const Byte count)
	{
		VkRect2D vkScissors[32];

		for (Byte scissorIndex = 0; scissorIndex < count; scissorIndex++)
		{
			const ScissorDesc& scissor = pScissorss[scissorIndex];

			VkRect2D rect = {};
			rect.offset = { (Int32)(scissor.X),(Int32)(scissor.Y) };
			rect.extent = { scissor.Width,scissor.Height };

			vkScissors[scissorIndex] = rect;
		}

		vkCmdSetScissor(mCommandBuffer, 0, count, vkScissors);
	}
	void VulkanCommandList::CommitResourcesCore(DescriptorSet** ppTables, const UInt32 count)
	{
		VkDescriptorSet descriptorSets[128];

		const VulkanPipeline* pPipeline = (const VulkanPipeline*)GetBoundPipeline().GetHeap();

		for (Byte resourceIndex = 0; resourceIndex < count; resourceIndex++)
		{
			const VulkanDescriptorSet* pResource = (const VulkanDescriptorSet*)ppTables[resourceIndex];

			descriptorSets[resourceIndex] = pResource->GetVkDescriptorSet();
		}

		vkCmdBindDescriptorSets(mCommandBuffer, pPipeline->GetVkPipelinBindPoint(), pPipeline->GetVkPipelineLayout(), 0, count, descriptorSets, 0, nullptr);
	}
	void VulkanCommandList::SetPipelineCore(const Pipeline* pPipeline)
	{
		const VulkanPipeline* pVkPipeline = (const VulkanPipeline*)pPipeline;

		vkCmdBindPipeline(mCommandBuffer, pVkPipeline->GetVkPipelinBindPoint(), pVkPipeline->GetVkPipeline());
	}

}