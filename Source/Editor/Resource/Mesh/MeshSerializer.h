#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Resource/Mesh/MeshResource.h>
#include "MeshSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceSerializer,"mesh",STRARRAY(".fbx",".obj"))
	PCLASS();
	class EDITOR_API MeshSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		MeshSerializer() = default;
		~MeshSerializer() = default;

		virtual void Serialize(DomainFile* pFile, const Object* pObject, MemoryOwnedView** ppView) override;
		virtual void SerializeOptimized(DomainFile* pFile, const Object* pObject, MemoryOwnedView** ppView) override;
	};
}

