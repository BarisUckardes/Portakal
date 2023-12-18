#pragma once
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanDescriptorPool : public ResourceTablePool
    {
    public:
        VulkanDescriptorPool(const ResourceTablePoolDesc& desc, VulkanDevice* pDevice);
        ~VulkanDescriptorPool() = default;

        FORCEINLINE VkDescriptorPool GetVkDescriptorPool() const noexcept { return mPool; }
    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorPool mPool;
        VkDevice mLogicalDevice;
    };
}
