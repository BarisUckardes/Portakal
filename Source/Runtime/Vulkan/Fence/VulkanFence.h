#pragma once
#include <Runtime/Graphics/Fence/Fence.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanFence : public Fence
	{
	public:
		VulkanFence(VulkanDevice* pDevice,const bool bSignalled);
		~VulkanFence() = default;

		FORCEINLINE VkFence GetVkFence() const noexcept
		{
			return mFence;
		}
		virtual void OnShutdown() override;
	private:
		VkFence mFence;
		VkDevice mLogicalDevice;
	};
}
