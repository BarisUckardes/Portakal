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
		~VulkanTexture() = default;

		FORCEINLINE VkImage GetVkImage() const noexcept
		{
			return mImage;
		}

		virtual void OnShutdown() override;
	private:
		const Bool8 mSwapchain;
		VkImage mImage;
		VkDevice mLogicalDevice;

	};
}
