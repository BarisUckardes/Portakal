#include "DirectXInstance.h"

#include <Runtime/DirectX12/Adapter/DirectXAdapter.h>

namespace Portakal
{
	DirectXInstance::DirectXInstance(const GraphicsInstanceDesc& desc) : GraphicsInstance(desc)
	{
#ifdef PORTAKAL_DEBUG
		DEV_ASSERT(SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&mDebugController))), "DirectXInstance", " Failed to get Debug Interface");
		mDebugController->EnableDebugLayer();
#endif

		// Create Factory
		DEV_ASSERT(SUCCEEDED(CreateDXGIFactory1(IID_PPV_ARGS(&mFactory))), "DirectXInstance", "Failed to create factory");

		// Find all the adapters in the system
		ComPtr<IDXGIAdapter1> adapter;
		for (UINT i = 0; mFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC1 desc;
			adapter->GetDesc1(&desc);

			GraphicsAdapterDesc adapterDesc = {};
		}
	}
	void DirectXInstance::OnShutdown()
	{
	}
}
