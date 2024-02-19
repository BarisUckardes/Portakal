#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>

namespace Portakal
{
	class GraphicsAdapter;
	struct RUNTIME_API GraphicsDeviceDesc
	{
		GraphicsBackend Backend;
		GraphicsAdapter* pAdapter;
		Byte GraphicsQueueCount;
		Byte ComputeQueueCount;
		Byte TransferQueueCount;
	};
}
