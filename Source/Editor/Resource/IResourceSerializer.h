#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include "IResourceSerializer.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class EDITOR_API IResourceSerializer : public Object
	{
		GENERATE_OBJECT;
	public:
		IResourceSerializer() = default;
		~IResourceSerializer() = default;

		virtual void Serialize(const Object* pObject, MemoryOwnedView** ppView) = 0;
		virtual void SerializeOptimized(const Object* pObject, MemoryOwnedView** ppView) = 0;
	};
}
















































































