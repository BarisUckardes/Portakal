#pragma once
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Queue/GraphicsQueueType.h>

namespace Portakal
{
	struct RUNTIME_API BufferMemoryBarrierDesc
	{
		UInt64 OffsetInBytes;
		UInt64 SizeInBytes;

		PipelineStageFlags SourceStageFlags;
		GraphicsMemoryAccessFlags SourceAccessFlags;
		GraphicsQueueType SourceQueue;

		PipelineStageFlags DestinationStageFlags;
		GraphicsMemoryAccessFlags DestinationAccessFlags;
		GraphicsQueueType DestinationQueue;

	};
}
