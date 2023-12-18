#pragma once
#include <Runtime/Graphics/Texture/TextureView.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanTextureView : public TextureView
	{
	public:
		VulkanTextureView(const TextureViewDesc& desc, VulkanDevice* pDevice);
		~VulkanTextureView() = default;

		FORCEINLINE VkImageView GetVkImageView() const noexcept
		{
			return mView;
		}
		virtual void OnShutdown() override;
	private:
		VkImageView mView;
		VkDevice mLogicalDevice;
	};
}
