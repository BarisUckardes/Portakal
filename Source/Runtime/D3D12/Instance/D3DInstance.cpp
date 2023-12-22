#include "D3DInstance.h"
#include <Runtime/D3D12/Adapter/D3DAdapter.h>

namespace Portakal
{
	D3DInstance::D3DInstance(const GraphicsInstanceDesc& desc) : GraphicsInstance(desc)
	{
#ifdef PORTAKAL_DEBUG
		DEV_ASSERT(SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&mDebugController))), "DirectXInstance", " Failed to get Debug Interface");
		mDebugController->EnableDebugLayer();
#endif

		// Create Factory
		DEV_ASSERT(SUCCEEDED(CreateDXGIFactory1(IID_PPV_ARGS(&mFactory))), "DirectXInstance", "Failed to create factory");

		// Find all the adapters in the system
		Array<SharedHeap<GraphicsAdapter>> adapters;
		ComPtr<IDXGIAdapter1> adapter;
		for (UINT i = 0; mFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC1 dxAdapterDesc;
			adapter->GetDesc1(&dxAdapterDesc);

			GraphicsAdapterDesc adapterDesc = {};
			adapterDesc.ProductName = dxAdapterDesc.Description;
			adapterDesc.VRam = dxAdapterDesc.DedicatedVideoMemory;
			adapterDesc.pInstance = this;

			adapters.Add(new D3DAdapter(adapterDesc, adapter));
		}

		SetAdapters(adapters);
	}
	void D3DInstance::OnShutdown()
	{
	}
}