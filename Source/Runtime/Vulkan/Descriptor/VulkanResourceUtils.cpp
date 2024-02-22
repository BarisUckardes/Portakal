#include "VulkanResourceUtils.h"

namespace Portakal
{

    VkDescriptorType VulkanResourceUtils::GetDescriptorType(DescriptorResourceType type)
    {
        switch (type)
        {
        case DescriptorResourceType::Sampler:
            return VK_DESCRIPTOR_TYPE_SAMPLER;
        case DescriptorResourceType::SampledTexture:
            return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
        case DescriptorResourceType::StorageTexture:
            return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
        case DescriptorResourceType::ConstantBuffer:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        case DescriptorResourceType::StorageBuffer:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        default:
            return VK_DESCRIPTOR_TYPE_SAMPLER;
        }
    }

}