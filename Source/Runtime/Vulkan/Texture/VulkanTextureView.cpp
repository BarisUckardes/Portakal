#include "VulkanTextureView.h"
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    VulkanTextureView::VulkanTextureView(const TextureViewDesc& desc, const VkImageView view, VulkanDevice* pDevice) : TextureView(desc,pDevice),mView(view),mLogicalDevice(pDevice->GetVkLogicalDevice()),mSwapchain(true)
    {

    }
    VulkanTextureView::VulkanTextureView(const TextureViewDesc& desc, VulkanDevice* pDevice) : TextureView(desc,pDevice),mView(VK_NULL_HANDLE),mLogicalDevice(pDevice->GetVkLogicalDevice()),mSwapchain(false)
	{
        //Get vulkan texture
        const VulkanTexture* pTexture = (VulkanTexture*)desc.pTexture;
        constexpr VkComponentMapping swizzleMap = {
            VK_COMPONENT_SWIZZLE_R,
            VK_COMPONENT_SWIZZLE_G,
            VK_COMPONENT_SWIZZLE_B,
            VK_COMPONENT_SWIZZLE_A
        };

        //Create image view
        VkImageViewCreateInfo info = {};
        info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        info.image = pTexture->GetVkImage();
        info.format = VulkanTextureUtils::GetTextureFormat(pTexture->GetFormat());
        info.viewType = VulkanTextureUtils::GetImageViewType(pTexture->GetTextureType());
        info.subresourceRange.aspectMask = VulkanTextureUtils::GetImageAspects(desc.AspectFlags);
        info.subresourceRange.baseArrayLayer = desc.ArrayLevel;
        info.subresourceRange.baseMipLevel = desc.MipLevel;
        info.subresourceRange.layerCount = desc.pTexture->GetArrayLevels();
        info.subresourceRange.levelCount = desc.pTexture->GetMipLevels();
        info.components = swizzleMap;
        info.flags = VkImageViewCreateFlags();
        info.pNext = nullptr;

        DEV_ASSERT(vkCreateImageView(mLogicalDevice, &info, nullptr, &mView) == VK_SUCCESS, "VulkanTextureView", "Failed to create view");
	}
	VulkanTextureView::~VulkanTextureView()
	{
        if(!mSwapchain)
            vkDestroyImageView(mLogicalDevice, mView, nullptr);
	}
}
