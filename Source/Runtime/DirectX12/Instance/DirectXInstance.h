#pragma once

#include <Runtime/Graphics/Instance/GraphicsInstance.h>

#include <Runtime/DirectX12/DXIncludes.h>

namespace Portakal
{
	/**
	 * @class DirectXInstance
	 * @brief VkInstance is kinda acceptable for equivalent of DirectX Factory.
	 */
	class RUNTIME_API DirectXInstance : public GraphicsInstance
	{
	public:
		DirectXInstance(const GraphicsInstanceDesc& desc);
		~DirectXInstance() = delete;

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
		ComPtr<ID3D12Debug> mDebugController;
#endif
	};
}
