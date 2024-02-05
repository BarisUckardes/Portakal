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
		virtual void OnShutdown() override;
	private:
		VkDevice mLogicalDevice;
		VkBuffer mBuffer;
	};
}
