#pragma once
#include <Runtime/Graphics/Queue/GraphicsQueue.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanQueue : public GraphicsQueue
	{
	public:
		VulkanQueue(const GraphicsQueueDesc& desc,const VkQueue queue,const Byte familyIndex, VulkanDevice* pDevice);
		~VulkanQueue();

		FORCEINLINE VkQueue GetVkQueue() const noexcept
		{
			return mQueue;
		}
		FORCEINLINE Byte GetVkFamilyIndex() const noexcept
		{
			return mFamilyIndex;
		}
	private:
		const VkQueue mQueue;
		const Byte mFamilyIndex;
	};
}
