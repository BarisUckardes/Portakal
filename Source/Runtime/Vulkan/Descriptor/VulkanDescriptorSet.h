#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSet.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanDescriptorSet : public DescriptorSet
	{
	public:
		VulkanDescriptorSet(const DescriptorSetDesc& desc, VulkanDevice* pDevice);
		~VulkanDescriptorSet();

		FORCEINLINE VkDescriptorSet GetVkSet() const noexcept
		{
			return mSet;
		}
	private:
		VkDescriptorSet mSet;
		VkDescriptorPool mPool;
		VkDevice mLogicalDevice;
	};
}
