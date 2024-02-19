#include "DescriptorSet.h"

namespace Portakal
{
	DescriptorSet::~DescriptorSet()
	{
	}
	DescriptorSet::DescriptorSet(const DescriptorSetDesc& desc, GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mPool(desc.pPool),mLayout(desc.pLayout)
	{

	}
}
