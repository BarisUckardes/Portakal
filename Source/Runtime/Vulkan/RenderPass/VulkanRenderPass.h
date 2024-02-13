#pragma once
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanRenderPass : public RenderPass
	{
	public:
		VulkanRenderPass(const RenderPassDesc& desc, VulkanDevice* pDevice);
		~VulkanRenderPass() = default;

		FORCEINLINE VkRenderPass GetVkRenderPass() const noexcept
		{
			return mRenderPass;
		}
		FORCEINLINE VkFramebuffer GetVkFramebuffer() const noexcept
		{
			return mFramebuffer;
		}
		FORCEINLINE Vector2US GetAvailableSize() const noexcept
		{
			return mSize;
		}
		virtual void OnShutdown() override;
	private:
		VkFramebuffer mFramebuffer;
		VkDevice mLogicalDevice;
		VkRenderPass mRenderPass;
		Vector2US mSize;
	};
}
