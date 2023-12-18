#include "VulkanTextureView.h"
#include <RUntime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
namespace Portakal
{
    VulkanTextureView::VulkanTextureView(const TextureViewDesc& desc, VulkanDevice* pDevice) : TextureView(desc),mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        //Get vulkan texture
        const VulkanTexture* pTexture = (const VulkanTexture*)desc.pTexture.GetHeap();
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
        info.viewType = VulkanTextureUtils::GetImageViewType(pTexture->GetType());
        info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        info.subresourceRange.baseArrayLayer = 0;
        info.subresourceRange.baseMipLevel = 0;
        info.subresourceRange.layerCount = desc.ArrayLevel;
        info.subresourceRange.levelCount = desc.MipLevel;
        info.flags = VkImageViewCreateFlags();
        info.pNext = nullptr;

        DEV_ASSERT(vkCreateImageView(mLogicalDevice, &info, nullptr, &mView) == VK_SUCCESS, "VulkanTextureView", "Failed to create view");
    }
    void VulkanTextureView::OnShutdown()
    {
        vkDestroyImageView(mLogicalDevice, mView, nullptr);
    }
}
