#include "SamplerDeserializer.h"
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Runtime/World/Component/InvalidComponent.h>

namespace Portakal
{
	ResourceSubObject* SamplerDeserializer::Deserialize(const MemoryView& view, const String& metaData)
	{
		SamplerResource* pSampler = new SamplerResource();

		return pSampler;
	}
	ResourceSubObject* SamplerDeserializer::DeserializeOptimized(const MemoryView& view, const String& metaData)
	{
		return nullptr;
	}
}
