#include "D3DInstance.h"
#include <Runtime/D3D12/Adapter/D3DAdapter.h>

namespace Portakal
{
	D3DInstance::D3DInstance(const GraphicsInstanceDesc& desc) : GraphicsInstance(desc)
	{
#ifdef PORTAKAL_DEBUG
		DEV_ASSERT(SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&mD3D12Debug))), "DirectXInstance", " Failed to get Debug Interface");
		mD3D12Debug->EnableDebugLayer();

		DEV_ASSERT(SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&mDXGIDebug))), "DirectXInstance", "Failed to get DXGI Debug Interface");
		mDXGIDebug->EnableLeakTrackingForThread();

		// Enable GPU-Based Validation
		ComPtr<ID3D12Debug1> debug1;
		if (SUCCEEDED(mD3D12Debug.As(&debug1)))
		{
			debug1->SetEnableGPUBasedValidation(true);
		}
#endif

		// Create Factory
		DEV_ASSERT(SUCCEEDED(CreateDXGIFactory1(IID_PPV_ARGS(mFactory.GetAddressOf()))), "DirectXInstance", "Failed to create factory");

		// Find all the adapters in the system
		Array<SharedHeap<GraphicsAdapter>> adapters;
		ComPtr<IDXGIAdapter1> adapter;
		for (UINT i = 0; mFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC1 dxAdapterDesc;
			adapter->GetDesc1(&dxAdapterDesc);

			DEV_LOG("DirectXInstance", "Adapter found: %s" , String(dxAdapterDesc.Description).GetSource());
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
#ifdef PORTAKAL_DEBUG
		mDXGIDebug->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL);
#endif
	}
}