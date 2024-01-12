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

namespace Portakal
{
    VulkanDevice::VulkanDevice(const GraphicsDeviceDesc& desc) : GraphicsDevice(desc),mPhysicalDevice(((const VulkanAdapter*)desc.pAdapter)->GetVkPhysicalDevice())
    {
        //Get queue families
        UInt32 queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, nullptr);
        DEV_ASSERT(queueFamilyCount > 0, "VulkanDevice", "No queue families found!");

        Array<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, queueFamilyProperties.GetData());

        //Collect queue families
        for (UInt32 i = 0;i<queueFamilyCount;i++)
        {
            const VkQueueFamilyProperties& properties = queueFamilyProperties[i];
            if (properties.queueFlags & VK_QUEUE_GRAPHICS_BIT && mGraphicsQueueFamily.FamilyIndex == 255)
            {
                mGraphicsQueueFamily.QueueCapacity = properties.queueCount;
                mGraphicsQueueFamily.FamilyIndex = i;
            }
            else if (properties.queueFlags & VK_QUEUE_COMPUTE_BIT && mComputeQueueFamily.FamilyIndex == 255)
            {
                mComputeQueueFamily.QueueCapacity = properties.queueCount;
                mComputeQueueFamily.FamilyIndex = i;
            }
            else if (properties.queueFlags & VK_QUEUE_TRANSFER_BIT && mTransferQueueFamily.FamilyIndex == 255)
            {
                mTransferQueueFamily.QueueCapacity = properties.queueCount;
                mTransferQueueFamily.FamilyIndex = i;
            }
        }

        //Validate queues
        DEV_ASSERT(mGraphicsQueueFamily.QueueCapacity != 0, "GraphicsDevice", "There is no queue for vk graphics queue family!");
        DEV_ASSERT(mComputeQueueFamily.QueueCapacity != 0, "GraphicsDevice", "There is no queue for vk compute queue family");
        DEV_ASSERT(mTransferQueueFamily.QueueCapacity != 0, "GraphicsDevice", "There is no queue for vk transfer queue family");

        //Get queues
        constexpr float queuePriorities[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
        Array<VkDeviceQueueCreateInfo> queueCreateInformations;
        {
            VkDeviceQueueCreateInfo graphicsQueueCreateInfo = {};
            graphicsQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            graphicsQueueCreateInfo.queueFamilyIndex = mGraphicsQueueFamily.FamilyIndex;
            graphicsQueueCreateInfo.queueCount = mGraphicsQueueFamily.QueueCapacity;
            graphicsQueueCreateInfo.pQueuePriorities = queuePriorities;
            graphicsQueueCreateInfo.pNext = nullptr;

            VkDeviceQueueCreateInfo computeQueueCreateInfo = {};
            computeQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            computeQueueCreateInfo.queueFamilyIndex = mComputeQueueFamily.FamilyIndex;
            computeQueueCreateInfo.queueCount = mComputeQueueFamily.QueueCapacity;
            computeQueueCreateInfo.pQueuePriorities = queuePriorities;
            computeQueueCreateInfo.pNext = nullptr;

            VkDeviceQueueCreateInfo transferQueueCreateInfo = {};
            transferQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            transferQueueCreateInfo.queueFamilyIndex = mTransferQueueFamily.FamilyIndex;
            transferQueueCreateInfo.queueCount = mTransferQueueFamily.QueueCapacity;
            transferQueueCreateInfo.pQueuePriorities = queuePriorities;
            transferQueueCreateInfo.pNext = nullptr;

            queueCreateInformations.Add(graphicsQueueCreateInfo);
            queueCreateInformations.Add(computeQueueCreateInfo);
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

        //Get default queues
        vkGetDeviceQueue(mLogicalDevice, mGraphicsQueueFamily.FamilyIndex, 0, &mGraphicsQueueFamily.DefaultQueue);
        vkGetDeviceQueue(mLogicalDevice, mComputeQueueFamily.FamilyIndex, 0, &mComputeQueueFamily.DefaultQueue);
        vkGetDeviceQueue(mLogicalDevice, mTransferQueueFamily.FamilyIndex, 0, &mTransferQueueFamily.DefaultQueue);

        //check default queues
        DEV_ASSERT(mGraphicsQueueFamily.DefaultQueue != NULL, "VulkanGraphicsDevice", "Graphics queue is invalid!");
        DEV_ASSERT(mComputeQueueFamily.DefaultQueue != NULL, "VulkanGraphicsDevice", "Compute queue is invalid!");
        DEV_ASSERT(mTransferQueueFamily.DefaultQueue != NULL, "VulkanGraphicsDevice", "Transfer queue is invalid!");

        DEV_LOG("VulkanDevice", "Initialized");
    }
    Int32 VulkanDevice::GetPresentQueueFamilyIndex(const VkSurfaceKHR surface) const noexcept
    {
        //Check graphics
        VkBool32 bGraphicsCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mGraphicsQueueFamily.FamilyIndex, surface, &bGraphicsCanPresent) == VK_SUCCESS,"VulkanDevice","Failed to check surface support");
        if (bGraphicsCanPresent)
            return mGraphicsQueueFamily.FamilyIndex;

        //Check compute
        VkBool32 bComputeCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mComputeQueueFamily.FamilyIndex, surface, &bComputeCanPresent) == VK_SUCCESS, "VulkanDevice", "Failed to check surface support");
        if (bComputeCanPresent)
            return mComputeQueueFamily.FamilyIndex;

        //Check transfer
        VkBool32 bTransferCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mTransferQueueFamily.FamilyIndex, surface, &bTransferCanPresent) == VK_SUCCESS, "VulkanDevice", "Failed to check surface support");
        if (bTransferCanPresent)
            return mTransferQueueFamily.FamilyIndex;

        return -1;
    }
    VkQueue VulkanDevice::GetPresentQueue(const VkSurfaceKHR surface) const noexcept
    {
        VkBool32 bGraphicsCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mGraphicsQueueFamily.FamilyIndex, surface, &bGraphicsCanPresent) == VK_SUCCESS, "VulkanDevice", "Failed to check surface support");
        if (bGraphicsCanPresent)
            return mGraphicsQueueFamily.DefaultQueue;

        //Check compute
        VkBool32 bComputeCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mComputeQueueFamily.FamilyIndex, surface, &bComputeCanPresent) == VK_SUCCESS, "VulkanDevice", "Failed to check surface support");
        if (bComputeCanPresent)
            return mComputeQueueFamily.DefaultQueue;

        //Check transfer
        VkBool32 bTransferCanPresent = false;
        DEV_ASSERT(vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mTransferQueueFamily.FamilyIndex, surface, &bTransferCanPresent) == VK_SUCCESS, "VulkanDevice", "Failed to check surface support");
        if (bTransferCanPresent)
            return mTransferQueueFamily.DefaultQueue;

        return VK_NULL_HANDLE;
    }
    SharedHeap<Texture> VulkanDevice::CreateVkSwapchainTexture(const TextureDesc& desc, const VkImage image)
    {
        SharedHeap<Texture> pTexture = new VulkanTexture(desc,image,this);
        RegisterChild(pTexture.QueryAs<GraphicsDeviceObject>());
        return pTexture;
    }
    void VulkanDevice::OnShutdown()
    {
        vkDestroyDevice(mLogicalDevice,nullptr);
        DEV_LOG("VulkanDevice", "Shutdown");
    }
    Texture* VulkanDevice::CreateTextureCore(const TextureDesc& desc)
    {
        return new VulkanTexture(desc,this);
    }
    TextureView* VulkanDevice::CreateTextureViewCore(const TextureViewDesc& desc)
    {
        return new VulkanTextureView(desc,this);
    }
   
    CommandList* VulkanDevice::CreateCommandListCore(const CommandListDesc& desc)
    {
        return new VulkanCommandList(desc,this);
    }
   
    GraphicsMemoryHeap* VulkanDevice::CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc)
    {
        return new VulkanMemoryHeap(desc,this);
    }
    GraphicsBuffer* VulkanDevice::CreateBufferCore(const GraphicsBufferDesc& desc)
    {
        return new VulkanBuffer(desc,this);
    }
    Shader* VulkanDevice::CreateShaderCore(const ShaderDesc& desc)
    {
        return new VulkanShader(desc,this);
    }
    Sampler* VulkanDevice::CreateSamplerCore(const SamplerDesc& desc)
    {
        return new VulkanSampler(desc,this);
    }
    ResourceTableLayout* VulkanDevice::CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc)
    {
        return new VulkanResourceTableLayout(desc,this);
    }
    ResourceTablePool* VulkanDevice::CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc)
    {
        return new VulkanResourcePool(desc,this);
    }
    ResourceTable* VulkanDevice::CreateResourceTableCore(const ResourceTableDesc& desc)
    {
        return new VulkanResourceTable(desc,this);
    }
    Fence* VulkanDevice::CreateFenceCore()
    {
        return new VulkanFence(this);
    }
    Swapchain* VulkanDevice::CreateSwapchainCore(const SwapchainDesc& desc)
    {
        return new VulkanSwapchain(desc,this);
    }
    RenderPass* VulkanDevice::CreateRenderPassCore(const RenderPassDesc& desc)
    {
        return new VulkanRenderPass(desc,this);
    }
    CommandPool* VulkanDevice::CreateCommandPoolCore(const CommandPoolDesc& desc)
    {
        return new VulkanCommandPool(desc,this);
    }
    Pipeline* VulkanDevice::CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc)
    {
        return new VulkanPipeline(desc,this);
    }
    SharedHeap<Pipeline> VulkanDevice::CreateComputePipelineCore(const ComputePipelineDesc& desc)
    {
        return new VulkanPipeline(desc, this);
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
        DEV_ASSERT(vkResetFences(mLogicalDevice, count, vkFences) == VK_SUCCESS, "VulkanGraphicsDevice", "Failed to reset fences[%hhu]", count);
    }
    void VulkanDevice::WaitDeviceIdleCore()
    {
        vkDeviceWaitIdle(mLogicalDevice);
    }
    void VulkanDevice::WaitQueueDefaultCore(const GraphicsQueueType type)
    {
        switch (type)
        {
            case GraphicsQueueType::Graphics:
            default:
            {
                vkQueueWaitIdle(mGraphicsQueueFamily.DefaultQueue);
                break;
            }
            case GraphicsQueueType::Compute:
            {
                vkQueueWaitIdle(mComputeQueueFamily.DefaultQueue);
                break;
            }
            case GraphicsQueueType::Transfer:
            {
                vkQueueWaitIdle(mTransferQueueFamily.DefaultQueue);
                break;
            }
            case GraphicsQueueType::Present:
            {
                vkQueueWaitIdle(mGraphicsQueueFamily.DefaultQueue);
                break;
            }
        }
    }
    void VulkanDevice::UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc)
    {
        const VulkanMemoryHeap* pHeap = (const VulkanMemoryHeap*)pBuffer->GetGraphicsHeap().GetHeap();

        Byte* pTargetHostData = nullptr;
        DEV_ASSERT(vkMapMemory(mLogicalDevice, pHeap->GetVkMemory(), pBuffer->GetAlignedMemoryHandle() + desc.OffsetInBytes, desc.View.GetSize(), 0, (void**)&pTargetHostData) == VK_SUCCESS, "VulkanDevice", "Failed to map the host buffer");
        Memory::Copy(pTargetHostData, (void*)desc.View.GetMemory(), desc.View.GetSize());
        vkUnmapMemory(mLogicalDevice, pHeap->GetVkMemory());
    }
    void VulkanDevice::UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc)
    {
        VkWriteDescriptorSet writeInformation[32];
        VkDescriptorBufferInfo writeBufferInformation[32];
        VkDescriptorImageInfo writeImageInformation[32];

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
                writeInfo.pImageInfo = &writeImageInformation[entryIndex];
                break;
            }
            case GraphicsResourceType::CombinedTextureSampler:
            {
                break;
            }
            case GraphicsResourceType::SampledTexture:
            case GraphicsResourceType::StorageTexture:
            {
                const VulkanTextureView* Texture = (const VulkanTextureView*)entry.pResource.GetHeap();

                VkDescriptorImageInfo samplerImageInfo = {};
                samplerImageInfo.imageView = Texture->GetVkImageView();
                samplerImageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                samplerImageInfo.sampler = VK_NULL_HANDLE;
                writeImageInformation[entryIndex] = samplerImageInfo;
                writeInfo.pImageInfo = &writeImageInformation[entryIndex];
                break;
            }
            case GraphicsResourceType::ConstantBuffer:
            case GraphicsResourceType::StorageBuffer:
            {
                const VulkanBuffer* pBuffer = (const VulkanBuffer*)entry.pResource.GetHeap();

                VkDescriptorBufferInfo bufferInfo = {};
                bufferInfo.buffer = pBuffer->GetVkBuffer();
                bufferInfo.offset = entry.BufferOffsetInBytes;
                bufferInfo.range = pBuffer->GetTotalSize();
                writeBufferInformation[entryIndex] = bufferInfo;
                writeInfo.pBufferInfo = &writeBufferInformation[entryIndex];

                break;
            }
            }

            writeInformation[entryIndex] = writeInfo;
        }

        vkUpdateDescriptorSets(mLogicalDevice, desc.Entries.GetSize(), writeInformation, 0, nullptr);
    }
    void VulkanDevice::SubmitCommandListsCore(CommandList** ppCmdLists, const Byte cmdListCount, const GraphicsQueueType type, const Fence* pFence)
    {
        const VulkanFence* pVkFence = (const VulkanFence*)pFence;
        VkCommandBuffer cmdBuffers[10];

        for (UInt32 cmdListIndex = 0; cmdListIndex < cmdListCount; cmdListIndex++)
        {
            const VulkanCommandList* pCmdList = (const VulkanCommandList*)ppCmdLists[cmdListIndex];

            cmdBuffers[cmdListIndex] = pCmdList->GetVkCommandBuffer();
        }

        VkSubmitInfo submitInfo = {};
        submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submitInfo.pNext = nullptr;
        submitInfo.waitSemaphoreCount = 0;
        submitInfo.pWaitSemaphores = nullptr;
        submitInfo.pCommandBuffers = cmdBuffers;
        submitInfo.commandBufferCount = cmdListCount;

        switch (type)
        {
        case GraphicsQueueType::Graphics:
        default:
        {
            DEV_ASSERT(vkQueueSubmit(mGraphicsQueueFamily.DefaultQueue, 1, &submitInfo, pVkFence != nullptr ? pVkFence->GetVkFence() : nullptr) == VK_SUCCESS, "VulkanGraphicsDevice",
                "Failed to submit command lists to the graphics queue");
            break;
        }
        case GraphicsQueueType::Compute:
        {
            DEV_ASSERT(vkQueueSubmit(mComputeQueueFamily.DefaultQueue, 1, &submitInfo, pVkFence != nullptr ? pVkFence->GetVkFence() : nullptr) == VK_SUCCESS, "VulkanGraphicsDevice",
                "Failed to submit command lists to the compute queue");
            break;
        }
        case GraphicsQueueType::Transfer:
        {
            DEV_ASSERT(vkQueueSubmit(mTransferQueueFamily.DefaultQueue, 1, &submitInfo, pVkFence != nullptr ? pVkFence->GetVkFence() : nullptr) == VK_SUCCESS, "VulkanGraphicsDevice",
                "Failed to submit command lists to the transfer queue");
            break;
        }
        }
    }
}
