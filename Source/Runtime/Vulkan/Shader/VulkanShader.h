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
		~VulkanShader();

		FORCEINLINE VkShaderModule GetVkModule() const noexcept
		{
			return mModule;
		}
	private:
		VkShaderModule mModule;
		VkDevice mLogicalDevice;
	};
}
