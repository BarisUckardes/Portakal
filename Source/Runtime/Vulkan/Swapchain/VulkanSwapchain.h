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
		~VulkanSwapchain();

		FORCEINLINE VkSwapchainKHR GetVkSwapchain() const noexcept
		{
			return mSwapchain;
		}
		FORCEINLINE VkSurfaceKHR GetVkSurface() const noexcept
		{
			return mSurface;
		}
	private:
		virtual void ResizeCore(const UInt32 width, const UInt32 height) override;
		virtual void PresentCore(Semaphore** ppWaitSemahpores, const UInt32 waitSemaphoreCount) override;
		void Delete();
	private:
		VkSwapchainKHR mSwapchain;
		VkSurfaceKHR mSurface;
		VkDevice mLogicalDevice;
		VkPhysicalDevice mPhysicalDevice;
		VkInstance mInstance;
	};
}
