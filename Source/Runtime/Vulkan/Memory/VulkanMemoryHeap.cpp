#include "VulkanMemoryHeap.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Adapter/VulkanAdapter.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryUtils.h>

namespace Portakal
{
	VulkanMemoryHeap::VulkanMemoryHeap(const GraphicsMemoryHeapDesc& desc, VulkanDevice* pDevice) : GraphicsMemoryHeap(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mMemory(VK_NULL_HANDLE)
	{
		// Get device memory properties
		VkPhysicalDeviceMemoryProperties memoryProperties = {};
		vkGetPhysicalDeviceMemoryProperties(((VulkanAdapter*)pDevice->GetOwnerAdapter())->GetVkPhysicalDevice(), &memoryProperties);

		//Allocate memory
		VkMemoryAllocateInfo info = {};
		info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		info.memoryTypeIndex = VulkanMemoryUtils::GetMemoryFlags(desc.Type);
		info.allocationSize = desc.SizeInBytes;
		info.pNext = nullptr;

		DEV_ASSERT(vkAllocateMemory(mLogicalDevice, &info, nullptr, &mMemory) == VK_SUCCESS, "VulkanMemoryHeap", "Failed to allocate memory!");
	}
	void VulkanMemoryHeap::OnShutdown()
	{
		vkFreeMemory(mLogicalDevice, mMemory,nullptr);
	}
}
