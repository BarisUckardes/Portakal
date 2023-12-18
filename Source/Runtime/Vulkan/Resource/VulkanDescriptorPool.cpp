#include "VulkanDescriptorPool.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Resource/VulkanResourceUtils.h>

namespace Portakal
{
    VulkanDescriptorPool::VulkanDescriptorPool(const ResourceTablePoolDesc& desc, VulkanDevice* pDevice) : ResourceTablePool(desc), mPool(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        /**
        * Create descriptor pool
        */
        VkDescriptorPoolSize sizes[16];
        for (byte entryIndex = 0; entryIndex < desc.Entries.GetSize(); entryIndex++)
        {
            const ResourceTablePoolEntry& entry = desc.Entries[entryIndex];

            VkDescriptorPoolSize size = {};
            size.type = VulkanResourceUtils::GetDescriptorType(entry.Type);
            size.descriptorCount = entry.Count;

            sizes[entryIndex] = size;
        }

        VkDescriptorPoolCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        createInfo.poolSizeCount = desc.Entries.GetSize();
        createInfo.pPoolSizes = sizes;
        createInfo.maxSets = desc.MaxTables;
        createInfo.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;

        DEV_ASSERT(vkCreateDescriptorPool(pDevice->GetVkLogicalDevice(), &createInfo, nullptr, &mPool) == VK_SUCCESS, "VulkanDescriptorPool", "Failed to create descriptor pool");
    }

    void VulkanDescriptorPool::OnShutdown()
    {
        vkDestroyDescriptorPool(mLogicalDevice, mPool, nullptr);
        mPool = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }
}