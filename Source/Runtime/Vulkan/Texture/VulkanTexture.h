#pragma once
#include <Runtime/Graphics/Texture/Texture.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanTexture : public Texture
	{
	public:
		VulkanTexture(const TextureDesc& desc, const VkImage image, VulkanDevice* pDevice);
		VulkanTexture(const TextureDesc& desc, VulkanDevice* pDevice);
		~VulkanTexture();

		FORCEINLINE VkImage GetVkImage() const noexcept
		{
			return mImage;
		}
		FORCEINLINE UInt64 GetVkMemoryOffset() const noexcept
		{
			return mMemoryOffset;
		}
		FORCEINLINE UInt64 GetVkMemoryAlignedOffset() const noexcept
		{
			return mMemoryAlignedOffset;
		}
	private:
		const bool mSwapchain;
		VkImage mImage;
		VkDevice mLogicalDevice;
		UInt64 mMemoryOffset;
		UInt64 mMemoryAlignedOffset;
	};
}
