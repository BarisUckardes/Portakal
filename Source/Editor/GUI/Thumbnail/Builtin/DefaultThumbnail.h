#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "DefaultThumbnail.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API DefaultThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		DefaultThumbnail() = default;
		~DefaultThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	};
}


