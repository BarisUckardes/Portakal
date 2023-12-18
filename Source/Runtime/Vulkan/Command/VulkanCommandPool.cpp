#include "VulkanCommandPool.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
	VulkanCommandPool::VulkanCommandPool(const CommandPoolDesc& desc, VulkanDevice* pDevice) : CommandPool(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mPool(VK_NULL_HANDLE)
	{
        //Get family index
        int32 queueFamilyIndex = -1;
        switch (desc.Type)
        {
        case CommandPoolType::Graphics:
        default:
        {
            queueFamilyIndex = pDevice->GetGraphicsQueueFamilyIndex();
            break;
        }
        case CommandPoolType::Compute:
        {
            queueFamilyIndex = pDevice->GetComputeQueueFamilyIndex();
            break;
        }
        case CommandPoolType::Transfer:
        {
            queueFamilyIndex = pDevice->GetTransfersQueueFamilyIndex();
            break;
        }
        }

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
	}
}
