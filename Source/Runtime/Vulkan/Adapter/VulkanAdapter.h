#pragma once
#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanAdapter : public GraphicsAdapter
	{
	public:
		VulkanAdapter(const GraphicsAdapterDesc& desc, const VkPhysicalDevice device) : GraphicsAdapter(desc), mDevice(device)
		{

		}
		~VulkanAdapter() = default;

		FORCEINLINE VkPhysicalDevice GetVkPhysicalDevice() const noexcept
		{
			return mDevice;
		}
		virtual void OnShutdown() override;
	private:
		// Inherited via GraphicsAdapter
		GraphicsDevice* CreateDeviceCore() override;
	private:
		VkPhysicalDevice mDevice;
	};
}
