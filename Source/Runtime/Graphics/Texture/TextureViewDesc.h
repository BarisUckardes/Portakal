#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class Texture;
	struct RUNTIME_API TextureViewDesc
	{
		Byte MipLevel;
		Byte ArrayLevel;
		SharedHeap<Texture> pTexture;
	};
}
