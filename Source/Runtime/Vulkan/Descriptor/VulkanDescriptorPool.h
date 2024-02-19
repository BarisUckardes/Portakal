#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorPool.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanDescriptorPool : public DescriptorPool
	{
	public:
		VulkanDescriptorPool(const DescriptorPoolDesc& desc, VulkanDevice* pDevice);
		~VulkanDescriptorPool();

		FORCEINLINE VkDescriptorPool GetVkPool() const noexcept
		{
			return mPool;
		}
	private:
		VkDescriptorPool mPool;
		VkDevice mLogicalDevice;
	};
}
