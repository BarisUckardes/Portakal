#pragma once
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Queue/GraphicsQueueFamilyType.h>

namespace Portakal
{
	struct RUNTIME_API BufferMemoryBarrierDesc
	{
		UInt64 OffsetInBytes;
		UInt64 SizeInBytes;

		PipelineStageFlags SourceStageFlags;
		GraphicsMemoryAccessFlags SourceAccessFlags;
		GraphicsQueueFamilyType SourceQueue;

		PipelineStageFlags DestinationStageFlags;
		GraphicsMemoryAccessFlags DestinationAccessFlags;
		GraphicsQueueFamilyType DestinationQueue;

	};
}
