#include "VulkanDevice.h"
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchain.h>
#include <Runtime/Vulkan/Fence/VulkanFence.h>

namespace Portakal
{
    VulkanDevice::VulkanDevice(const GraphicsDeviceDesc& desc) : GraphicsDevice(desc),mPhysicalDevice(((const VulkanAdapter*)desc.pAdapter)->GetVkPhysicalDevice())
    {
        //Get queue families
        uint32 queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, nullptr);
        DEV_ASSERT(queueFamilyCount > 0, "VulkanDevice", "No queue families found!");

        Array<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyCount, queueFamilyProperties.GetData());

        //Collect queue families
        for (uint32 i = 0;i<queueFamilyCount;i++)
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
        //DEV_ASSERT(mPresentQueueFamily.QueueCapacity != 0, "GraphicsDevice", "There is no queue for vk present queue family");

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
        Array<const char*> logicalDeviceExtensions;
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
    int32 VulkanDevice::GetPresentQueueFamilyIndex(const VkSurfaceKHR surface) const noexcept
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
    void VulkanDevice::OnShutdown()
    {
        vkDestroyDevice(mLogicalDevice,nullptr);
        DEV_LOG("VulkanDevice", "Shutdown");
    }
    Texture* VulkanDevice::CreateTextureCore(const TextureDesc& desc)
    {
        return nullptr;
    }
    TextureView* VulkanDevice::CreateTextureViewCore(const TextureViewDesc& desc)
    {
        return nullptr;
    }
    Framebuffer* VulkanDevice::CreateFramebufferCore(const FramebufferDesc& desc)
    {
        return nullptr;
    }
    CommandList* VulkanDevice::CreateCommandListCore(const CommandListDesc& desc)
    {
        return nullptr;
    }
    Pipeline* VulkanDevice::CreatePipelineCore(const PipelineDesc& desc)
    {
        return nullptr;
    }
    GraphicsMemoryHeap* VulkanDevice::CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc)
    {
        return nullptr;
    }
    GraphicsBuffer* VulkanDevice::CreateBufferCore(const GraphicsBufferDesc& desc)
    {
        return nullptr;
    }
    Shader* VulkanDevice::CreateShaderCore(const ShaderDesc& desc)
    {
        return nullptr;
    }
    Sampler* VulkanDevice::CreateSamplerCore(const SamplerDesc& desc)
    {
        return nullptr;
    }
    ResourceTableLayout* VulkanDevice::CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc)
    {
        return nullptr;
    }
    ResourceTablePool* VulkanDevice::CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc)
    {
        return nullptr;
    }
    ResourceTable* VulkanDevice::CreateResourceTableCore(const ResourceTableDesc& desc)
    {
        return nullptr;
    }
    Fence* VulkanDevice::CreateFenceCore()
    {
        return new VulkanFence(this);
    }
    Swapchain* VulkanDevice::CreateSwapchainCore(const SwapchainDesc& desc)
    {
        return new VulkanSwapchain(desc,this);
    }
}
