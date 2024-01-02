#include "TextureDeserializer.h"
#include <Runtime/Resource/Texture/TextureResource.h>

namespace Portakal
{
	ResourceSubObject* TextureDeserializer::Deserialize(const MemoryView& view)
	{
		//Create texture
		TextureResource* pTexture = new TextureResource();

		//pTexture->AllocateTexture();

		//pTexture->UpdateTexture();

		return pTexture;
	}
	ResourceSubObject* TextureDeserializer::DeserializeOptimized(const MemoryView& view)
	{
		//Create texture
		TextureResource* pTexture = new TextureResource();

		//pTexture->AllocateTexture();

		//pTexture->UpdateTexture();

		return pTexture;
	}
}
