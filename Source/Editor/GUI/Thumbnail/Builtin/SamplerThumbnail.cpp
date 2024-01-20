#include "SamplerThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void SamplerThumbnail::OnInitialize()
	{
		
	}
	SharedHeap<TextureResource> SamplerThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//Get sub object
		SharedHeap<TextureResource> pTexture = pFile->GetSubObject().QueryAs<TextureResource>();
		return pTexture.IsShutdown() ? EditorResourceAPI::GetResource("SamplerIcon").QueryAs<EditorTextureResource>()->GetTexture() : pTexture;
	}
}
