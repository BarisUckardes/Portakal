#pragma once
#include <Runtime/Graphics/Swapchain/PresentMode.h>
#include <vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanSwapchainUtils final
	{
	public:
		FORCEINLINE static VkPresentModeKHR GetPresentMode(const PresentMode mode)
		{
			switch (mode)
			{
			case Portakal::PresentMode::Immediate:
			default:
				return VK_PRESENT_MODE_IMMEDIATE_KHR;
			case Portakal::PresentMode::VsyncImmediate:
				return VK_PRESENT_MODE_MAILBOX_KHR;
			case Portakal::PresentMode::VsyncQueued:
				return VK_PRESENT_MODE_FIFO_KHR;;
				break;
			}
		}
	public:
		VulkanSwapchainUtils() = delete;
		~VulkanSwapchainUtils() = delete;
	};
}
