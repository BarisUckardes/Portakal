#include "VulkanResourceTable.h"
#include <Runtime/Vulkan/Resource/VulkanResourceTableLayout.h>
#include <Runtime/Vulkan/Resource/VulkanDescriptorPool.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{

    VulkanResourceTable::VulkanResourceTable(const ResourceTableDesc& desc, VulkanDevice* pDevice) :
        ResourceTable(desc), mDescriptorSet(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice()), mPool(VK_NULL_HANDLE)
    {
        const VulkanDescriptorPool* pVkPool = (const VulkanDescriptorPool*)desc.pOwnerPool;
        const VulkanResourceTableLayout* pVkLayout = (const VulkanResourceTableLayout*)desc.pTargetLayout;

        /**
        * Allocate descriptor set
        */
        VkDescriptorSetAllocateInfo allocateInfo = {};
        allocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        allocateInfo.descriptorPool = pVkPool->GetVkDescriptorPool();
        VkDescriptorSetLayout layouts = pVkLayout->GetVkSetLayout();
        allocateInfo.pSetLayouts = &layouts;
        allocateInfo.descriptorSetCount = 1;
        allocateInfo.pNext = nullptr;

        DEV_ASSERT(vkAllocateDescriptorSets(pDevice->GetVkLogicalDevice(), &allocateInfo, &mDescriptorSet) == VK_SUCCESS, "VulkanDescriptorSet", "Failed to allocate descriptorset set");

        mPool = pVkPool->GetVkDescriptorPool();
    }
    void VulkanResourceTable::OnShutdown()
    {
        vkFreeDescriptorSets(mLogicalDevice, mPool, 1, &mDescriptorSet);
        mDescriptorSet = VK_NULL_HANDLE;
        mPool = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }

}