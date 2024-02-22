#include "VulkanDescriptorSet.h"
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSetLayout.h>
#include <Runtime/Vulkan/Descriptor/VulkanDescriptorSetPool.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{

    VulkanDescriptorSet::VulkanDescriptorSet(const DescriptorSetDesc& desc, VulkanDevice* pDevice) :
        DescriptorSet(desc,pDevice), mDescriptorSet(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice()), mPool(VK_NULL_HANDLE)
    {
        const VulkanDescriptorSetPool* pVkPool = (const VulkanDescriptorSetPool*)desc.pOwnerPool;
        const VulkanDescriptorSetLayout* pVkLayout = (const VulkanDescriptorSetLayout*)desc.pTargetLayout;

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
    void VulkanDescriptorSet::OnShutdown()
    {
        vkFreeDescriptorSets(mLogicalDevice, mPool, 1, &mDescriptorSet);
        mDescriptorSet = VK_NULL_HANDLE;
        mPool = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }

}