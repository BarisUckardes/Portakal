#pragma once

#include <Runtime/Graphics/Resource/ResourceTablePool.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;
	class RUNTIME_API D3DResourcePool : public ResourceTablePool
	{
		D3DResourcePool(const ResourceTablePoolDesc& desc, D3DDevice* pDevice);
		~D3DResourcePool() override = default;
	private:
		D3D12_DESCRIPTOR_RANGE mRange;
	};
}
