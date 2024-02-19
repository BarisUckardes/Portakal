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
		~VulkanBuffer() = default;

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
		virtual void OnShutdown() override;
	private:
		VkDevice mLogicalDevice;
		VkBuffer mBuffer;
		UInt64 mMemoryOffset;
		UInt64 mMemoryAlignedOffset;
	};
}
