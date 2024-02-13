#include "VulkanRenderPass.h"
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPassUtils.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryUtils.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTextureView.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>

namespace Portakal
{
	VulkanRenderPass::VulkanRenderPass(const RenderPassDesc& desc, VulkanDevice* pDevice) : RenderPass(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mRenderPass(VK_NULL_HANDLE),mFramebuffer(VK_NULL_HANDLE)
	{
		//Create color attachment descs
		const Byte colorAttachmentCount = desc.ColorAttachments.GetSize();
		const Bool8 bHasDepthStencilAttachment = !desc.DepthStencilAttachment.pTexture.IsShutdown();
		Array<VkAttachmentDescription> attachments(colorAttachmentCount + bHasDepthStencilAttachment);
		for (Byte i = 0; i < attachments.GetSize(); i++)
		{
			const RenderPassAttachmentDesc& attachmentDesc = desc.ColorAttachments[i];
			VkAttachmentDescription attachment = {};
			attachment.format = VulkanTextureUtils::GetTextureFormat(attachmentDesc.pTexture->GetFormat());
			attachment.samples = (VkSampleCountFlagBits)VulkanTextureUtils::GetSampleCount(attachmentDesc.pTexture->GetSampleCount());
			attachment.loadOp = VulkanRenderPassUtils::GetLoadOperation(attachmentDesc.ColorLoadOperation);
			attachment.storeOp = VulkanRenderPassUtils::GetStoreOperation(attachmentDesc.ColorStoreOperation);
			attachment.initialLayout = VulkanTextureUtils::GetImageLayout(attachmentDesc.InputLayout);
			attachment.finalLayout = VulkanTextureUtils::GetImageLayout(attachmentDesc.OutputLayout);
			attachment.stencilLoadOp = VulkanRenderPassUtils::GetLoadOperation(attachmentDesc.StencilLoadOperation);
			attachment.stencilStoreOp = VulkanRenderPassUtils::GetStoreOperation(attachmentDesc.StencilStoreOperation);

			attachments[i] = attachment;
		}

		//Create depth stencil attachment desc
		{
			if (!desc.DepthStencilAttachment.pTexture.IsShutdown())
			{
				VkAttachmentDescription attachment = {};
				attachment.format = VulkanTextureUtils::GetTextureFormat(desc.DepthStencilAttachment.pTexture->GetFormat());
				attachment.samples = (VkSampleCountFlagBits)VulkanTextureUtils::GetSampleCount(desc.DepthStencilAttachment.pTexture->GetSampleCount());
				attachment.loadOp = VulkanRenderPassUtils::GetLoadOperation(desc.DepthStencilAttachment.ColorLoadOperation);
				attachment.storeOp = VulkanRenderPassUtils::GetStoreOperation(desc.DepthStencilAttachment.ColorStoreOperation);
				attachment.initialLayout = VulkanTextureUtils::GetImageLayout(desc.DepthStencilAttachment.InputLayout);
				attachment.finalLayout = VulkanTextureUtils::GetImageLayout(desc.DepthStencilAttachment.OutputLayout);
				attachment.stencilLoadOp = VulkanRenderPassUtils::GetLoadOperation(desc.DepthStencilAttachment.StencilLoadOperation);
				attachment.stencilStoreOp = VulkanRenderPassUtils::GetStoreOperation(desc.DepthStencilAttachment.StencilStoreOperation);
				attachments.Add(attachment);
			}
		}

		//Create attachment references
		Array<VkAttachmentReference> references(attachments.GetSize());
		for (Byte i = 0; i < references.GetSize(); i++)
		{
			VkAttachmentReference reference = {};
			reference.attachment = i;
			reference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
			references[i] = reference;
		}

		//Create sub passes
		Array<VkSubpassDescription> subpasses;
		for (const RenderPassSubpassDesc& subpassDesc : desc.Subpasses)
		{
			VkAttachmentReference colorAttachmentsReferences[16];
			for (Byte i = 0; i < subpassDesc.Attachments.GetSize();i++)
			{
				const Byte attachmentIndex = subpassDesc.Attachments[i];
				colorAttachmentsReferences[i] = references[attachmentIndex];
			}
			VkAttachmentReference inputAttachmentReferences[16];
			for (Byte i = 0; i < subpassDesc.Inputs.GetSize(); i++)
			{
				const Byte attachmentIndex = subpassDesc.Inputs[i];
				inputAttachmentReferences[i] = references[attachmentIndex];
			}
			VkAttachmentReference multiSampleAttachmentReferences[16];
			for (Byte i = 0; i < subpassDesc.MultisampleInputs.GetSize(); i++)
			{
				const Byte attachmentIndex = subpassDesc.MultisampleInputs[i];
				multiSampleAttachmentReferences[i] = references[attachmentIndex];
			}
			UInt32 preserveAttachmentReferences[16];
			for (Byte i = 0; i < subpassDesc.PreserveAttachments.GetSize(); i++)
			{
				const Byte attachmentIndex = subpassDesc.PreserveAttachments[i];
				preserveAttachmentReferences[i] = attachmentIndex;
			}

			VkSubpassDescription subpass = {};
			subpass.pipelineBindPoint = subpassDesc.BindPoint == PipelineBindPoint::Graphics ? VK_PIPELINE_BIND_POINT_GRAPHICS : VK_PIPELINE_BIND_POINT_COMPUTE;
			subpass.preserveAttachmentCount = subpassDesc.PreserveAttachments.GetSize();;
			subpass.pPreserveAttachments = preserveAttachmentReferences;

			subpass.colorAttachmentCount = subpassDesc.Attachments.GetSize();
			subpass.pColorAttachments = colorAttachmentsReferences;

			subpass.inputAttachmentCount = subpassDesc.Inputs.GetSize();
			subpass.pInputAttachments = inputAttachmentReferences;

			subpass.pResolveAttachments = nullptr;

			subpasses.Add(subpass);
		}

		//Create dependencies
		Array<VkSubpassDependency> subpassDependencies;
		for (const RenderPassSubpassDependencyDesc& dependecyDesc : desc.Dependencies)
		{
			VkSubpassDependency subpassDependency = {};
			subpassDependency.srcSubpass = dependecyDesc.InputSubpass;
			subpassDependency.srcAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(dependecyDesc.InputAccess);
			subpassDependency.srcStageMask = VulkanPipelineUtils::GetStageFlags(dependecyDesc.InputStageFlags);
			subpassDependency.dstSubpass = dependecyDesc.OutputSubpass;
			subpassDependency.dstAccessMask = VulkanMemoryUtils::GetMemoryAccessFlags(dependecyDesc.OutputAccess);
			subpassDependency.dstStageMask = VulkanPipelineUtils::GetStageFlags(dependecyDesc.OutputStageFlags);
			subpassDependency.dependencyFlags = VkDependencyFlags();
			subpassDependencies.Add(subpassDependency);
		}

		//Create render pass
		VkRenderPassCreateInfo info = {};
		info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		info.attachmentCount = attachments.GetSize();
		info.subpassCount = subpasses.GetSize();
		info.dependencyCount = subpassDependencies.GetSize();;
		info.flags = VkRenderPassCreateFlags();
		info.pAttachments = attachments.GetData();
		info.pSubpasses = subpasses.GetData();
		info.pDependencies = subpassDependencies.GetData();;
		info.pNext = nullptr;

		DEV_ASSERT(vkCreateRenderPass(mLogicalDevice, &info, nullptr, &mRenderPass) == VK_SUCCESS, "VulkanRenderPass", "Failed to create render pass!");

		//Create framebuffer
		VkImageView imageViews[8] = {};
		for (Byte i = 0; i < desc.AttachmentViews.GetSize(); i++)
		{
			const VulkanTextureView* pView = (const VulkanTextureView*)desc.AttachmentViews[i].GetHeap();
			imageViews[i] = pView->GetVkImageView();
		}

		VkFramebufferCreateInfo framebufferInfo = {};
		framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		framebufferInfo.width = desc.Size.X;
		framebufferInfo.height = desc.Size.Y;
		framebufferInfo.renderPass = mRenderPass;
		framebufferInfo.layers = 1;
		framebufferInfo.attachmentCount = desc.ColorAttachments.GetSize();
		framebufferInfo.pAttachments = imageViews;
		framebufferInfo.flags = VkFramebufferCreateFlags();
		framebufferInfo.pNext = nullptr;

		DEV_ASSERT(vkCreateFramebuffer(mLogicalDevice, &framebufferInfo, nullptr, &mFramebuffer) == VK_SUCCESS, "VulkanRenderPass", "Failed to create normal framebuffer!");
	}
	void VulkanRenderPass::OnShutdown()
	{
		//Clear frame buffers first
		vkDestroyFramebuffer(mLogicalDevice, mFramebuffer, nullptr);
		vkDestroyRenderPass(mLogicalDevice, mRenderPass, nullptr);
	}
}
