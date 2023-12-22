#include "D3DCommandPool.h"

namespace Portakal
{
	D3DCommandPool::D3DCommandPool(const CommandPoolDesc& desc, D3DDevice* pDevice) : CommandPool(desc)
	{
		D3D12_COMMAND_LIST_TYPE type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		switch (desc.Type)
		{
		case CommandPoolType::Graphics:
			type = D3D12_COMMAND_LIST_TYPE_DIRECT;
			break;
		case CommandPoolType::Compute:
			type = D3D12_COMMAND_LIST_TYPE_COMPUTE;
			break;
		case CommandPoolType::Transfer:
			type = D3D12_COMMAND_LIST_TYPE_COPY;
			break;
		}

		pDevice->GetDevice()->CreateCommandAllocator(type, IID_PPV_ARGS(&mAllocator));
	}
	void D3DCommandPool::OnShutdown()
	{
	}
}
