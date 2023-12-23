#include "D3DDevice.h"

#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/D3D12/Swapchain/D3DSwapchain.h>
#include <Runtime/D3D12/Command/D3DCommandList.h>
#include <Runtime/D3D12/Command/D3DCommandPool.h>
#include <Runtime/D3D12/Fence/D3DFence.h>

namespace Portakal
{
	D3DDevice::D3DDevice(const GraphicsDeviceDesc& desc) : GraphicsDevice(desc), mAdapter(((const D3DAdapter*)desc.pAdapter)->GetAdapter())
	{
		DEV_SYSTEM(SUCCEEDED(D3D12CreateDevice(mAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&mDevice))), "D3DDevice", "Failed to create D3DDevice", 
				   "ID3D12Device has been created successfully.");
	}
	CommandList* D3DDevice::CreateCommandListCore(const CommandListDesc& desc)
	{
		return new D3DCommandList(desc, this);
	}
	CommandPool* D3DDevice::CreateCommandPoolCore(const CommandPoolDesc& desc)
	{
		return new D3DCommandPool(desc, this);
	}
	Fence* D3DDevice::CreateFenceCore()
	{
		return new D3DFence(this);
	}
	Swapchain* D3DDevice::CreateSwapchainCore(const SwapchainDesc& desc)
	{
		return new D3DSwapchain(desc, this);
	}
}