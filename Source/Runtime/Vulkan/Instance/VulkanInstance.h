#pragma once
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanInstance : public GraphicsInstance
	{
	public:
	private:
		static PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
		static PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
	public:
		VulkanInstance(const GraphicsInstanceDesc& desc);
		~VulkanInstance() = delete;

	private:
		VkInstance mInstance;
		Array<const char*> mEnabledValidationLayers;
#ifdef PORTAKAL_DEBUG
		VkDebugUtilsMessengerEXT mDebugMessenger;
#endif

		// Inherited via GraphicsInstance
		virtual void OnShutdown() override;
	};
}