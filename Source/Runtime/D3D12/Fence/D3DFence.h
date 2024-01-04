#pragma once

#include <Runtime/Graphics/Fence/Fence.h>

#include <Runtime/D3D12/D3DIncludes.h>
#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	class RUNTIME_API D3DFence : public Fence
	{
	public:
		D3DFence(D3DDevice* pDevice);
		~D3DFence() override = default;

		virtual void OnShutdown() override;

		FORCEINLINE ComPtr<ID3D12Fence> GetFence() const noexcept
		{
			return mFence;
		}
		
		FORCEINLINE UInt64 GetFenceValue() const noexcept
		{
			return mFenceValue;
		}
	private:
		ComPtr<ID3D12Fence> mFence;
		UInt64 mFenceValue;
	};
}
