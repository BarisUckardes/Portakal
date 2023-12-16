#pragma once
#include <Runtime/Graphics/Framebuffer/FramebufferAttachmentDesc.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Math/Vector2.h>

namespace Portakal
{
	struct RUNTIME_API FramebufferDesc
	{
		Vector2US Size;
		Array<FramebufferAttachmentDesc> ColorAttachments;
		FramebufferAttachmentDesc DepthStencilAttachment;
	};
}
