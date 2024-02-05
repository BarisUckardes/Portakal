#pragma once
#include <Runtime/Resource/Mesh/MeshResource.h>
#include <Runtime/Resource/IResourceDeserializer.h>
#include "MeshDeserializer.reflected.h"

namespace Portakal
{

	/// <summary>
	/// Deserializer for mesh resource sub object
	/// </summary>
	PATTRIBUTE(CustomResourceDeserializer, "mesh")
	PCLASS();
	class RUNTIME_API MeshDeserializer : public IResourceDeserializer
	{
	public:
		MeshDeserializer() = default;
		~MeshDeserializer() = default;

		virtual ResourceSubObject* Deserialize(const MemoryView& view, const String& metaData) override;
		virtual ResourceSubObject* DeserializeOptimized(const MemoryView& view, const String& metaData) override;
	};
}

