#pragma once
#include <Runtime/Graphics/Command/CommandPool.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanCommandPool : public CommandPool
	{
	public:
		VulkanCommandPool(const CommandPoolDesc& desc, VulkanDevice* pDevice);
		~VulkanCommandPool() = default;

		FORCEINLINE VkCommandPool GetVkCmdPool() const noexcept
		{
			return mPool;
		}

		virtual void OnShutdown() override;
	private:
		VkCommandPool mPool;
		VkDevice mLogicalDevice;
	};
}
