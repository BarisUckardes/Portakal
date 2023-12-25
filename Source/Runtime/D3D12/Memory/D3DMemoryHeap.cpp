#include "D3DMemoryHeap.h"

#include <Runtime/D3D12/Memory/D3DMemoryUtils.h>

namespace Portakal
{
	D3DMemoryHeap::D3DMemoryHeap(const GraphicsMemoryHeapDesc& desc, D3DDevice* pInstance) : GraphicsMemoryHeap(desc)
	{

		D3D12_HEAP_DESC heapDesc = {};
		heapDesc.SizeInBytes = desc.SizeInBytes;
		heapDesc.Alignment = 0;
		heapDesc.Properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
		heapDesc.Properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
		heapDesc.Properties.Type = D3DMemoryUtils::GetMemoryHeapType(desc.Type);
		heapDesc.Properties.CreationNodeMask = 1;
		heapDesc.Properties.VisibleNodeMask = 1;
		heapDesc.Flags = D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS;

		pInstance->GetD3DDevice()->CreateHeap(&heapDesc, IID_PPV_ARGS(&mMemoryHeap));
	}
}
