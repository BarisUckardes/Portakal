#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSetPool.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanDescriptorSetPool : public DescriptorSetPool
    {
    public:
        VulkanDescriptorSetPool(const DescriptorSetPoolDesc& desc, VulkanDevice* pDevice);
        ~VulkanDescriptorSetPool() = default;

        FORCEINLINE VkDescriptorPool GetVkDescriptorPool() const noexcept { return mPool; }
    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorPool mPool;
        VkDevice mLogicalDevice;
    };
}
