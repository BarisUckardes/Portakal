#include "GraphicsAPI.h"

namespace Portakal
{
	void GraphicsAPI::SetMemoryBudget(const UInt64 deviceMemorySize, const UInt64 hostMemorySize)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(pAPI->mDevice.IsAlive(), "GraphicsAPI", "Cannot set memory profile without creating a graphics device first!");

		GraphicsMemoryHeapDesc deviceHeapDesc = {};
		deviceHeapDesc.SizeInBytes = deviceMemorySize;
		deviceHeapDesc.Type = GraphicsMemoryType::Device;
		pAPI->mHeapDevice = pAPI->mDevice->CreateMemoryHeap(deviceHeapDesc);

		GraphicsMemoryHeapDesc hostHeapDesc = {};
		hostHeapDesc.SizeInBytes = hostMemorySize;
		hostHeapDesc.Type = GraphicsMemoryType::Host;
		pAPI->mHeapHost = pAPI->mDevice->CreateMemoryHeap(hostHeapDesc);
	}
	void GraphicsAPI::SetResourceBudget(const UInt64 resourceCount, const UInt64 setCount)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(pAPI->mDevice.IsAlive(), "GraphicsAPI", "Cannot set memory profile without creating a graphics device first!");

		ResourceTablePoolDesc desc = {};
		desc.Entries =
		{
			{GraphicsResourceType::Sampler,resourceCount},
			{GraphicsResourceType::ConstantBuffer,resourceCount},
			{GraphicsResourceType::SampledTexture,resourceCount},
			{GraphicsResourceType::StorageBuffer,resourceCount},
			{GraphicsResourceType::StorageTexture,resourceCount}
		};
		desc.MaxTables = setCount;
		pAPI->mTablePool = pAPI->mDevice->CreateResourceTablePool(desc);
	}
	SharedHeap<GraphicsDevice> GraphicsAPI::GetDefaultDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mDevice;
	}

	SharedHeap<GraphicsMemoryHeap> GraphicsAPI::GetDefaultDeviceHeap()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mHeapDevice;
	}

	SharedHeap<GraphicsMemoryHeap> GraphicsAPI::GetDefaultHostHeap()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mHeapHost;
	}
	SharedHeap<ResourceTablePool> GraphicsAPI::GetDefaultTablePool()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mTablePool;
	}
	
	void GraphicsAPI::_SetDevice(const SharedHeap<GraphicsDevice>& pDevice)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(pAPI->mDevice.IsShutdown(), "GraphicsAPI", "Cannot have more than one graphics device!");

		pAPI->mDevice = pDevice;
	}
	void GraphicsAPI::_RemoveDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mDevice = nullptr;
	}
}
