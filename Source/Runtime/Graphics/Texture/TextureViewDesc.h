#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class Texture;
	struct RUNTIME_API TextureViewDesc
	{
		byte MipLevel;
		byte ArrayLevel;
		SharedHeap<Texture> pTexture;
	};
}
