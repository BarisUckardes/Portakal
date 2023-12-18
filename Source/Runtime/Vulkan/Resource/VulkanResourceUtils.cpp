#include "VulkanResourceUtils.h"

namespace Portakal
{

    VkDescriptorType VulkanResourceUtils::GetDescriptorType(GraphicsResourceType type)
    {
        switch (type)
        {
        case GraphicsResourceType::Sampler:
            return VK_DESCRIPTOR_TYPE_SAMPLER;
        case GraphicsResourceType::CombinedTextureSampler:
            return VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        case GraphicsResourceType::SampledTexture:
            return VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
        case GraphicsResourceType::StorageTexture:
            return VK_DESCRIPTOR_TYPE_STORAGE_IMAGE;
        case GraphicsResourceType::ConstantBuffer:
            return VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        case GraphicsResourceType::StorageBuffer:
            return VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
        default:
            return VK_DESCRIPTOR_TYPE_SAMPLER;
        }
    }

}