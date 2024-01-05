#include "ResourceSubObject.h"

namespace Portakal
{
	void ResourceSubObject::_SetOwnerResource(const SharedHeap<Resource>& pResource)
	{
		mOwnerResource = pResource;
	}
}
