#include "TextureLoader.h"
#include <stb_image.h>

namespace Portakal
{
	bool TextureLoader::LoadFromPath(const String& path, TextureLoadResult& resultOut)
	{
		/*int width = 0;
		int height = 0;
		int channels = 0;
		byte* pData = stbi_load(*path, &width, &height, &channels, 4);
		if (pData == nullptr)
		{
			DEV_LOG("TextureLoader", "Failed to load the texture");
			return false;
		}

		resultOut.Size = { (uint16)width,(uint16)height };
		resultOut.pView = new MemoryOwnedView(pData, width * height * 4);*/

		return true;
	}
}
