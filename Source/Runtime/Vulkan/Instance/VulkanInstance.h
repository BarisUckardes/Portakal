#pragma once
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/Vulkan/Instance/VulkanInstanceDesc.h>
#include <vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanInstance : public GraphicsInstance
	{
	public:
		VulkanInstance(const VulkanInstanceDesc* pDesc);
		~VulkanInstance();

		FORCEINLINE VkInstance GetVkInstance() const noexcept
		{
			return mInstance;
		}
	private:
		VkInstance mInstance;
#ifdef Portakal_DEBUG
		VkDebugUtilsMessengerEXT mDebugMessenger;
#endif
	};
}
