#pragma once
#include <Runtime/Graphics/RenderPass/RenderPassAttachmentDesc.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API RenderPassDesc
	{
		UInt32 TargetRenderWidth;
		UInt32 TargetRenderHeight;
		Array<RenderPassAttachmentDesc> ColorAttachments;
		RenderPassAttachmentDesc* pDepthStencilAttachment;
	};
}
