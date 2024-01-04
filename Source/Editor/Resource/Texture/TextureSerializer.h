#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Editor/Resource/ResourceSerializerAttribute.h>
#include "TextureSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(ResourceSerializerAttribute, "texture");
	PCLASS();
	class EDITOR_API TextureSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		TextureSerializer() = default;
		~TextureSerializer() = default;

		// Inherited via IResourceSerializer
		void OnShutdown() override;
		void Serialize(const Object* pObject, MemoryOwnedView** ppView) override;
		void SerializeOptimized(const Object* pObject, MemoryOwnedView** ppView) override;
	};
}
































