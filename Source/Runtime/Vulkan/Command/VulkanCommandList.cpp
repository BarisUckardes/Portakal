#include "VulkanCommandList.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Buffer/VulkanBuffer.h>
#include <Runtime/Vulkan/Command/VulkanCommandPool.h>
#include <Runtime/Vulkan/Fence/VulkanFence.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipeline.h>
#include <Runtime/Vulkan/Resource/VulkanResourcePool.h>
#include <Runtime/Vulkan/Resource/VulkanResourceTable.h>
#include <Runtime/Vulkan/Sampler/VulkanSampler.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTextureView.h>
#include <Runtime/Vulkan/Command/VulkanCommandListUtils.h>
#include <Runtime/Vulkan/Sampler/VulkanSamplerUtils.h>

namespace Portakal
{

    VulkanCommandList::VulkanCommandList(const CommandListDesc& desc, VulkanDevice* pDevice) : CommandList(desc), mCommandBuffer(VK_NULL_HANDLE)
    {
        VulkanCommandPool* pCmdPool = (VulkanCommandPool*)desc.pPool.GetHeap();

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

    void VulkanCommandList::SetVertexBufferCore(const GraphicsBuffer* pBuffer)
    {
        constexpr VkDeviceSize offsets[] = { 0 };

        VulkanBuffer* pVkBuffer = (VulkanBuffer*)pBuffer;
        VkBuffer buffers = pVkBuffer->GetVkBuffer();
        vkCmdBindVertexBuffers(mCommandBuffer, 0, 1, &buffers, offsets);
    }
    void VulkanCommandList::SetIndexBufferCore(const GraphicsBuffer* pBuffer, const CommandListIndexBufferType type)
    {
        VulkanBuffer* pVkBuffer = (VulkanBuffer*)pBuffer;
        vkCmdBindIndexBuffer(mCommandBuffer, pVkBuffer->GetVkBuffer(), 0, type == CommandListIndexBufferType::Unsigned_Short ? VK_INDEX_TYPE_UINT16 : VK_INDEX_TYPE_UINT32);
    }
    void VulkanCommandList::DrawIndexedCore(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexOffset, const uint32 instanceCount, const uint32 instanceOffset)
    {
        vkCmdDrawIndexed(mCommandBuffer, indexCount, instanceCount, indexOffset, vertexOffset, instanceOffset);
    }
    void VulkanCommandList::DispatchComputeCore(const uint32 groupX, const uint32 groupY, const uint32 groupZ)
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
        blitInfo.srcSubresource.aspectMask = VulkanTextureUtils::GetImageAspects(desc.SourceAspectFlags);
        blitInfo.srcSubresource.baseArrayLayer = desc.SourceArrayIndex;
        blitInfo.srcSubresource.layerCount = pSourceTexture->GetMipLevels();
        blitInfo.srcSubresource.mipLevel = desc.SourceMipIndex;

        blitInfo.dstOffsets[0] = { (int)desc.DestinationOffset.X,(int)desc.DestinationOffset.Y,(int)desc.DestinationOffset.Z };
        blitInfo.dstSubresource.aspectMask = VulkanTextureUtils::GetImageAspects(desc.DestinationAspectFlags);
        blitInfo.dstSubresource.baseArrayLayer = desc.DestinationArrayIndex;
        blitInfo.dstSubresource.layerCount = pDestinationTexture->GetMipLevels();
        blitInfo.dstSubresource.mipLevel = desc.DestinationMipIndex;

        vkCmdBlitImage(mCommandBuffer, pVkSourceTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, pVkDestinationTexture->GetVkImage(), VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blitInfo, VulkanSamplerUtils::GetFilter(desc.Filtering));
    }
    void VulkanCommandList::SetTextureMemoryBarrierCore(const Texture* Texture, const CommandListTextureMemoryBarrierDesc& desc)
    {
        const VulkanTexture* pVkTexture = (const VulkanTexture*)Texture;

        VkImageMemoryBarrier memoryBarrier = {};
        memoryBarrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        memoryBarrier.pNext = nullptr;
        memoryBarrier.image = pVkTexture->GetVkImage();
        memoryBarrier.oldLayout = VulkanTextureUtils::GetImageLayout(desc.SourceLayout);
        memoryBarrier.newLayout = VulkanTextureUtils::GetImageLayout(desc.DestinationLayout);
        memoryBarrier.srcQueueFamilyIndex = GetQueueFamilyIndex(desc.SourceQueue);
        memoryBarrier.dstQueueFamilyIndex = GetQueueFamilyIndex(desc.DestinationQueue);
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
    void VulkanCommandList::SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc)
    {
        const VulkanBuffer* pVkBuffer = (const VulkanBuffer*)pBuffer;

        VkBufferMemoryBarrier barrier = {};
        barrier.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
        barrier.buffer = pVkBuffer->GetVkBuffer();
        barrier.srcAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.SourceAccessFlags);
        barrier.srcQueueFamilyIndex = GetQueueFamilyIndex(desc.SourceQueueFamily);
        barrier.dstAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(desc.DestinationAccessFlags);
        barrier.dstAccessMask = GetQueueFamilyIndex(desc.DestinationQueueFamily);
        barrier.offset = desc.OffsetInBytes;
        barrier.size = desc.SizeInBytes;

