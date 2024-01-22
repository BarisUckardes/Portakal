#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>

namespace Portakal
{
	struct RUNTIME_API SubMeshResource
	{
		SharedHeap<GraphicsBuffer> pVertexBuffer;
		SharedHeap<GraphicsBuffer> pIndexBuffer;
		SharedHeap<GraphicsBuffer> pVertexStageBuffer;
		SharedHeap<GraphicsBuffer> pIndexStageBuffer;

	};
}
