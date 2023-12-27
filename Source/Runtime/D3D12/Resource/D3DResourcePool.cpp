#include "D3DResourcePool.h"

namespace Portakal
{
	D3DResourcePool::D3DResourcePool(const ResourceTablePoolDesc& desc, D3DDevice* pDevice) : ResourceTablePool(desc)
	{
		mRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
	}
}
