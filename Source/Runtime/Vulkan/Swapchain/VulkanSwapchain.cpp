#include "VulkanSwapchain.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Window.h>
#include <Windows.h>
#include <vulkan_win32.h>
#endif

namespace Portakal
{
	VulkanSwapchain::VulkanSwapchain(const SwapchainDesc& desc, VulkanDevice* pDevice) : Swapchain(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mPhysicalDevice(VK_NULL_HANDLE),mPresentQueueFamilyIndex(0),mSwapchain(VK_NULL_HANDLE)
	{
#ifdef PORTAKAL_PLATFORM_WINDOWS
		const Win32Window* pWindow = (const Win32Window*)desc.pWindow.GetHeap();

		VkWin32SurfaceCreateInfoKHR surfaceInfo = {};
		surfaceInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		surfaceInfo.hwnd = pWindow->GetWin32WindowHandle();
		surfaceInfo.hinstance = GetModuleHandle(NULL);

		DEV_ASSERT(vkCreateWin32SurfaceKHR(VK_NULL_HANDLE, &surfaceInfo, nullptr, &mSurface) == VK_SUCCESS, "VulkanSwapchain", "Failed to create win32 surface");
#endif
	}
	void VulkanSwapchain::OnShutdown()
	{
		vkDestroySurfaceKHR(VK_NULL_HANDLE, mSurface, nullptr);
	}
	void VulkanSwapchain::Present()
	{
		//Acquire image
		uint32 imageIndex = 0;
		if (vkAcquireNextImageKHR(mLogicalDevice, mSwapchain, uint64_max, VK_NULL_HANDLE, VK_NULL_HANDLE, &imageIndex) != VK_SUCCESS)
		{
			DEV_LOG("VulkanSwapchain", "Failed to acquire image");
			return;
		}

		//Present
		VkPresentInfoKHR presentInfo = {};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 0;
		presentInfo.pWaitSemaphores = nullptr;
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = &mSwapchain;
		presentInfo.pImageIndices = &imageIndex;
		presentInfo.pResults = nullptr;

		if (vkQueuePresentKHR(VK_NULL_HANDLE, &presentInfo) != VK_SUCCESS)
			DEV_LOG("VulkanSwapchain", "Failed to present!");
	}
}
