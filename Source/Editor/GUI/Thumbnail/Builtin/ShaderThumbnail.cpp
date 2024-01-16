#include "ShaderThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void ShaderThumbnail::OnInitialize()
	{

	}
	SharedHeap<TextureResource> ShaderThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//Get sub object
		SharedHeap<TextureResource> pTexture = pFile->GetSubObject().QueryAs<TextureResource>();
		return pTexture.IsShutdown() ? EditorResourceAPI::GetResource("ShaderIcon").QueryAs<EditorTextureResource>()->GetTexture() : pTexture;
	}
}
