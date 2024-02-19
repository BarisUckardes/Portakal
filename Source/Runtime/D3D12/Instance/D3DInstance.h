#pragma once

#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	/**
	 * @class D3DInstance
	 * @brief VkInstance is kinda acceptable for equivalent of DirectX Factory.
	 */
	class RUNTIME_API D3DInstance : public GraphicsInstance
	{
	public:
		D3DInstance(const GraphicsInstanceDesc& desc);
		~D3DInstance() = default;

		FORCEINLINE ComPtr<IDXGIFactory4> GetFactory() const noexcept
		{
			return mFactory;
		}

	protected:
		// Inherited via GraphicsInstance
		virtual void OnShutdown() override;
	private:
		ComPtr<IDXGIFactory4> mFactory;

#ifdef PORTAKAL_DEBUG
		ComPtr<ID3D12Debug6> mD3D12Debug;
		ComPtr<IDXGIDebug1> mDXGIDebug;
#endif
	};
}
