#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Texture/TextureMemoryLayout.h>
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>
#include <Runtime/Graphics/Queue/GraphicsQueueType.h>

namespace Portakal
{
	struct RUNTIME_API CommandListTextureMemoryBarrierDesc
	{
		TextureMemoryLayout SourceLayout;
		TextureMemoryLayout DestinationLayout;
		TextureAspectFlags AspectFlags;
		Byte MipIndex;
		Byte ArrayIndex;
		GraphicsMemoryAccessFlags SourceAccessFlags;
		GraphicsMemoryAccessFlags DestinationAccessFlags;
		PipelineStageFlags SourceStageFlags;
		PipelineStageFlags DestinationStageFlags;
		GraphicsQueueType SourceQueue;
		GraphicsQueueType DestinationQueue;
	};
}
