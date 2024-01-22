#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Resource/ResourceAttribute.h>
#include "TextureResource.reflected.h"

namespace Portakal
{
	PATTRIBUTE(ResourceAttribute, "texture");
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

		FORCEINLINE SharedHeap<GraphicsDevice> GetDevice() const noexcept
		{
			return mDevice;
		}
		FORCEINLINE SharedHeap<Texture> GetTexture() const noexcept
		{
			return mTexture;
		}
		FORCEINLINE const TextureDesc& GetDesc() const noexcept
		{
			return mDesc;
		}

		void Wrap(const SharedHeap<Texture>& pTexture);
		void SetMemoryProfile(const SharedHeap<GraphicsMemoryHeap>& pHeapDevice, const SharedHeap<GraphicsMemoryHeap>& pHeapHost);
		void AllocateTexture(const TextureDesc& desc, const Bool8 bAllocateStagebuffersUpfront = false,const Bool8 bCreateViewsUpfront = false);
		SharedHeap<TextureView> CreateView(const Byte mipLevel, const Byte arrayLevel);
		SharedHeap<TextureView> GetView(const Byte mipLevel, const Byte arrayLevel);
		void Update(const MemoryView& memory,const Vector3US offset,const TextureMemoryLayout inputMemoryLayout,const GraphicsMemoryAccessFlags inputAccessFlags,const PipelineStageFlags inputPipelineFlags,const GraphicsQueueType inputQueueType,const Byte mipLevel,const Byte arrayLevel);
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
		SharedHeap<GraphicsMemoryHeap> mHeapDevice;
		SharedHeap<GraphicsMemoryHeap> mHeapHost;
		TextureDesc mDesc;
		bool mWrapped;
	};
}





































































































































































































































































