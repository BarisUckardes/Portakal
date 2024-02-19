#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceFeatures.h>
#include <vulkan.h>

namespace Portakal
{
    struct RUNTIME_API VulkanDeviceFeatures : public GraphicsDeviceFeatures
    {
        VkPhysicalDeviceFeatures Features;
    };
}
