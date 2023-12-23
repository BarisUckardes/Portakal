#pragma once

#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class RUNTIME_API D3DAdapter : public GraphicsAdapter
	{
	public:
		D3DAdapter(const GraphicsAdapterDesc& desc, ComPtr<IDXGIAdapter1> pAdapter) : GraphicsAdapter(desc), mAdapter(pAdapter)
		{
		}
		~D3DAdapter() = default;

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