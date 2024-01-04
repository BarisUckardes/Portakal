#include "VulkanSwapchain.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Vulkan/Swapchain/VulkanSwapchainUtils.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Window.h>
#include <Windows.h>
#include <vulkan_win32.h>
#endif
#include <Runtime/Vulkan/Fence/VulkanFence.h>
#include <Runtime/Graphics/Command/CommandListTextureMemoryBarrierDesc.h>

namespace Portakal
{
	VulkanSwapchain::VulkanSwapchain(const SwapchainDesc& desc, VulkanDevice* pDevice) : Swapchain(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mPhysicalDevice(((VulkanAdapter*)pDevice->GetOwnerAdapter())->GetVkPhysicalDevice()),mPresentQueueFamilyIndex(0),mSwapchain(VK_NULL_HANDLE),mDevice(pDevice),mSurface(VK_NULL_HANDLE)
	{
		ResizeCore(desc.pWindow->GetSize().X, desc.pWindow->GetSize().Y);
	}
	void VulkanSwapchain::OnShutdown()
	{
		Swapchain::OnShutdown();

		Free();

		DEV_LOG("VulkanSwapchain", "Shutdown");
	}
	Bool8 VulkanSwapchain::PresentCore()
	{
		//Get queue first and validate
		const VkQueue queue = ((VulkanDevice*)mDevice)->GetPresentQueue(mSurface);
		if (queue == VK_NULL_HANDLE)
		{
			DEV_LOG("VulkanSwapchain", "Invalid queue handle!");
			return false;
		}

		//Get current image fence
		VkFence fence = ((VulkanFence*)GetPresentFence(GetImageIndex()).GetHeap())->GetVkFence();

		//Acquire image
		Uint32 imageIndex = 0;
		if (vkAcquireNextImageKHR(mLogicalDevice, mSwapchain, uint64_max, VK_NULL_HANDLE, fence, &imageIndex) != VK_SUCCESS)
		{
			DEV_LOG("VulkanSwapchain", "Failed to acquire image");
			return false;
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
		{
			DEV_LOG("VulkanSwapchain", "Failed to present!");
			return false;
		}

		return true;
	}
	void VulkanSwapchain::ResizeCore(const Uint16 width, const Uint16 height)
	{
		//First free
		Free();

#ifdef PORTAKAL_PLATFORM_WINDOWS
		const Win32Window* pWindow = (const Win32Window*)GetWindow().GetHeap();

		VkWin32SurfaceCreateInfoKHR surfaceInfo = {};
		surfaceInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		surfaceInfo.hwnd = pWindow->GetWin32WindowHandle();
		surfaceInfo.hinstance = GetModuleHandle(NULL);

		DEV_ASSERT(vkCreateWin32SurfaceKHR(((VulkanInstance*)mDevice->GetOwnerAdapter()->GetOwnerInstance())->GetVkInstance(), &surfaceInfo, nullptr, &mSurface) == VK_SUCCESS, "VulkanSwapchain", "Failed to create win32 surface");

		DEV_LOG("VulkanSwapchain", "Win32 surface created!");
#endif
		//Get surface capabiltiies
		VkSurfaceCapabilitiesKHR surfaceCapabilities = {};
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(mPhysicalDevice, mSurface, &surfaceCapabilities) == VK_SUCCESS, "VulkanSwapchain", "Failed to get surface capabilties!");

		//Check if surface supports the buffer count
		DEV_ASSERT(surfaceCapabilities.maxImageCount >= GetBufferCount(), "VulkanSwapchain", "Supported max buffer count is %s, but you have requested %d!", );

		//Check image dimensions
		const Vector2US windowSize = { width,height };

		//Get supported formats
		Uint32 supportedFormatCount = 0;
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, mSurface, &supportedFormatCount, nullptr) == VK_SUCCESS, "VulkanSwapchain", "Failed to get supported surface formats");
		DEV_ASSERT(supportedFormatCount > 0, "VulkanSwapchain", "No supported formats found!");

