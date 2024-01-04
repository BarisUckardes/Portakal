#include "VulkanTexture.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryHeap.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>

namespace Portakal
{
    VulkanTexture::VulkanTexture(const TextureDesc& desc, const VkImage image, VulkanDevice* pDevice) : Texture(desc,true),mSwapchain(true),mLogicalDevice(pDevice->GetVkLogicalDevice()),mImage(image)
    {
        
    }
    VulkanTexture::VulkanTexture(const TextureDesc& desc, VulkanDevice* pDevice) : Texture(desc,false),mSwapchain(false),mLogicalDevice(pDevice->GetVkLogicalDevice()),mImage(VK_NULL_HANDLE)
    {
        //Get vulkan memory heap
        const VulkanMemoryHeap* pHeap = (const VulkanMemoryHeap*)desc.pHeap.GetHeap();

        //Create image
        VkImageCreateInfo imageInfo = {};
        imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        imageInfo.extent = { desc.Size.X,desc.Size.Y,desc.Size.Z };
        imageInfo.format = VulkanTextureUtils::GetTextureFormat(desc.Format);
        imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        imageInfo.arrayLayers = desc.ArrayLevels;
        imageInfo.mipLevels = desc.MipLevels;
        imageInfo.imageType = VulkanTextureUtils::GetImageType(desc.Type);
        imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
        imageInfo.usage = VulkanTextureUtils::GetImageUsages(desc.Usage);
        imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        imageInfo.samples = (VkSampleCountFlagBits)VulkanTextureUtils::GetSampleCount(desc.SampleCount);

        DEV_ASSERT(vkCreateImage(mLogicalDevice, &imageInfo, nullptr, &mImage) == VK_SUCCESS, "VulkanTexture", "Failed to create texture");

        //Get memory requirements
        VkMemoryRequirements requirements = {};
        vkGetImageMemoryRequirements(mLogicalDevice, mImage, &requirements);

        //Rent memory
        const MemoryHandle memoryHandle = desc.pHeap->Allocate(requirements.size + requirements.alignment);
        const MemoryHandle alignedMemoryHandle = memoryHandle + (requirements.alignment - (memoryHandle % requirements.alignment));
        DEV_ASSERT(vkBindImageMemory(mLogicalDevice, mImage, pHeap->GetVkMemory(), alignedMemoryHandle) == VK_SUCCESS,"VulkanTexture","Failed to bind the texture memory!");

        //Set aligned handle
        SetAlignedMemory(alignedMemoryHandle);
    }
    void VulkanTexture::OnShutdown()
    {
        if (mSwapchain)
            return;

        //Cal texture impl
        Texture::OnShutdown();

        //Destroy vk image
        vkDestroyImage(mLogicalDevice, mImage, nullptr);
    }
}