        vkCmdPipelineBarrier(mCommandBuffer,
            VulkanPipelineUtils::GetStageFlags(desc.SourceStageFlags), VulkanPipelineUtils::GetStageFlags(desc.DestinationStageFlags),
            0,
            0, nullptr,
            1, &barrier,
            0, nullptr);
    }
    byte VulkanCommandList::GetQueueFamilyIndex(GraphicsQueueType type)
    {
        VulkanDevice* pDevice = (VulkanDevice*)GetOwnerDevice();

        switch (type)
        {
            case GraphicsQueueType::Graphics:
            default:
                return pDevice->GetGraphicsQueueFamilyIndex();
            case GraphicsQueueType::Compute:
                return pDevice->GetComputeQueueFamilyIndex();
            case GraphicsQueueType::Transfer:
                return pDevice->GetTransfersQueueFamilyIndex();
        }
    }
    void VulkanCommandList::OnShutdown()
    {

    }
    void VulkanCommandList::BeginRenderPassCore(const RenderPass* pRenderPass)
    {
    }
    void VulkanCommandList::EndRenderPassCore()
    {
    }
    void VulkanCommandList::SetViewportsCore(const ViewportDesc* pViewports, const byte count)
    {
        VkViewport vkViewports[32];

        for (byte viewportIndex = 0; viewportIndex < count; viewportIndex++)
        {
            const ViewportDesc& viewport = pViewports[viewportIndex];

            VkViewport vkViewport = {};
            vkViewport.x = viewport.OffsetInPixels.X;
            vkViewport.y = viewport.OffsetInPixels.Y;
            vkViewport.width = viewport.SizeInPixels.X;
            vkViewport.height = viewport.SizeInPixels.Y;
            vkViewport.minDepth = viewport.DepthRange.X;
            vkViewport.maxDepth = viewport.DepthRange.Y;

            vkViewports[viewportIndex] = vkViewport;
        }
        vkCmdSetViewport(mCommandBuffer, 0, count, vkViewports);
    }
    void VulkanCommandList::SetScissorsCore(const ScissorDesc* pScissorss, const byte count)
    {
        VkRect2D vkScissors[32];

        for (byte scissorIndex = 0; scissorIndex < count; scissorIndex++)
        {
            const ScissorDesc& scissor = pScissorss[scissorIndex];

            VkRect2D rect = {};
            rect.offset = { (int32)(scissor.OffsetInPixels.X),(int32)(scissor.OffsetInPixels.Y) };
            rect.extent = { scissor.SizeInPixels.X,scissor.SizeInPixels.Y };

            vkScissors[scissorIndex] = rect;
        }

        vkCmdSetScissor(mCommandBuffer, 0, count, vkScissors);
    }
    void VulkanCommandList::CommitResourcesCore(const Array<ResourceTable*>& resources)
    {
        VkDescriptorSet descriptorSets[128];

        const VulkanPipeline* pPipeline = (const VulkanPipeline*)GetBoundPipeline().GetHeap();

        for (byte resourceIndex = 0; resourceIndex < resources.GetSize(); resourceIndex++)
        {
            const VulkanResourceTable* pResource = (const VulkanResourceTable*)resources[resourceIndex];

            descriptorSets[resourceIndex] = pResource->GetVkDescriptorSet();
        }

        vkCmdBindDescriptorSets(mCommandBuffer, pPipeline->GetVkPipelinBindPoint(), pPipeline->GetVkPipelineLayout(), 0, resources.GetSize(), descriptorSets, 0, nullptr);
    }
    void VulkanCommandList::SetPipelineCore(const Pipeline* pPipeline)
    {
        const VulkanPipeline* pVkPipeline = (const VulkanPipeline*)pPipeline;

        vkCmdBindPipeline(mCommandBuffer, pVkPipeline->GetVkPipelinBindPoint(), pVkPipeline->GetVkPipeline());
    }

}