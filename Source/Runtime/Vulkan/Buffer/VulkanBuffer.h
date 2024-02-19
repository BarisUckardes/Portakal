#pragma once
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanBuffer : public GraphicsBuffer
	{
	public:
		VulkanBuffer(const GraphicsBufferDesc& desc, VulkanDevice* pDevice);
		~VulkanBuffer();

		FORCEINLINE VkBuffer GetVkBuffer() const noexcept
		{
			return mBuffer;
		}
		FORCEINLINE UInt64 GetVkMemoryOffset() const noexcept
		{
			return mMemoryOffset;
		}
		FORCEINLINE UInt64 GetVkMemoryAlignedOffset() const noexcept
		{
			return mMemoryAlignedOffset;
		}
	private:
		VkBuffer mBuffer;
		VkDevice mLogicalDevice;
		UInt64 mMemoryOffset;
		UInt64 mMemoryAlignedOffset;
	};
}
