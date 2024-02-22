#pragma once
#include <Runtime/Graphics/Semaphore/Semaphore.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanSemaphore : public Semaphore
	{
	public:
		VulkanSemaphore(VulkanDevice* pDevice);
		~VulkanSemaphore() = default;

		FORCEINLINE VkSemaphore GetVkSemaphore() const noexcept
		{
			return mSemaphore;
		}

		virtual void OnShutdown() override;
	private:
		VkSemaphore mSemaphore;
		VkDevice mLogicalDevice;
	};
}
