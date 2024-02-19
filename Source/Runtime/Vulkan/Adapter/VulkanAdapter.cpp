#include "VulkanAdapter.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    void VulkanAdapter::OnShutdown()
    {
        DEV_LOG("VulkanAdapter", "Shutdown");
    }

    GraphicsDevice* VulkanAdapter::CreateDeviceCore(const GraphicsDeviceDesc* pDesc)
    {
        return new VulkanDevice(pDesc);
    }
}
