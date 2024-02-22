#include "RenderTarget.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	RenderTarget::RenderTarget()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}
	
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
