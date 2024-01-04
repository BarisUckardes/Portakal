#pragma once
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanMemoryHeap : public GraphicsMemoryHeap
	{
	public:
		VulkanMemoryHeap(const GraphicsMemoryHeapDesc& desc, VulkanDevice* pDevice);
		~VulkanMemoryHeap() = default;

		FORCEINLINE VkDeviceMemory GetVkMemory() const noexcept
		{
			return mMemory;
		}
	private:
		VkDeviceMemory mMemory;
		VkDevice mLogicalDevice;

		// Inherited via GraphicsMemoryHeap
		void OnShutdown() override;
		MemoryHandle AllocateCore(const Uint64 offsetInBytes) override;
	};
}
