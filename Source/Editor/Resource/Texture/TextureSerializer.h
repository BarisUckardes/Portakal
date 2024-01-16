#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Editor/Resource/CustomResourceSerializer.h>
#include "TextureSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceSerializer, "texture",STRARRAY(".png",".jpg"));
	PCLASS();
	class EDITOR_API TextureSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		TextureSerializer() = default;
		~TextureSerializer() = default;

		// Inherited via IResourceSerializer
		void OnShutdown() override;
		void Serialize(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) override;
		void SerializeOptimized(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) override;
	};
}
