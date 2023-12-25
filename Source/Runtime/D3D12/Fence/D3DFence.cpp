#include "D3DFence.h"

namespace Portakal
{
	D3DFence::D3DFence(D3DDevice* pDevice) : mFenceValue(0)
	{
		DEV_ASSERT(SUCCEEDED(pDevice->GetD3DDevice()->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&mFence))), "D3DFence", "Failed to create fence");
	}

	void D3DFence::OnShutdown()
	{
	}

}
