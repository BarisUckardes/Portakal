#pragma once

#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/DXIncludes.h>

namespace Portakal
{
	class RUNTIME_API DirectXAdapter : public GraphicsAdapter
	{
	public:
		DirectXAdapter(const GraphicsAdapterDesc& desc, ComPtr<IDXGIAdapter1> pAdapter) : GraphicsAdapter(desc), mAdapter(pAdapter)
		{
			DXGI_ADAPTER_DESC1 desc1;
			mAdapter->GetDesc1(&desc1);

			DEV_LOG("GraphicsAdapter", "Adapter Data Stored For: %s", String(desc1.Description).GetSource());
		}
		~DirectXAdapter() = default;

		FORCEINLINE ComPtr<IDXGIAdapter1> GetAdapter() const noexcept
		{
			return mAdapter;
		}

	protected:
		// Inherited via GraphicsAdapter
		virtual GraphicsDevice* CreateDeviceCore() override;
		
		virtual void OnShutdown() override;
	private:
		ComPtr<IDXGIAdapter1> mAdapter;
	};
}
#endif