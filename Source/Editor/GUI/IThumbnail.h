#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Editor/GUI/CustomThumbnail.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include "IThumbnail.reflected.h"

namespace Portakal
{
	class DomainFile;
	PCLASS();
	class IThumbnail : public Object
	{
		GENERATE_OBJECT;
	public:
		IThumbnail() = default;
		~IThumbnail() = default;

		virtual void OnInitialize()
		{

		}
		virtual SharedHeap<TextureResource> GetThumbnailTexture(DomainFile* pFile)
		{
			return nullptr;
		}

	};
}

