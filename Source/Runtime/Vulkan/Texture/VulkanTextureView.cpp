#include "VulkanTextureView.h"
#include <RUntime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
namespace Portakal
{
    VulkanTextureView::VulkanTextureView(const TextureViewDesc& desc, VulkanDevice* pDevice) : TextureView(desc,pDevice),mLogicalDevice(pDevice->GetVkLogicalDevice()),mSwapchain(false)
    {
        //Get vulkan texture
        const VulkanTexture* pTexture = (VulkanTexture*)desc.pTexture.GetHeap();
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
        info.format = VulkanTextureUtils::GetTextureFormat(desc.Format);
        info.viewType = VulkanTextureUtils::GetImageViewType(pTexture->GetTextureType());
        info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        info.subresourceRange.baseArrayLayer = desc.ArrayLevel;
        info.subresourceRange.baseMipLevel = desc.MipLevel;
        info.subresourceRange.layerCount = desc.pTexture->GetArrayLevels();
        info.subresourceRange.levelCount = desc.pTexture->GetMipLevels();
        info.components = swizzleMap;
        info.flags = VkImageViewCreateFlags();
        info.pNext = nullptr;

        DEV_ASSERT(vkCreateImageView(mLogicalDevice, &info, nullptr, &mView) == VK_SUCCESS, "VulkanTextureView", "Failed to create view");
    }
    VulkanTextureView::VulkanTextureView(const TextureViewDesc& desc, const VkImageView view, VulkanDevice* pDevice) : TextureView(desc,pDevice),mLogicalDevice(VK_NULL_HANDLE),mSwapchain(true),mView(view)
    {
    }
    void VulkanTextureView::OnShutdown()
    {
        vkDestroyImageView(mLogicalDevice, mView, nullptr);
    }
}
