#pragma once
#include <Runtime/Graphics/Shader/Shader.h>
#include <vulkan.h>

namespace Portakal
{
    class VulkanDevice;
    class RUNTIME_API VulkanShader : public Shader
    {
    public:
        VulkanShader(const ShaderDesc& desc, VulkanDevice* pDevice);
        ~VulkanShader() = default;

        FORCEINLINE VkShaderModule GetVkShader() const noexcept
        {
            return mShader;
        }
    private:
        virtual void OnShutdown() override;
    private:
        VkShaderModule mShader;
        VkDevice mLogicalDevice;
    };
}
