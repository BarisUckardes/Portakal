#pragma once
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanResourcePool : public ResourceTablePool
    {
    public:
        VulkanResourcePool(const ResourceTablePoolDesc& desc, VulkanDevice* pDevice);
        ~VulkanResourcePool() = default;

        FORCEINLINE VkDescriptorPool GetVkDescriptorPool() const noexcept { return mPool; }
    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorPool mPool;
        VkDevice mLogicalDevice;
    };
}
