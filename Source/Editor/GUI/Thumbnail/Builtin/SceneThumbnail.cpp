#include "SceneThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void SceneThumbnail::OnInitialize()
	{

	}
	SharedHeap<TextureResource> SceneThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//Get sub object
		SharedHeap<TextureResource> pTexture = pFile->GetSubObject().QueryAs<TextureResource>();
		return pTexture.IsShutdown() ? EditorResourceAPI::GetResource("SceneIcon").QueryAs<EditorTextureResource>()->GetTexture() : pTexture;
	}
}
