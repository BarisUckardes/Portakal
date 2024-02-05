#include "RenderTarget.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	RenderTarget::RenderTarget()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}
	//void RenderTarget::Create(const Array<SharedHeap<Texture>>& colorTargets, const Array<SharedHeap<TextureView>>& colorViews)
	//{
	//	//First check if shutdown
	//	if (IsShutdown())
	//		return;

	//	//Check the graphics device
	//	if (mDevice.IsShutdown())
	//		return;

	//	//Delete the former setup
	//	Delete();

	//	//Create render pass desc with basic informations
	//	RenderPassDesc renderPassDesc = {};
	//	renderPassDesc.bSwapchain = colorTargets[0]->IsSwapchain();
	//	renderPassDesc.Size = { colorTargets[0]->GetSize().X,colorTargets[0]->GetSize().Y};

	//	//Get color attachments
	//	for (const SharedHeap<Texture>& pTexture : colorTargets)
	//	{
	//		RenderPassAttachmentDesc desc = {};
	//		desc.ArrayLevel = 0;
	//		desc.MipLevel = 0;
	//		desc.ColorLoadOperation = RenderPassLoadOperation::Clear;
	//		desc.ColorStoreOperation = RenderPassStoreOperation::Store;
	//		desc.InputLayout = TextureMemoryLayout::Present;
	//		desc.OutputLayout = TextureMemoryLayout::Present;
	//		desc.pTexture = pTexture;
	//		desc.StencilLoadOperation = RenderPassLoadOperation::Clear;
	//		desc.StencilStoreOperation = RenderPassStoreOperation::Store;
	//		renderPassDesc.ColorAttachments.Add(desc);
	//	}

	//	//Get attachment views
	//	for (const SharedHeap<TextureView>& pView : colorViews)
	//	{
	//		renderPassDesc.AttachmentViews.Add(pView);
	//	}

	//	//Create subpass
	//	RenderPassSubpassDesc subpassDesc = {};
	//	subpassDesc.BindPoint = PipelineBindPoint::Graphics;
	//	subpassDesc.DepthStencilInput = 0;
	//	renderPassDesc.Subpasses.Add(subpassDesc);

	//	//Create render pass
	//	renderPassDesc.Dependencies = {};
	//	mRenderPass = mDevice->CreateRenderPass(renderPassDesc);

	//	//Set properties
	//	mColorTargets = colorTargets;
	//	mDepthStencilTarget = {};
	//}
	void RenderTarget::Create(const RenderPassDesc& desc)
	{
		//First check if shutdown
		if (IsShutdown())
			return;

		//Check the graphics device
		if (mDevice.IsShutdown())
			return;

		//Delete the former setup
		Delete();

		//Create render pass
		mRenderPass = mDevice->CreateRenderPass(desc);

		//Set properties
		for (const RenderPassAttachmentDesc& attachment : desc.ColorAttachments)
			mColorTargets.Add(attachment.pTexture);

		mDepthStencilTarget = desc.DepthStencilAttachment.pTexture;
	}
	void RenderTarget::Delete()
	{
		mRenderPass.Shutdown();
		mColorTargets.Clear();
		mDepthStencilTarget.Deference();
	}
	void RenderTarget::OnShutdown()
	{
		Delete();
	}
}
