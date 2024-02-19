#pragma once
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <vulkan.h>

namespace Portakal
{
    class RUNTIME_API VulkanShaderUtils
    {
    public:
        FORCEINLINE static VkShaderStageFlags GetShaderFlags(const ShaderStage stages)
        {
            VkShaderStageFlags flags = VkShaderStageFlags();

            if (stages & ShaderStage::Vertex)
                flags |= VK_SHADER_STAGE_VERTEX_BIT;
            if (stages & ShaderStage::Fragment)
                flags |= VK_SHADER_STAGE_FRAGMENT_BIT;
            if (stages & ShaderStage::TesellationEval)
                flags |= VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
            if (stages & ShaderStage::TesellationControl)
                flags |= VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
            if (stages & ShaderStage::Geometry)
                flags |= VK_SHADER_STAGE_GEOMETRY_BIT;
            if (stages & ShaderStage::Compute)
                flags |= VK_SHADER_STAGE_COMPUTE_BIT;

            return flags;
        }
    public:
        VulkanShaderUtils() = delete;
        ~VulkanShaderUtils() = delete;
    };
}
