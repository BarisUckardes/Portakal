#include "FontLoader.h"

#include <Runtime/Platform/PlatformFile.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

namespace Portakal
{
	Bool8 FontLoader::LoadFromPath(const String& path, TextureLoadResult& resultOut)
	{
		String fontData;
		if (!PlatformFile::Read(path, fontData))
		{
			PORTAKAL_LOG(PE_ERROR, "Failed to read font file");
			return false;
		}

		Byte* fontDataPtr = (Byte*)fontData.GetSource();
		// Initialize the font info structure
		stbtt_fontinfo font;
		if (!stbtt_InitFont(&font, fontDataPtr, stbtt_GetFontOffsetForIndex(fontDataPtr, 0)))
		{
			PORTAKAL_LOG(PE_ERROR, "Failed to initialize font info structure");
			return false;
		}

		// Set the scale factor
		float scale = stbtt_ScaleForPixelHeight(&font, 16);

		// Compute the bounding box for a character
		int x0, y0, x1, y1;
		stbtt_GetCodepointBitmapBox(&font, 'A', scale, scale, &x0, &y0, &x1, &y1);

		// Allocate a bitmap large enough to hold the character
		unsigned char* bitmap = (unsigned char*)malloc((x1 - x0) * (y1 - y0));

		// Render the character into the bitmap
		int width = x1 - x0;
		int height = y1 - y0;
		int stride = width;
		stbtt_MakeCodepointBitmap(&font, bitmap, width, height, stride, scale, scale, 'A');

		// Take data from bitmap and put it into the texture
		resultOut.Size = { (UInt16)width,(UInt16)height };
		resultOut.pView = new MemoryOwnedView(bitmap, width * height * 4);

		free(bitmap);

		return true;
	}
}
