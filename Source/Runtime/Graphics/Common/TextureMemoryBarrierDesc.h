#pragma once
#include <Runtime/Graphics/Texture/TextureMemoryLayout.h>
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Queue/GraphicsQueueFamilyType.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>

namespace Portakal
{
	struct RUNTIME_API TextureMemoryBarrierDesc
	{
		TextureAspectFlags AspectFlags;
		Byte ArrayIndex;
		Byte MipIndex;

		TextureMemoryLayout SourceLayout;
		GraphicsMemoryAccessFlags SourceAccessFlags;
		PipelineStageFlags SourceStageFlags;
		GraphicsQueueFamilyType SourceQueue;

		TextureMemoryLayout DestinationLayout;
		GraphicsMemoryAccessFlags DestinationAccessFlags;
		PipelineStageFlags DestinationStageFlags;
		GraphicsQueueFamilyType DestinationQueue;
	};
}
