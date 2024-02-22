#include "GraphicsAPI.h"

namespace Portakal
{
	void GraphicsAPI::SetMemoryBudget(const UInt64 deviceMemorySize, const UInt64 hostMemorySize)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(!pAPI->mDevice.IsShutdown(), "GraphicsAPI", "Cannot set memory profile without creating a graphics device first!");

		GraphicsMemoryDesc deviceHeapDesc = {};
		deviceHeapDesc.SizeInBytes = deviceMemorySize;
		deviceHeapDesc.Type = GraphicsMemoryType::Device;
		pAPI->mHeapDevice = pAPI->mDevice->CreateMemoryHeap(deviceHeapDesc);

		GraphicsMemoryDesc hostHeapDesc = {};
		hostHeapDesc.SizeInBytes = hostMemorySize;
		hostHeapDesc.Type = GraphicsMemoryType::Host;
		pAPI->mHeapHost = pAPI->mDevice->CreateMemoryHeap(hostHeapDesc);
	}
	void GraphicsAPI::SetResourceBudget(const UInt64 resourceCount, const UInt64 setCount)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(!pAPI->mDevice.IsShutdown(), "GraphicsAPI", "Cannot set memory profile without creating a graphics device first!");

		DescriptorSetPoolDesc desc = {};
		desc.Entries =
		{
			{DescriptorResourceType::Sampler,resourceCount},
			{DescriptorResourceType::ConstantBuffer,resourceCount},
			{DescriptorResourceType::SampledTexture,resourceCount},
			{DescriptorResourceType::StorageBuffer,resourceCount},
			{DescriptorResourceType::StorageTexture,resourceCount}
		};
		desc.MaxTables = setCount;
		pAPI->mTablePool = pAPI->mDevice->CreateDescriptorSetPool(desc);
	}
	SharedHeap<GraphicsDevice> GraphicsAPI::GetDefaultDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mDevice;
	}

	SharedHeap<GraphicsMemory> GraphicsAPI::GetDefaultDeviceHeap()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mHeapDevice;
	}

	SharedHeap<GraphicsMemory> GraphicsAPI::GetDefaultHostHeap()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mHeapHost;
	}
	SharedHeap<DescriptorSetPool> GraphicsAPI::GetDefaultTablePool()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mTablePool;
	}

	SharedHeap<GraphicsQueue> GraphicsAPI::GetDefaultGraphicsQueue()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mGraphicsQueue;
	}

	SharedHeap<GraphicsQueue> GraphicsAPI::GetDefaultComputeQueue()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mComputeQueue;
	}

	SharedHeap<GraphicsQueue> GraphicsAPI::GetDefaultTransferQueue()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mTransferQueue;
	}
	
	void GraphicsAPI::_SetDevice(const SharedHeap<GraphicsDevice>& pDevice)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(pAPI->mDevice.IsShutdown(), "GraphicsAPI", "Cannot have more than one graphics device!");

		pAPI->mDevice = pDevice;
		pAPI->mGraphicsQueue = pDevice->RentQueue({ GraphicsQueueFamilyType::Graphics });
		pAPI->mComputeQueue = pDevice->RentQueue({ GraphicsQueueFamilyType::Compute });
		pAPI->mTransferQueue = pDevice->RentQueue({ GraphicsQueueFamilyType::Transfer });
	}
	void GraphicsAPI::_RemoveDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mDevice = nullptr;
	}
}
