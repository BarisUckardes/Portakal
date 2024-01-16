#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "TextureThumbnail.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomThumbnail, "texture");
	PCLASS();
	class EDITOR_API TextureThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		TextureThumbnail() = default;
		~TextureThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	};
}


