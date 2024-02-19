#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>
#include <vulkan.h>

namespace Portakal
{
    class RUNTIME_API VulkanDescriptorUtils
    {
    public:
        static VkDescriptorType GetDescriptorType(const DescriptorResourceType type);
    public:
        VulkanDescriptorUtils() = delete;
        ~VulkanDescriptorUtils() = delete;
    };
}
