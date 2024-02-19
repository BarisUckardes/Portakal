#pragma once
#include <Runtime/Graphics/Fence/Fence.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanFence : public Fence
	{
	public:
		VulkanFence(const FenceDesc& desc, VulkanDevice* pDevice);
		~VulkanFence();

		FORCEINLINE VkFence GetVkFence() const noexcept
		{
			return mFence;
		}
	private:
		VkFence mFence;
		VkDevice mLogicalDevice;
	};
}