		Array<VkSurfaceFormatKHR> supportedFormats(supportedFormatCount);
		DEV_ASSERT(vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, mSurface, &supportedFormatCount, supportedFormats.GetData()) == VK_SUCCESS, "VulkanSwapchain", "Failed to get supported surface formats");

		//Get color format
		const VkFormat requestedFormat = VulkanTextureUtils::GetTextureFormat(GetColorFormat());

		//Check if requested format is supported
		Bool8 bRequiredFormatSupported = false;
		for (Byte i = 0; i < supportedFormatCount; i++)
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
		Uint32 supportedPresentModeCount = 0;
		DEV_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, mSurface, &supportedPresentModeCount, nullptr) == VK_SUCCESS, "VulkanSwapchain", "Failed to get present modes");
		DEV_ASSERT(supportedPresentModeCount > 0, "VulkanSwapchain", "No supported present modes available!");

		Array<VkPresentModeKHR> supportedPresentModes(supportedPresentModeCount);
		DEV_ASSERT(vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, mSurface, &supportedPresentModeCount, supportedPresentModes.GetData()) == VK_SUCCESS, "VulkanSwapchain", "Failed to get present modes");

		//Check if default present mode exists
		Bool8 bPresentModeSupported = false;
		for (Byte i = 0; i < supportedPresentModeCount; i++)
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
			Math::Clamp((Uint32)windowSize.X,surfaceCapabilities.minImageExtent.width,surfaceCapabilities.maxImageExtent.width),
			Math::Clamp((Uint32)windowSize.Y,surfaceCapabilities.minImageExtent.height,surfaceCapabilities.maxImageExtent.height)
		};
		SetSize(selectedExtent.width, selectedExtent.height);

		//Try get present queue family index
		const Int32 presentFamilyIndex = ((VulkanDevice*)mDevice)->GetPresentQueueFamilyIndex(mSurface);
		DEV_ASSERT(presentFamilyIndex != -1, "VulkanSwapchain", "No presentable queue found");

		//Create swapchain
		VkSwapchainCreateInfoKHR swapchainInfo = {};
		swapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapchainInfo.surface = mSurface;
		swapchainInfo.imageFormat = requestedFormat;
		swapchainInfo.minImageCount = GetBufferCount();
		swapchainInfo.imageExtent = selectedExtent;
		swapchainInfo.imageArrayLayers = 1;
		swapchainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
		swapchainInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		swapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		swapchainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		swapchainInfo.preTransform = surfaceCapabilities.currentTransform;
		swapchainInfo.presentMode = VulkanSwapchainUtils::GetPresentMode(GetPresentMode());
		swapchainInfo.clipped = VK_FALSE;
		swapchainInfo.oldSwapchain = VK_NULL_HANDLE;

		swapchainInfo.pQueueFamilyIndices = nullptr;
		swapchainInfo.queueFamilyIndexCount = presentFamilyIndex;
		swapchainInfo.flags = VkSwapchainCreateFlagsKHR();
		swapchainInfo.pNext = nullptr;

		DEV_ASSERT(vkCreateSwapchainKHR(mLogicalDevice, &swapchainInfo, nullptr, &mSwapchain) == VK_SUCCESS, "VulkanSwapchain", "Failed to create swapchain");
		DEV_LOG("VulkanSwapchain", "Initialized!");

		//Get swapchain images
		Uint32 swapchainImageCount = 0;
		DEV_ASSERT(vkGetSwapchainImagesKHR(mLogicalDevice, mSwapchain, &swapchainImageCount, nullptr) == VK_SUCCESS, "VulkanSwapchain", "Failed to get swapchain images!");
		DEV_ASSERT(swapchainImageCount == GetBufferCount(), "VulkanSwapchain", "Swapchain image count does not match with the requested image count");

		Array<VkImage> swapchainImages(swapchainImageCount);
		DEV_ASSERT(vkGetSwapchainImagesKHR(mLogicalDevice, mSwapchain, &swapchainImageCount, swapchainImages.GetData()) == VK_SUCCESS, "VulkanSwapchain", "Failed to get swapchain images!");

		//Create texture wrapper around swapchain textures
		Array<SharedHeap<Texture>> textures;
		Array<SharedHeap<TextureView>> views;
		for (Byte i = 0; i < swapchainImageCount; i++)
		{
			//Create texture
			TextureDesc textureDesc = {};
			textureDesc.Type = TextureType::Texture2D;
			textureDesc.Format = GetColorFormat();
			textureDesc.Usage = TextureUsage::ColorAttachment;
			textureDesc.Size = { (Uint16)selectedExtent.width,(Uint16)selectedExtent.height,1 };
			textureDesc.MipLevels = 1;
			textureDesc.ArrayLevels = 1;
			textureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
			textureDesc.pHeap = nullptr;

			SharedHeap<Texture> pTexture = ((VulkanDevice*)mDevice)->CreateVkSwapchainTexture(textureDesc, swapchainImages[i]);
			textures.Add(pTexture);

			//Create view
			TextureViewDesc viewDesc = {};
			viewDesc.MipLevel = 0;
			viewDesc.ArrayLevel = 0;
			viewDesc.pTexture = pTexture;
			SharedHeap<TextureView> pView = mDevice->CreateTextureView(viewDesc);
			views.Add(pView);
		}

		//Set framebuffer textures and views
		SetTextures(textures, views);
	}
	void VulkanSwapchain::Free()
	{
		//Destroy swapchain
		if(mSwapchain != VK_NULL_HANDLE)
			vkDestroySwapchainKHR(mLogicalDevice, mSwapchain, nullptr);

		//Destroy surface
		if(mSurface != VK_NULL_HANDLE)
			vkDestroySurfaceKHR(((VulkanInstance*)mDevice->GetOwnerAdapter()->GetOwnerInstance())->GetVkInstance(), mSurface, nullptr);
	}
	Bool8 VulkanSwapchain::SetFullScreen()
	{
		//Get monitor and validate
		SharedHeap<PlatformMonitor> pMonitor = GetWindow()->GetMonitor();
		if (pMonitor.IsShutdown())
			return false;

		//Resize according to the monitor
		Resize(pMonitor->GetSize().X, pMonitor->GetSize().Y);

		return true;
	}
	Bool8 VulkanSwapchain::SetWindowed()
	{
		//Get monitor and validate
		SharedHeap<PlatformMonitor> pMonitor = GetWindow()->GetMonitor();
		if (pMonitor.IsShutdown())
			return false;

		//Resize according to the monitor
		Resize(pMonitor->GetSize().X / 2, pMonitor->GetSize().Y / 2);

		return true;
	}
}
