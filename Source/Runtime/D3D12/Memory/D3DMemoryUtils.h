#pragma once

#include <Runtime/D3D12/D3DIncludes.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryType.h>

namespace Portakal
{
	class RUNTIME_API D3DMemoryUtils
	{
	public:
		static D3D12_HEAP_TYPE GetMemoryHeapType(GraphicsMemoryType type)
		{
			switch (type)
			{
			case GraphicsMemoryType::Device:
				return D3D12_HEAP_TYPE_DEFAULT;
			case GraphicsMemoryType::Host:
				return D3D12_HEAP_TYPE_UPLOAD;
			}
		}

	private:
		D3DMemoryUtils() = delete;
		~D3DMemoryUtils() = delete;
	};
}
