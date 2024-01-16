#pragma once
#include <Runtime/Resource/IResourceDeserializer.h>
#include <Runtime/Resource/Scene/SceneResource.h>
#include "SceneDeserializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceDeserializer,"scene");
	PCLASS();
	class RUNTIME_API SceneDeserializer : public IResourceDeserializer
	{
		GENERATE_OBJECT;
	public:
		SceneDeserializer() = default;
		~SceneDeserializer() = default;

	private:
		// Inherited via IResourceDeserializer
		ResourceSubObject* Deserialize(const MemoryView& view) override;
		ResourceSubObject* DeserializeOptimized(const MemoryView& view) override;
	};
}

