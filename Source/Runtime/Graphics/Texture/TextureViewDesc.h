#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
namespace Portakal
{
	struct RUNTIME_API TextureViewDesc
	{
		Byte MipLevel;
		Byte ArrayLevel;
		TextureFormat Format;
		TextureAspectFlags AspectFlags;
		SharedHeap<Texture> pTexture;
	};
}
