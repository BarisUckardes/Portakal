#pragma once
#include <Editor/GUI/Thumbnail/IThumbnail.h>
#include "ShaderThumbnail.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomThumbnail, "shader");
	PCLASS();
	class EDITOR_API ShaderThumbnail : public IThumbnail
	{
		GENERATE_OBJECT;
	public:
		ShaderThumbnail() = default;
		~ShaderThumbnail() = default;

		virtual void OnInitialize() override;
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile) override;
	};
}
