#include "DescriptorPool.h"

namespace Portakal
{
	DescriptorPool::~DescriptorPool()
	{

	}
	DescriptorPool::DescriptorPool(const DescriptorPoolDesc& desc, GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mSetCount(desc.SetCount),mSizes(desc.Sizes),mType(desc.Type)
	{

	}
}
