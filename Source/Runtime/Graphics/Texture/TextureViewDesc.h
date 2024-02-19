#pragma once
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	struct RUNTIME_API TextureViewDesc
	{
		TextureAspectFlags AspectFlags;
		Byte MipLevel;
		Byte ArrayLevel;
		SharedHeap<Texture> pTexture;
	};
}
