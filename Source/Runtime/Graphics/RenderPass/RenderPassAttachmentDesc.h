#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/RenderPass/RenderPassLoadOperation.h>
#include <Runtime/Graphics/RenderPass/RenderPassStoreOperation.h>
#include <Runtime/Graphics/Texture/TextureMemoryLayout.h>
#include <Runtime/Graphics/Texture/TextureView.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Graphics/Texture/TextureSampleCount.h>


namespace Portakal
{
	struct RUNTIME_API RenderPassAttachmentDesc
	{
		SharedHeap<Texture> pTexture;
		SharedHeap<TextureView> pView;
		TextureFormat Format;
		TextureSampleCount SampleCount;
		RenderPassLoadOperation ColorLoadOperation;
		RenderPassStoreOperation ColorStoreOperation;
		RenderPassLoadOperation StencilLoadOperation;
		RenderPassStoreOperation StencilStoreOperation;
		TextureMemoryLayout InputLayout;
		TextureMemoryLayout OutputLayout;
		Byte MipLevel;
		Byte ArrayLevel;

	};
}
