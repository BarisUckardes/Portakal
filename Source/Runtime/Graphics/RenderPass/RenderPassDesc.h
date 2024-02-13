#pragma once
#include <Runtime/Graphics/RenderPass/RenderPassAttachmentDesc.h>
#include <Runtime/Graphics/RenderPass/RenderPassSubpassDesc.h>
#include <Runtime/Graphics/RenderPass/RenderPassSubpassDependencyDesc.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Graphics/Texture/TextureView.h>

namespace Portakal
{

	struct RUNTIME_API RenderPassDesc
	{
		Vector2US Size;
		Array<RenderPassAttachmentDesc> ColorAttachments;
		RenderPassAttachmentDesc DepthStencilAttachment;
		Array<RenderPassSubpassDesc> Subpasses;
		Array<RenderPassSubpassDependencyDesc> Dependencies;
		Array<SharedHeap<TextureView>> AttachmentViews;
	};
}
