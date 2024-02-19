#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/RenderPass/RenderPassDesc.h>
#include <Runtime/Graphics/Texture/Texture.h>

namespace Portakal
{
	class RUNTIME_API RenderPass : public GraphicsDeviceObject
	{
	public:
		~RenderPass() = default;

		FORCEINLINE const Array<RenderPassAttachmentDesc>& GetColorAttachments() const noexcept
		{
			return mAttachments;
		}

		
		FORCEINLINE UInt32 GetRenderWidth() const noexcept
		{
			return mTargetRenderWidth;
		}
		FORCEINLINE UInt32 GetRenderHeight() const noexcept
		{
			return mTargetRenderHeight;
		}
		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::RenderPass;
		}
	protected:
		RenderPass(const RenderPassDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),
			mAttachments(desc.ColorAttachments),mTargetRenderWidth(desc.TargetRenderWidth),mTargetRenderHeight(desc.TargetRenderHeight)
		{

		}
	private:
		const Array<RenderPassAttachmentDesc> mAttachments;
		const UInt32 mTargetRenderWidth;
		const UInt32 mTargetRenderHeight;;
	};
}
