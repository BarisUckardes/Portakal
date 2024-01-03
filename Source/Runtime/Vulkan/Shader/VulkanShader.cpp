#include "VulkanShader.h"
#include <Runtime/Vulkan/Device/VulkanDevice.h>

namespace Portakal
{
    VulkanShader::VulkanShader(const ShaderDesc& desc, VulkanDevice* pDevice) : Shader(desc), mLogicalDevice(pDevice->GetVkLogicalDevice())
    {
        /**
        * Create module
        */
        VkShaderModuleCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.pCode = (const uint32_t*)desc.ByteCode.GetMemory();
        createInfo.codeSize = desc.ByteCode.GetSize();
        createInfo.flags = VkShaderModuleCreateFlags();

        DEV_ASSERT(vkCreateShaderModule(mLogicalDevice, &createInfo, nullptr, &mShader) == VK_SUCCESS, "VulkanShader", "Failed to create shader module");
    }

    void VulkanShader::OnShutdown()
    {
        vkDestroyShaderModule(mLogicalDevice, mShader, nullptr);
        mShader = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }
}