#pragma once
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanSwapchain : public Swapchain
	{
	public:
		VulkanSwapchain(const SwapchainDesc& desc, VulkanDevice* pDevice);
		~VulkanSwapchain() = default;

		virtual void OnShutdown() override;
	private:
		void PresentCore() override;
		void ResizeCore(const uint16 width, const uint16 height) override;
		void Free();
		// Inherited via Swapchain
		bool SetFullScreen() override;
		bool SetWindowed() override;
	private:
		VulkanDevice* mDevice;
		VkSurfaceKHR mSurface;
		VkSwapchainKHR mSwapchain;
		VkDevice mLogicalDevice;
		VkPhysicalDevice mPhysicalDevice;
		uint32 mPresentQueueFamilyIndex;
	};
}
