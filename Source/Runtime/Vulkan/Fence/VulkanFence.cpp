#include "VulkanFence.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    VulkanFence::VulkanFence(VulkanDevice* pDevice) : mLogicalDevice(pDevice->GetVkLogicalDevice()),mFence(VK_NULL_HANDLE)
    {
        VkFenceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        createInfo.pNext = nullptr;
        createInfo.flags = VkFenceCreateFlags();

        DEV_ASSERT(vkCreateFence(pDevice->GetVkLogicalDevice(), &createInfo, nullptr, &mFence) == VK_SUCCESS, "VulkanFence", "Failed to create fence");

        mLogicalDevice = pDevice->GetVkLogicalDevice();

    }
    void VulkanFence::OnShutdown()
    {
        vkDestroyFence(mLogicalDevice, mFence, nullptr);
    }
}