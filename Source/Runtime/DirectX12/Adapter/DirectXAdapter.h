#pragma once

#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>

#include <Runtime/DirectX12/DXIncludes.h>

namespace Portakal
{
	class RUNTIME_API DirectXAdapter : public GraphicsAdapter
	{
	public:
		DirectXAdapter(const GraphicsAdapterDesc& desc, ComPtr<IDXGIAdapter1> pAdapter) : GraphicsAdapter(desc), mAdapter(pAdapter)
		{
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
