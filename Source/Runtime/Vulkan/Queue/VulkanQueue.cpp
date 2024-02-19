#include "VulkanQueue.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
	VulkanQueue::VulkanQueue(const GraphicsQueueDesc& desc, const VkQueue queue, const Byte familyIndex, VulkanDevice* pDevice) : GraphicsQueue(desc,pDevice),mQueue(queue),mFamilyIndex(familyIndex)
	{

	}
	VulkanQueue::~VulkanQueue()
	{
		VulkanDevice* pDevice = (VulkanDevice*)GetDevice();
		pDevice->vkReturnQueue(GetType(), mQueue);
	}
}
