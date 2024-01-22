#include "MeshThumbnail.h"
#include <Editor/Resource/EditorResourceAPI.h>
#include <Editor/Resource/EditorTextureResource.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	void MeshThumbnail::OnInitialize()
	{

	}
	SharedHeap<TextureResource> MeshThumbnail::GetThumbnailTexture(DomainFile* pFile)
	{
		//Get sub object
		return EditorResourceAPI::GetResource("MeshIcon").QueryAs<EditorTextureResource>()->GetTexture();
	}
}
