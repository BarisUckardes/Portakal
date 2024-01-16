#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "SceneThumbnail.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomThumbnail,"scene")
	PCLASS();
	class EDITOR_API SceneThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		SceneThumbnail() = default;
		~SceneThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	private:
	};
}

