#include "TextureLoader.h"
#include <stb_image.h>

namespace Portakal
{
	Bool8 TextureLoader::LoadFromPath(const String& path, TextureLoadResult& resultOut)
	{
		/*int width = 0;
		int height = 0;
		int channels = 0;
		Byte* pData = stbi_load(*path, &width, &height, &channels, 4);
		if (pData == nullptr)
		{
			DEV_LOG("TextureLoader", "Failed to load the texture");
			return false;
		}

		resultOut.Size = { (Uint16)width,(Uint16)height };
		resultOut.pView = new MemoryOwnedView(pData, width * height * 4);*/

		return true;
	}
}
