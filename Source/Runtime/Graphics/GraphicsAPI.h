#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Object/API.h>
#include <Runtime/Containers/HashMap.h>

namespace Portakal
{
	class RUNTIME_API GraphicsAPI : public API<GraphicsAPI>
	{
		friend class GraphicsDevice;
		friend class GraphicsAdapter;
	public:
		static void SetMemoryBudget(const UInt64 deviceMemorySize, const UInt64 hostMemorySize);
		static void SetResourceBudget(const UInt64 resourceCount,const UInt64 setCount);
		static SharedHeap<GraphicsDevice> GetDefaultDevice();
		static SharedHeap<GraphicsMemoryHeap> GetDefaultDeviceHeap();
		static SharedHeap<GraphicsMemoryHeap> GetDefaultHostHeap();
		static SharedHeap<ResourceTablePool> GetDefaultTablePool();
	private:
		static void _SetDevice(const SharedHeap<GraphicsDevice>& pDevice);
		static void _RemoveDevice();
	public:
		GraphicsAPI() = default;
		~GraphicsAPI() = default;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<GraphicsMemoryHeap> mHeapDevice;
		SharedHeap<GraphicsMemoryHeap> mHeapHost;
		SharedHeap<ResourceTablePool> mTablePool;
	};
}
