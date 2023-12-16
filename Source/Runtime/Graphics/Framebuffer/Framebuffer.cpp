#include "Framebuffer.h"

namespace Portakal
{
	Framebuffer::Framebuffer(const FramebufferDesc& desc) : mColorAttachments(desc.ColorAttachments),mDepthStencilAttachment(desc.DepthStencilAttachment),mSize(desc.Size)
	{

	}
}
