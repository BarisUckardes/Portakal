#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceFeatures.h>
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GraphicsAdapter;
	struct RUNTIME_API GraphicsDeviceDesc
	{
		GraphicsDeviceDesc() : GraphicsQueueCount(0),ComputeQueueCount(0),TransferQueueCount(0)
		{

		}

		GraphicsAdapter* pOwnerAdapter;
		GraphicsDeviceFeatures* pRequestedFeatures;
		Byte GraphicsQueueCount;
		Byte ComputeQueueCount;
		Byte TransferQueueCount;
	};
}
