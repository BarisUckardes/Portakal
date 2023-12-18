#pragma once
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanResourceTableLayout : public ResourceTableLayout
    {
    public:
        VulkanResourceTableLayout(const ResourceTableLayoutDesc& desc, VulkanDevice* pDevice);
        ~VulkanResourceTableLayout() = default;

        FORCEINLINE VkDescriptorSetLayout GetVkSetLayout() const noexcept { return mLayout; }

    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorSetLayout mLayout;
        VkDevice mLogicalDevice;
    };
}
