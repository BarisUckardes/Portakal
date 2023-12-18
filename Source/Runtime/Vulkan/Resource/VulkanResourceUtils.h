#pragma once
#include <Runtime/Graphics/Resource/GraphicsResourceType.h>
#include <vulkan.h>

namespace Portakal
{
    class RUNTIME_API VulkanResourceUtils
    {
    public:
        static VkDescriptorType GetDescriptorType(const GraphicsResourceType type);
    public:
        VulkanResourceUtils() = delete;
        ~VulkanResourceUtils() = delete;
    };
}
