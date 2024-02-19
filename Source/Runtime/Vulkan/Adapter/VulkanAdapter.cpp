#include "VulkanAdapter.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
	VulkanAdapter::VulkanAdapter(const VkPhysicalDevice physicalDevice,const GraphicsAdapterDesc& desc) : GraphicsAdapter(desc),mDevice(physicalDevice)
	{

	}
	VulkanAdapter::~VulkanAdapter()
	{

	}
	GraphicsDevice* VulkanAdapter::CreateDeviceCore(const GraphicsDeviceDesc* pDesc)
	{
		return new VulkanDevice((VulkanDeviceDesc*)pDesc);
	}
}
