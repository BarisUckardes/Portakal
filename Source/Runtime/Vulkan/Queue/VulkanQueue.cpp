#include "VulkanQueue.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    VulkanQueue::VulkanQueue(const GraphicsQueueDesc& desc,VulkanDevice* pDevice) : GraphicsQueue(desc,pDevice)
    {
        mQueue = pDevice->vkOwnQueue(desc.Type);
        mFamilyIndex = pDevice->vkGetQueueFamilyIndex(desc.Type);
    }
    void VulkanQueue::OnShutdown()
    {
        VulkanDevice* pDevice = (VulkanDevice*)GetOwnerDevice();
        pDevice->vkReturnQueue(GetQueueType(), mQueue);
    }
}
