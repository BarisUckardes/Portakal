#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include "ResourceSubObject.reflected.h"

namespace Portakal
{
	class Resource;
	PCLASS(Virtual);
	class ResourceSubObject : public Object
	{
		GENERATE_OBJECT;
		friend class Resource;
	public:
		ResourceSubObject() = default;
		~ResourceSubObject() = default;

		FORCEINLINE SharedHeap<Resource> GetOwnerResource() const noexcept
		{
			return mOwnerResource;
		}
		FORCEINLINE bool IsVirtual() const noexcept
		{
			return mOwnerResource.GetHeap() == nullptr;
		}
	private:
		void _SetOwnerResource(const SharedHeap<Resource>& pResource);
	private:
		SharedHeap<Resource> mOwnerResource;
	};
}































































































