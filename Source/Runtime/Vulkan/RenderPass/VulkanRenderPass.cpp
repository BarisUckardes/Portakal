#include "VulkanRenderPass.h"
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Texture/VulkanTexture.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPassUtils.h>
#include <Runtime/Vulkan/Memory/VulkanMemoryUtils.h>
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>

namespace Portakal
{
	VulkanRenderPass::VulkanRenderPass(const RenderPassDesc& desc, VulkanDevice* pDevice) : RenderPass(desc),mLogicalDevice(pDevice->GetVkLogicalDevice()),mRenderPass(VK_NULL_HANDLE)
	{
		//Create color attachment descs
		const byte colorAttachmentCount = desc.ColorAttachments.GetSize();
		const bool bHasDepthStencilAttachment = !desc.DepthStencilAttachment.pTexture.IsShutdown();
		Array<VkAttachmentDescription> attachments(colorAttachmentCount + bHasDepthStencilAttachment);
		for (byte i = 0; i < attachments.GetSize(); i++)
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

		//Create attachment references
		Array<VkAttachmentReference> references(attachments.GetSize());
		for (byte i = 0; i < references.GetSize(); i++)
		{
			VkAttachmentReference reference = {};
			reference.attachment = i;
			reference.layout = (i == references.GetSize() - 1 && !desc.DepthStencilAttachment.pTexture.IsShutdown()) ? VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL : VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
			references[i] = reference;
		}

		//Create sub passes
		VkAttachmentReference colorAttachmentsReferences[16];
		VkAttachmentReference inputAttachmentReferences[16];
		VkAttachmentReference multiSampleAttachmentReferences[16];
		uint32 preserveAttachmentReferences[16];

		Array<VkSubpassDescription> subpasses;
		for (const RenderPassSubpassDesc& subpassDesc : desc.Subpasses)
		{
			VkSubpassDescription subpass = {};
			subpass.pipelineBindPoint = subpassDesc.BindPoint == PipelineBindPoint::Graphics ? VK_PIPELINE_BIND_POINT_GRAPHICS : VK_PIPELINE_BIND_POINT_COMPUTE;
			subpass.preserveAttachmentCount = subpassDesc.MultisampleInputs.GetSize();
			subpass.colorAttachmentCount = colorAttachmentCount;
			subpass.inputAttachmentCount = subpassDesc.Inputs.GetSize();
			subpass.pColorAttachments = colorAttachmentsReferences;
			subpass.pInputAttachments = inputAttachmentReferences;
			subpass.pResolveAttachments = multiSampleAttachmentReferences;
			subpass.pPreserveAttachments = preserveAttachmentReferences;
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

		DEV_ASSERT(vkCreateRenderPass(mLogicalDevice, &info, nullptr, &mRenderPass),"VulkanRenderPass","Failed to create render pass!");

	}
	void VulkanRenderPass::OnShutdown()
	{
		vkDestroyRenderPass(mLogicalDevice, mRenderPass, nullptr);
	}
}
