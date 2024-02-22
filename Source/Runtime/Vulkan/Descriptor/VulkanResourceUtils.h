#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>
#include <vulkan.h>

namespace Portakal
{
    class RUNTIME_API VulkanResourceUtils
    {
    public:
        static VkDescriptorType GetDescriptorType(const DescriptorResourceType type);
    public:
        VulkanResourceUtils() = delete;
        ~VulkanResourceUtils() = delete;
    };
}
