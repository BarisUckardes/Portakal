#include "VulkanSampler.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/VulkanUtils.h>
#include <Runtime/Vulkan/Sampler/VulkanSamplerUtils.h>

namespace Portakal
{
    VulkanSampler::VulkanSampler(const SamplerDesc& desc, VulkanDevice* pDevice) : Sampler(desc), mSampler(VK_NULL_HANDLE), mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        VkSamplerCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        createInfo.flags = VkSamplerCreateFlags();
        createInfo.minFilter = VulkanSamplerUtils::GetFilter(desc.MinFilter);
        createInfo.magFilter = VulkanSamplerUtils::GetFilter(desc.MagFilter);
        createInfo.addressModeU = VulkanSamplerUtils::GetAddressMode(desc.AddressModeU);
        createInfo.addressModeV = VulkanSamplerUtils::GetAddressMode(desc.AddressModeV);
        createInfo.addressModeW = VulkanSamplerUtils::GetAddressMode(desc.AddressModeW);
        createInfo.mipLodBias = desc.MipLodBias;
        createInfo.anisotropyEnable = desc.MaxAnisotropy != 0;
        createInfo.maxAnisotropy = desc.MaxAnisotropy;
        createInfo.compareEnable = desc.ComparisonEnabled;
        createInfo.compareOp = VulkanUtils::GetCompareOperation(desc.CompareOperation);
        createInfo.minLod = desc.MinLod;
        createInfo.maxLod = desc.MaxLod;
        createInfo.borderColor = VulkanSamplerUtils::GetBorderColor(desc.BorderColor);
        createInfo.unnormalizedCoordinates = false;

        createInfo.pNext = nullptr;


        DEV_ASSERT(vkCreateSampler(pDevice->GetVkLogicalDevice(), &createInfo, nullptr, &mSampler) == VK_SUCCESS, "VulkanSampler", "Failed to create sampler");

    }

    void VulkanSampler::OnShutdown()
    {
        vkDestroySampler(mLogicalDevice, mSampler, nullptr);
        mSampler = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }
}