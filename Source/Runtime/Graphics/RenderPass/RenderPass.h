#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/RenderPass/RenderPassDesc.h>

namespace Portakal
{
	class RUNTIME_API RenderPass : public GraphicsDeviceObject
	{
	public:
		RenderPass(const RenderPassDesc& desc) : mColorAttachments(desc.ColorAttachments), mDepthStencilAttachment(desc.DepthStencilAttachment), mSubpasses(desc.Subpasses), mDependencies(desc.Dependencies), mSize(desc.Size),mSwapchain(desc.bSwapchain)
		{

		}
		~RenderPass() = default;

		FORCEINLINE bool IsSwapchain() const noexcept
		{
			return mSwapchain;
		}
		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::RenderPass;
		}
	private:
		const Array<RenderPassAttachmentDesc> mColorAttachments;
		const RenderPassAttachmentDesc mDepthStencilAttachment;
		const Array<RenderPassSubpassDesc> mSubpasses;
		const Array<RenderPassSubpassDependencyDesc> mDependencies;
		const Vector2US mSize;
		const bool mSwapchain;
	};
}
