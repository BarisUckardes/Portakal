#include "DirectXDevice.h"
#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/Adapter/DirectXAdapter.h>
#include <Runtime/DirectX12/Swapchain/DirectXSwapchain.h>
namespace Portakal
{
	DirectXDevice::DirectXDevice(const GraphicsDeviceDesc& desc) : GraphicsDevice(desc), mAdapter(((const DirectXAdapter*)desc.pAdapter)->GetAdapter())
	{
		DEV_SYSTEM(SUCCEEDED(D3D12CreateDevice(mAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&mDevice))), "DirectXDevice", "Failed to create DirectXDevice", 
				   "ID3D12Device has been created successfully.");
	}
	Swapchain* DirectXDevice::CreateSwapchainCore(const SwapchainDesc& desc)
	{
		return new DirectXSwapchain(desc, this);
	}
}
#endif