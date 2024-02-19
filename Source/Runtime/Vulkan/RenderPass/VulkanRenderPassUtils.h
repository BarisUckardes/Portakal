#pragma once
#include <Runtime/Graphics/RenderPass/RenderPassDesc.h>
#include <vulkan.h>

namespace Portakal
{
	class RUNTIME_API VulkanRenderPassUtils
	{
	public:
		static VkAttachmentLoadOp GetLoadOperation( RenderPassLoadOperation op)
		{
			switch (op)
			{
			default:
			case Portakal::RenderPassLoadOperation::Ignore:
				return VK_ATTACHMENT_LOAD_OP_DONT_CARE;
			case Portakal::RenderPassLoadOperation::Load:
				return VK_ATTACHMENT_LOAD_OP_LOAD;
			case Portakal::RenderPassLoadOperation::Clear:
				return VK_ATTACHMENT_LOAD_OP_CLEAR;
			}
		}
		static VkAttachmentStoreOp GetStoreOperation( RenderPassStoreOperation op)
		{
			switch (op)
			{
			case Portakal::RenderPassStoreOperation::Store:
				return VK_ATTACHMENT_STORE_OP_STORE;
			case Portakal::RenderPassStoreOperation::Ignore:
			default:
				return VK_ATTACHMENT_STORE_OP_DONT_CARE;
			}
		}
	public:
		VulkanRenderPassUtils() = delete;
		~VulkanRenderPassUtils() = delete;
	};
}
