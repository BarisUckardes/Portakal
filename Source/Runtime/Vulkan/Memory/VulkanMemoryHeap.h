#pragma once
#include <Runtime/Graphics/Memory/GraphicsMemory.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanMemoryHeap : public GraphicsMemory
	{
	public:
		VulkanMemoryHeap(const GraphicsMemoryDesc& desc, VulkanDevice* pDevice);
		~VulkanMemoryHeap() = default;

		FORCEINLINE VkDeviceMemory GetVkMemory() const noexcept
		{
			return mMemory;
		}
	private:
		VkDeviceMemory mMemory;
		VkDevice mLogicalDevice;

		// Inherited via GraphicsMemory
		void OnShutdown() override;
	};
}
