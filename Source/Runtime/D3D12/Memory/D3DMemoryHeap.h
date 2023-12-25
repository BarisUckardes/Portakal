#pragma once
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>

#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>

#include <Runtime/D3D12/D3DIncludes.h>
#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	class RUNTIME_API D3DMemoryHeap : public GraphicsMemoryHeap
	{
	public:
		D3DMemoryHeap(const GraphicsMemoryHeapDesc& desc, D3DDevice* pInstance);
		~D3DMemoryHeap() override = default;

	private:
	};
}
