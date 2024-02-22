#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSet.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanDescriptorSet : public DescriptorSet
    {
    public:
        VulkanDescriptorSet(const DescriptorSetDesc& desc, VulkanDevice* pDevice);
        ~VulkanDescriptorSet() = default;

        FORCEINLINE VkDescriptorSet GetVkDescriptorSet() const noexcept { return mDescriptorSet; }
    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorSet mDescriptorSet;
        VkDescriptorPool mPool;
        VkDevice mLogicalDevice;
    };
}
