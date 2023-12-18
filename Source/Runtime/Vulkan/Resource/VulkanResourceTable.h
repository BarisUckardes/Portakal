#pragma once
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanResourceTable : public ResourceTable
    {
    public:
        VulkanResourceTable(const ResourceTableDesc& desc, VulkanDevice* pDevice);
        ~VulkanResourceTable() = default;

        FORCEINLINE VkDescriptorSet GetVkDescriptorSet() const noexcept { return mDescriptorSet; }
    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorSet mDescriptorSet;
        VkDescriptorPool mPool;
        VkDevice mLogicalDevice;
    };
}
