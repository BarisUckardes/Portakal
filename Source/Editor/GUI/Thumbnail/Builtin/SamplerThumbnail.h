#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "SamplerThumbnail.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomThumbnail, "sampler");
	PCLASS();
	class EDITOR_API SamplerThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		SamplerThumbnail() = default;
		~SamplerThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	private:
	};
}
