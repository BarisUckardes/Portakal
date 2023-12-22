#pragma once

#include <Runtime/Graphics/Command/CommandPool.h>

#include <Runtime/D3D12/D3DIncludes.h>
#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	class RUNTIME_API D3DCommandPool : public CommandPool
	{
	public:
		D3DCommandPool(const CommandPoolDesc& desc, D3DDevice* pDevice);
		~D3DCommandPool() = default;

		virtual void OnShutdown() override;

	private:
		ComPtr<ID3D12CommandAllocator> mAllocator;
	};
}
