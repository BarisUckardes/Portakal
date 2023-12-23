#include "D3DCommandPool.h"

namespace Portakal
{
	D3DCommandPool::D3DCommandPool(const CommandPoolDesc& desc, D3DDevice* pDevice) : CommandPool(desc)
	{
		switch (desc.Type)
		{
		case CommandPoolType::Graphics:
			mType = D3D12_COMMAND_LIST_TYPE_DIRECT;
			break;
		case CommandPoolType::Compute:
			mType = D3D12_COMMAND_LIST_TYPE_COMPUTE;
			break;
		case CommandPoolType::Transfer:
			mType = D3D12_COMMAND_LIST_TYPE_COPY;
			break;
		}

		DEV_ASSERT(SUCCEEDED(pDevice->GetDevice()->CreateCommandAllocator(mType, IID_PPV_ARGS(&mAllocator))), "D3DCommandPool", "Failed to create command pool/allocator");
	}

	void D3DCommandPool::OnShutdown()
	{
	}
}
