#pragma once

#include <Runtime/Graphics/Command/CommandPool.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;
	class RUNTIME_API D3DCommandPool : public CommandPool
	{
	public:
		D3DCommandPool(const CommandPoolDesc& desc, D3DDevice* pDevice);
		~D3DCommandPool() = default;

		FORCEINLINE ComPtr<ID3D12CommandAllocator> GetAllocator() const noexcept
		{
			return mAllocator;
		}

		FORCEINLINE D3D12_COMMAND_LIST_TYPE GetType() const noexcept
		{
			return mType;
		}

		virtual void OnShutdown() override;

	private:
		ComPtr<ID3D12CommandAllocator> mAllocator;
		D3D12_COMMAND_LIST_TYPE mType;
	};
}
