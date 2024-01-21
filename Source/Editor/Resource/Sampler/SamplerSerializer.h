#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Resource/Sampler/SamplerResource.h>
#include "SamplerSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceSerializer, "sampler", STRARRAY(".psampler"));
	PCLASS();
	class EDITOR_API SamplerSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		SamplerSerializer() = default;
		~SamplerSerializer() = default;

	private:
		// Inherited via IResourceSerializer
		void OnShutdown() override;
		void Serialize(DomainFile* pFile, const Object* pObject, MemoryOwnedView** ppView) override;
		void SerializeOptimized(DomainFile* pFile, const Object* pObject, MemoryOwnedView** ppView) override;
	};
}

