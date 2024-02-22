#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/RenderPass/RenderPassDesc.h>
#include <Runtime/Graphics/Texture/Texture.h>

namespace Portakal
{
	class RUNTIME_API RenderPass : public GraphicsDeviceObject
	{
	public:
		RenderPass(const RenderPassDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mColorAttachments(desc.ColorAttachments), mSize(desc.Size)
		{

		}
		~RenderPass() = default;

		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::RenderPass;
		}
		FORCEINLINE Vector2US GetRenderRegion() const noexcept
		{
			return mSize;
		}
	private:
		const Array<RenderPassAttachmentDesc> mColorAttachments;
		const Vector2US mSize;
	};
}
