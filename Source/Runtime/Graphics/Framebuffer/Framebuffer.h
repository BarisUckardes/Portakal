#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Framebuffer/FramebufferDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API Framebuffer : public GraphicsDeviceObject
	{
	public:
		Framebuffer(const FramebufferDesc& desc);
		~Framebuffer() = default;

		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE Array<FramebufferAttachmentDesc> GetColorAttachments() const noexcept
		{
			return mColorAttachments;
		}
		FORCEINLINE FramebufferAttachmentDesc GetDepthStencilAttachment() const noexcept
		{
			return mDepthStencilAttachment;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Framebuffer;
		}
	private:
		const Array<FramebufferAttachmentDesc> mColorAttachments;
		const FramebufferAttachmentDesc mDepthStencilAttachment;
		Vector2US mSize;
	};
}
