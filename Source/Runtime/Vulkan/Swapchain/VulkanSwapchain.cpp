#include "VulkanSwapchain.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Window.h>
#include <Windows.h>
#include <vulkan_win32.h>
#endif
#include <Runtime/Vulkan/Fence/VulkanFence.h>

namespace Portakal
{
	VulkanSwapchain::VulkanSwapchain(const SwapchainDesc& desc, VulkanDevice* pDevice) : Swapchain(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mPhysicalDevice(((VulkanAdapter*)pDevice->GetOwnerAdapter())->GetVkPhysicalDevice()),mPresentQueueFamilyIndex(0),mSwapchain(VK_NULL_HANDLE)
	{
#ifdef PORTAKAL_PLATFORM_WINDOWS
		const Win32Window* pWindow = (const Win32Window*)desc.pWindow.GetHeap();

		VkWin32SurfaceCreateInfoKHR surfaceInfo = {};
		surfaceInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		surfaceInfo.hwnd = pWindow->GetWin32WindowHandle();
		surfaceInfo.hinstance = GetModuleHandle(NULL);

		DEV_ASSERT(vkCreateWin32SurfaceKHR(((VulkanInstance*)pDevice->GetOwnerAdapter()->GetOwnerInstance())->GetVkInstance(), &surfaceInfo, nullptr, &mSurface) == VK_SUCCESS, "VulkanSwapchain", "Failed to create win32 surface");

		DEV_LOG("VulkanSwapchain", "Win32 surface created!");
#endif
		//Get surface capabiltiies
		VkSurfaceCapabilitiesKHR surfaceCapabilities = {};
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(mPhysicalDevice, mSurface, &surfaceCapabilities) == VK_SUCCESS, "VulkanSwapchain", "Failed to get surface capabilties!");

		//Check if surface supports the buffer count
		DEV_ASSERT(surfaceCapabilities.maxImageCount >= desc.BufferCount, "VulkanSwapchain", "Supported max buffer count is %s, but you have requested %d!", );

		//Check image dimensions
		const Vector2US windowSize = desc.pWindow->GetSize();
		
		//Get supported formats
		uint32 supportedFormatCount = 0;
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, mSurface, &supportedFormatCount, nullptr) == VK_SUCCESS,"VulkanSwapchain","Failed to get supported surface formats");
		DEV_ASSERT(supportedFormatCount > 0, "VulkanSwapchain", "No supported formats found!");

		Array<VkSurfaceFormatKHR> supportedFormats(supportedFormatCount);
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, mSurface, &supportedFormatCount, supportedFormats.GetData()) == VK_SUCCESS, "VulkanSwapchain", "Failed to get supported surface formats");

		//Get color format
		const VkFormat requestedFormat = VulkanTextureUtils::GetTextureFormat(desc.ColorFormat);

		//Check if requested format is supported
		bool bRequiredFormatSupported = false;
		for (byte i = 0; i < supportedFormatCount; i++)
		{
			const VkSurfaceFormatKHR& surfaceFormat = supportedFormats[i];

			if (surfaceFormat.format == requestedFormat && surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
			{
				bRequiredFormatSupported = true;
				break;
			}
		}
		DEV_ASSERT(bRequiredFormatSupported, "VulkanSwapchain", "Requested format is not supported!");

		//Get present modes
		uint32 supportedPresentModeCount = 0;
		DEV_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, mSurface, &supportedPresentModeCount, nullptr) == VK_SUCCESS, "VulkanSwapchain", "Failed to get present modes");
		DEV_ASSERT(supportedPresentModeCount > 0,"VulkanSwapchain", "No supported present modes available!");

		Array<VkPresentModeKHR> supportedPresentModes(supportedPresentModeCount);
		DEV_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, mSurface, &supportedPresentModeCount, supportedPresentModes.GetData()) == VK_SUCCESS, "VulkanSwapchain", "Failed to get present modes");

		//Check if default present mode exists
		bool bPresentModeSupported = false;
		for (byte i = 0; i < supportedPresentModeCount; i++)
		{
			const VkPresentModeKHR& mode = supportedPresentModes[i];
			if (mode == VK_PRESENT_MODE_FIFO_KHR)
			{
				bPresentModeSupported = true;
				break;
			}
		}
		DEV_ASSERT(bPresentModeSupported, "VulkanSwapchain", "Requested present mode is not available!");

		//Select extent
		const VkExtent2D selectedExtent =
		{
			Math::Clamp((uint32)windowSize.X,surfaceCapabilities.minImageExtent.width,surfaceCapabilities.maxImageExtent.width),
			Math::Clamp((uint32)windowSize.Y,surfaceCapabilities.minImageExtent.height,surfaceCapabilities.maxImageExtent.height)
		};

		//Try get present queue family index
		const int32 presentFamilyIndex = pDevice->GetPresentQueueFamilyIndex(mSurface);
		DEV_ASSERT(presentFamilyIndex != -1, "VulkanSwapchain", "No presentable queue found");

		//Create swapchain
		VkSwapchainCreateInfoKHR swapchainInfo = {};
		swapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapchainInfo.surface = mSurface;
		swapchainInfo.imageFormat = requestedFormat;
		swapchainInfo.minImageCount = desc.BufferCount;
		swapchainInfo.imageExtent = selectedExtent;
		swapchainInfo.imageArrayLayers = 1;
		swapchainInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		swapchainInfo.imageUsage = VK_SHARING_MODE_EXCLUSIVE;
		swapchainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		swapchainInfo.preTransform = surfaceCapabilities.currentTransform;
		swapchainInfo.presentMode = VK_PRESENT_MODE_FIFO_KHR;
		swapchainInfo.clipped = VK_TRUE;
		swapchainInfo.oldSwapchain = VK_NULL_HANDLE;

		swapchainInfo.pQueueFamilyIndices = nullptr;
		swapchainInfo.queueFamilyIndexCount = presentFamilyIndex;
		swapchainInfo.flags = VkSwapchainCreateFlagsKHR();
		swapchainInfo.pNext = nullptr;

		DEV_ASSERT(vkCreateSwapchainKHR(mLogicalDevice,&swapchainInfo,nullptr,&mSwapchain) == VK_SUCCESS,"VulkanSwapchain","Failed to create swapchain");
		DEV_LOG("VulkanSwapchain", "Initialized!");
	}
	void VulkanSwapchain::OnShutdown()
	{
		vkDestroySurfaceKHR(((VulkanInstance*)GetOwnerDevice()->GetOwnerAdapter()->GetOwnerInstance())->GetVkInstance(), mSurface, nullptr);
		DEV_LOG("VulkanSwapchain", "Shutdown");
	}
	void VulkanSwapchain::Present()
	{
		//Get queue first and validate
		const VkQueue queue = ((VulkanDevice*)GetOwnerDevice())->GetPresentQueue(mSurface);
		if (queue == VK_NULL_HANDLE)
		{
			DEV_LOG("VulkanSwapchain", "Invalid queue handle!");
			return;
		}

		VkFence fence = ((VulkanFence*)GetFence().GetHeap())->GetVkFence();

		//Acquire image
		uint32 imageIndex = 0;
		if (vkAcquireNextImageKHR(mLogicalDevice, mSwapchain, uint64_max, VK_NULL_HANDLE, fence, &imageIndex) != VK_SUCCESS)
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

		if (vkQueuePresentKHR(queue, &presentInfo) != VK_SUCCESS)
			DEV_LOG("VulkanSwapchain", "Failed to present!");
	}
}