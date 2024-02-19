#pragma once
#include <Runtime/Graphics/Texture/TextureView.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanTextureView : public TextureView
	{
	public:
		VulkanTextureView(const TextureViewDesc& desc, const VkImageView view, VulkanDevice* pDevice);
		VulkanTextureView(const TextureViewDesc& desc, VulkanDevice* pDevice);
		~VulkanTextureView();

		FORCEINLINE VkImageView GetVkView() const noexcept
		{
			return mView;
		}
	private:
		VkImageView mView;
		VkDevice mLogicalDevice;
		const bool mSwapchain;
	};
}
