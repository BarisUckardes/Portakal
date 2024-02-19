#include "VulkanCommandPool.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
	VulkanCommandPool::VulkanCommandPool(const CommandPoolDesc& desc, VulkanDevice* pDevice) : CommandPool(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mPool(VK_NULL_HANDLE)
	{
        //Get family index
        const unsigned char queueFamilyIndex = pDevice->vkGetQueueFamilyIndex((GraphicsQueueType)desc.Type);


        DEV_ASSERT(queueFamilyIndex != -1, "VulkanCommandPool", "Failed to find corresponding queue family index");

        //Create command pool
        VkCommandPoolCreateInfo cmdPoolInfo = {};
        cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        cmdPoolInfo.queueFamilyIndex = queueFamilyIndex;
        cmdPoolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

        DEV_ASSERT(vkCreateCommandPool(mLogicalDevice, &cmdPoolInfo, nullptr, &mPool) == VK_SUCCESS, "VulkanCommandPool", "Failed to create command pool");
	}
	void VulkanCommandPool::OnShutdown()
	{
        vkDestroyCommandPool(mLogicalDevice, mPool, nullptr);
	}
}
