#pragma once
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Reflection/Reflection.h>
#include "IResourceDeserializer.reflected.h"

namespace Portakal
{
	class ResourceSubObject;

	PCLASS(Virtual);
	class RUNTIME_API IResourceDeserializer : public Class
	{
		GENERATE_OBJECT;
	public:
		IResourceDeserializer() = default;
		~IResourceDeserializer() = default;

		virtual ResourceSubObject* Deserialize(const MemoryView& view) = 0;
		virtual ResourceSubObject* DeserializeOptimized(const MemoryView& view) = 0;
	};
}








