#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class Resource;
	class ResourceSubObject : public Object
	{
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
