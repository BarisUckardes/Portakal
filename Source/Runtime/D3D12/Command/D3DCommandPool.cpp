#include "D3DCommandPool.h"

#include <Runtime/D3D12/Command/D3DCommandUtils.h>
#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	D3DCommandPool::D3DCommandPool(const CommandPoolDesc& desc, D3DDevice* pDevice) : CommandPool(desc)
	{
		mType = D3DCommandUtils::GetCommandType(desc.Type);

		DEV_ASSERT(SUCCEEDED(pDevice->GetD3DDevice()->CreateCommandAllocator(mType, IID_PPV_ARGS(&mAllocator))), "D3DCommandPool", "Failed to create command pool/allocator");
	}

	void D3DCommandPool::OnShutdown()
	{
	}
}
