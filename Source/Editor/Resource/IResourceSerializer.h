#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include "IResourceSerializer.reflected.h"

namespace Portakal
{
	class DomainFile;

	PCLASS(Virtual);
	class EDITOR_API IResourceSerializer : public Object
	{
		GENERATE_OBJECT;
	public:
		IResourceSerializer() = default;
		~IResourceSerializer() = default;

		virtual void Serialize(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) = 0;
		virtual void SerializeOptimized(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) = 0;
	};
}




















































































































