#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Resource/Scene/SceneResource.h>
#include "SceneSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceSerializer, "scene",STRARRAY(".pscene"));
	PCLASS();
	class EDITOR_API SceneSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		SceneSerializer() = default;
		~SceneSerializer() = default;

	private:
		// Inherited via IResourceSerializer
		void Serialize(const Object* pObject, MemoryOwnedView** ppView) override;
		void SerializeOptimized(const Object* pObject, MemoryOwnedView** ppView) override;
	};
}

