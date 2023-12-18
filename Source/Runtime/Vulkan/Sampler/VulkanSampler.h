#pragma once
#include <Runtime/Graphics/Sampler/Sampler.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanSampler : public Sampler
    {
    public:
        VulkanSampler(const SamplerDesc& desc, VulkanDevice* pDevice);
        ~VulkanSampler() = default;

        FORCEINLINE VkSampler GetVkSampler() const noexcept
        {
            return mSampler;
        }

    private:
        void OnShutdown() override;

    private:
        VkSampler mSampler;
        VkDevice mLogicalDevice;
    };
}
