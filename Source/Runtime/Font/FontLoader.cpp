#include "FontLoader.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <Runtime/Font/FontBuffer.h>

namespace Portakal
{
	SharedHeap<FontBuffer> FontLoader::LoadFromPath(const String& path)
	{
		FT_Library library;

		DEV_ASSERT(!FT_Init_FreeType(&library), "FontLoader", "Failed to initialize FreeType library!");

		FT_Face face;

		DEV_ASSERT(!FT_New_Face(library, path.GetSource(), 0, &face), "FontLoader", "Failed to load font from path: %s", path.GetSource());

		FT_Set_Pixel_Sizes(face, 0, 48);

		FT_Bitmap bitmap = face->glyph->bitmap;

		SharedHeap<FontBuffer> fontBuffer;
		FontBufferDesc fontBufferDesc;

		//TODO: Fill fontBufferDesc and create FontBuffer

		return fontBuffer;
	}
}
