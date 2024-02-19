#pragma once
#include <Runtime/Graphics/Queue/GraphicsQueue.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanQueue : public GraphicsQueue
	{
	public:
		VulkanQueue(const GraphicsQueueDesc& desc,VulkanDevice* pDevice);
		~VulkanQueue() = default;

		FORCEINLINE VkQueue GetVkQueue() const noexcept
		{
			return mQueue;
		}
		FORCEINLINE Byte GetVkFamilyIndex() const noexcept
		{
			return mFamilyIndex;
		}
	private:
		virtual void OnShutdown() override;
	private:
		VkQueue mQueue;
		Byte mFamilyIndex;
	};
}
