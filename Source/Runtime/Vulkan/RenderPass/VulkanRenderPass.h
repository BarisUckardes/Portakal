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
		virtual void OnShutdown() override;
	private:
		VkDevice mLogicalDevice;
		VkRenderPass mRenderPass;
	};
}
