#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Memory/SharedHeap.h>
#include "TextureResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API TextureResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	private:
		struct MipData
		{
			SharedHeap<TextureView> pView;
			SharedHeap<GraphicsBuffer> pStageBuffer;
		};
	public:
		TextureResource(const SharedHeap<GraphicsDevice>& pDevice);
		TextureResource();
		~TextureResource() = default;

		FORCEINLINE SharedHeap<Texture> GetTexture() const noexcept
		{
			return mTexture;
		}
		FORCEINLINE const TextureDesc& GetDesc() const noexcept
		{
			return mDesc;
		}
		void AllocateTexture(const TextureDesc& desc, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const bool bAllocateStagebuffersUpfront = false,const bool bCreateViewsUpfront = false);
		SharedHeap<TextureView> CreateView(const byte mipLevel, const byte arrayLevel);
		SharedHeap<TextureView> GetView(const byte mipLevel, const byte arrayLevel);
		void Update(const MemoryView& memory,const Vector3US offset,const TextureMemoryLayout inputMemoryLayout,const GraphicsMemoryAccessFlags inputAccessFlags,const PipelineStageFlags inputPipelineFlags,const GraphicsQueueType inputQueueType,const byte mipLevel,const byte arrayLevel);
	private:
		void CreateInternalResources();
		void Clear();
		virtual void OnShutdown() override;
	private:
		Array<Array<MipData>> mData;
		SharedHeap<Texture> mTexture;
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<CommandList> mCmdList;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<Fence> mFence;
		SharedHeap<GraphicsMemoryHeap> mHostHeap;
		TextureDesc mDesc;
	};
}









































