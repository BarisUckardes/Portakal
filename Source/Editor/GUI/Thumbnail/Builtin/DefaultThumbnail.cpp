#include "DefaultThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void DefaultThumbnail::OnInitialize()
	{

	}
	SharedHeap<TextureResource> DefaultThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//Get sub object
		SharedHeap<TextureResource> pTexture = pFile->GetSubObject().QueryAs<TextureResource>();
		return pTexture.IsShutdown() ? EditorResourceAPI::GetResource("DefaultIcon").QueryAs<EditorTextureResource>()->GetTexture() : pTexture;
	}
}
