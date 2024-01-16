#include "TextureThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void TextureThumbnail::OnInitialize()
	{

	}
	SharedHeap<TextureResource> TextureThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//First make sure it's loaded
		pFile->LoadSync();

		//Get sub object
		SharedHeap<TextureResource> pTexture = pFile->GetSubObject().QueryAs<TextureResource>();
		return pTexture.IsShutdown() ? EditorResourceAPI::GetResource("DefaultIcon").QueryAs<EditorTextureResource>()->GetTexture() : pTexture;
	}
}
