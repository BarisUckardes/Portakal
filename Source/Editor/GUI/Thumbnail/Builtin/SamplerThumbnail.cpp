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
		return EditorResourceAPI::GetResource("SamplerIcon").QueryAs<EditorTextureResource>()->GetTexture();
	}
}
