#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GraphicsAdapter;
	struct RUNTIME_API GraphicsDeviceDesc
	{
		SharedHeap<GraphicsAdapter> Adapter;
	};
}
