#include "VulkanSemaphore.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    VulkanSemaphore::VulkanSemaphore(VulkanDevice* pDevice) : mSemaphore(VK_NULL_HANDLE),mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        VkSemaphoreCreateInfo info = {};
        info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        info.flags = VkSemaphoreCreateFlags();
        info.pNext = nullptr;

        DEV_ASSERT(vkCreateSemaphore(mLogicalDevice, &info, nullptr, &mSemaphore) == VK_SUCCESS, "VulkanSemaphore", "Failed to create semaphore");

    }
}
