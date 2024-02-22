#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSetLayout.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanDescriptorSetLayout : public DescriptorSetLayout
    {
    public:
        VulkanDescriptorSetLayout(const DescriptorSetLayoutDesc& desc, VulkanDevice* pDevice);
        ~VulkanDescriptorSetLayout() = default;

        FORCEINLINE VkDescriptorSetLayout GetVkSetLayout() const noexcept { return mLayout; }

    private:
        virtual void OnShutdown() override;
    private:
        VkDescriptorSetLayout mLayout;
        VkDevice mLogicalDevice;
    };
}
