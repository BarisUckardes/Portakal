#include "VulkanResourceTableLayout.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Resource/VulkanResourceUtils.h>
#include <Runtime/Vulkan/Shader/VulkanShaderUtils.h>

namespace Portakal
{
    VulkanResourceTableLayout::VulkanResourceTableLayout(const ResourceTableLayoutDesc& desc, VulkanDevice* pDevice) : ResourceTableLayout(desc), mLayout(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        /**
        * Create descriptor layout
        */
        VkDescriptorSetLayoutBinding vkLayoutBindings[32];
        for (byte bindingIndex = 0; bindingIndex < desc.Entries.GetSize(); bindingIndex++)
        {
            const ResourceLayoutEntry& entry = desc.Entries[bindingIndex];

            VkDescriptorSetLayoutBinding layoutBinding = {};
            layoutBinding.binding = entry.Binding;
            layoutBinding.descriptorCount = 1;
            layoutBinding.descriptorType = VulkanResourceUtils::GetDescriptorType(entry.Type);
            layoutBinding.pImmutableSamplers = nullptr;
            layoutBinding.stageFlags = VulkanShaderUtils::GetShaderFlags(entry.Stages);

            vkLayoutBindings[bindingIndex] = layoutBinding;
        }

        /**
        * Create layout
        */
        VkDescriptorSetLayoutCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        createInfo.bindingCount = desc.Entries.GetSize();
        createInfo.pBindings = vkLayoutBindings;
        createInfo.flags = VkDescriptorSetLayoutCreateFlags();
        createInfo.pNext = nullptr;

        DEV_ASSERT(vkCreateDescriptorSetLayout(pDevice->GetVkLogicalDevice(), &createInfo, nullptr, &mLayout) == VK_SUCCESS, "VulkanDescriptorLayout", "Failed to create layout");
    }

    void VulkanResourceTableLayout::OnShutdown()
    {
        vkDestroyDescriptorSetLayout(mLogicalDevice, mLayout, nullptr);
        mLayout = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }

}