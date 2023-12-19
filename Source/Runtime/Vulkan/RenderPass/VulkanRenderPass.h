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
		FORCEINLINE Array<VkFramebuffer> GetvkSwapchainFramebuffers() const noexcept
		{
			return mSwapchainFramebuffers;
		}
		virtual void OnShutdown() override;
	private:
		void CreateAsSwapchain(const RenderPassDesc& desc,VulkanDevice* pDevice);
	private:
		Array<VkFramebuffer> mSwapchainFramebuffers;
		VkFramebuffer mFramebuffer;
		VkDevice mLogicalDevice;
		VkRenderPass mRenderPass;
	};
}
