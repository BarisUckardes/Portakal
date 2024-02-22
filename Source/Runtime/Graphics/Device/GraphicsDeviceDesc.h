#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>
#include <Runtime/Graphics/Device/GraphicsDeviceFeatures.h>

namespace Portakal
{
	class GraphicsAdapter;
	struct RUNTIME_API GraphicsDeviceDesc
	{
		GraphicsAdapter* pAdapter;
		GraphicsDeviceFeatures* pRequestedFeatures;
		Byte GraphicsQueueCount;
		Byte ComputeQueueCount;
		Byte TransferQueueCount;
	};
}
