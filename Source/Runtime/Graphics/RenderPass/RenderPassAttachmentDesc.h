#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/RenderPass/RenderPassLoadOperation.h>
#include <Runtime/Graphics/RenderPass/RenderPassStoreOperation.h>
#include <Runtime/Graphics/Texture/TextureMemoryLayout.h>

namespace Portakal
{
	class Texture;
	struct RUNTIME_API RenderPassAttachmentDesc
	{
		SharedHeap<Texture> pTexture;
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
