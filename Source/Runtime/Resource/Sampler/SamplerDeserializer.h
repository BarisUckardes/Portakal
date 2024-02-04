#pragma once
#include <Runtime/Resource/Sampler/SamplerResource.h>
#include <Runtime/Resource/Sampler/SamplerDescriptor.h>
#include <Runtime/Resource/IResourceDeserializer.h>
#include "SamplerDeserializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceDeserializer, "sampler");
	PCLASS();
	class RUNTIME_API SamplerDeserializer : public IResourceDeserializer
	{
		GENERATE_OBJECT;
	public:
		SamplerDeserializer() = default;
		~SamplerDeserializer() = default;

		virtual ResourceSubObject* Deserialize(const MemoryView& view, const String& metaData) override;
		virtual ResourceSubObject* DeserializeOptimized(const MemoryView& view, const String& metaData) override;
	};
}


