#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryAccessFlags.h>
#include <Runtime/Graphics/Queue/GraphicsQueueType.h>

namespace Portakal
{
	/**
	 * @class BufferBarrierDesc
	 * 
	 * @brief A multihread spin lock barrier ? My guess is that it is being 
	 * used to lock a certain amount of data in a buffer while it is being used by a thread.
	 * 
	 * @throw At least give me a fuckin clue to understand.
	 */
	struct RUNTIME_API BufferBarrierDesc
	{
		PipelineStageFlags SourceStageFlags;
		GraphicsMemoryAccessFlags SourceAccessFlags;
		GraphicsQueueType SourceQueueFamily;
		PipelineStageFlags DestinationStageFlags;
		GraphicsMemoryAccessFlags DestinationAccessFlags;
		GraphicsQueueType DestinationQueueFamily;
		uint64 OffsetInBytes;
		uint64 SizeInBytes;
	};
}
