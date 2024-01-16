#pragma once
#include <Runtime/Resource/IResourceDeserializer.h>
#include "ShaderDeserializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceDeserializer, "shader");
	PCLASS();
	class RUNTIME_API ShaderDeserializer : public IResourceDeserializer
	{
		GENERATE_OBJECT;
	public:
		ShaderDeserializer() = default;
		~ShaderDeserializer() = default;

		virtual ResourceSubObject* Deserialize(const MemoryView& view,const String& metaData) override;
		virtual ResourceSubObject* DeserializeOptimized(const MemoryView& view,const String& metaData) override;
	};
}

