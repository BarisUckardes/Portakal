#include "TextureLoader.h"

#include <stb_image.h>

namespace Portakal
{
	Bool8 TextureLoader::LoadFromPath(const String& path, TextureLoadResult& resultOut)
	{
		int width = 0;
		int height = 0;
		int channels = 0;
		Byte* pData = stbi_load(*path, &width, &height, &channels, 4);
		if (pData == nullptr)
		{
			DEV_LOG("TextureLoader", "Failed to load the texture");
			return false;
		}

		resultOut.Size = { (UInt16)width,(UInt16)height };
		resultOut.pView = new MemoryOwnedView(pData, width * height * 4);

		stbi_image_free(pData);
		return true;
	}
	Bool8 TextureLoader::LoadFromMemory(const MemoryView& memory,TextureLoadResult& resultOut)
	{
		int width = 0;
		int height = 0;
		int channels = 0;
		Byte* pData = stbi_load_from_memory((const stbi_uc*)memory.GetMemory(),memory.GetSize(), &width, &height, &channels, 4);
		if (pData == nullptr)
		{
			DEV_LOG("TextureLoader", "Failed to load the texture");
			return false;
		}

		resultOut.Size = { (UInt16)width,(UInt16)height };
		resultOut.pView = new MemoryOwnedView(pData, width * height * 4);

		return true;
	}
}
