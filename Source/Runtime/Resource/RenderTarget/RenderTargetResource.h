#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include "RenderTargetResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API RenderTargetResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
		RenderTargetResource(const SharedHeap<GraphicsDevice>& pDevice);
		RenderTargetResource();
		~RenderTargetResource() = default;

		FORCEINLINE Array<SharedHeap<Texture>> GetColorTargets() const noexcept
		{
			return mColorTargets;
		}
		FORCEINLINE SharedHeap<Texture> GetDepthStencilTarget() const noexcept
		{
			return mDepthStencilTarget;
		}
		FORCEINLINE SharedHeap<RenderPass> GetRenderPass() const noexcept
		{
			return mRenderPass;
		}
		FORCEINLINE Vector2US GetRenderRegionSize() const noexcept
		{
			return mRenderRegionSize;
		}

		void Create(const RenderPassDesc& desc);
	private:
		void Delete();
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		Array<SharedHeap<Texture>> mColorTargets;
		SharedHeap<Texture> mDepthStencilTarget;
		SharedHeap<RenderPass> mRenderPass;
		Vector2US mRenderRegionSize;
	};
}





























































































