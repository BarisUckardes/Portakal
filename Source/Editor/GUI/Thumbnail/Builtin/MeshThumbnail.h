#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "MeshThumbnail.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomThumbnail, "mesh");
	PCLASS();
	class EDITOR_API MeshThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		MeshThumbnail() = default;
		~MeshThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	};
}


