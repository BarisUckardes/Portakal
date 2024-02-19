#include "DescriptorSetLayout.h"

namespace Portakal
{
	DescriptorSetLayout::~DescriptorSetLayout()
	{

	}
	DescriptorSetLayout::DescriptorSetLayout(const DescriptorSetLayoutDesc& desc, GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mEntries(desc.Entries)
	{

	}
}
