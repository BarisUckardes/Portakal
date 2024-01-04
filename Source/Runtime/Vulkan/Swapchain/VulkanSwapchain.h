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
		Bool8 PresentCore() override;
		void ResizeCore(const Uint16 width, const Uint16 height) override;
		void Free();
		// Inherited via Swapchain
		Bool8 SetFullScreen() override;
		Bool8 SetWindowed() override;
	private:
		VulkanDevice* mDevice;
		VkSurfaceKHR mSurface;
		VkSwapchainKHR mSwapchain;
		VkDevice mLogicalDevice;
		VkPhysicalDevice mPhysicalDevice;
		Uint32 mPresentQueueFamilyIndex;
	};
}
