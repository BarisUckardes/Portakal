#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Math/Vector2F.h>

#include <Runtime/Font/FontPixelMode.h>
#include <Runtime/Font/FontThickness.h>
#include <Runtime/Font/FontStyle.h>

namespace Portakal
{
	struct RUNTIME_API FontBufferDesc
	{
		UInt32 Rows;
		UInt32 Width;
		Int32 Pitch;
		Byte* Buffer;
		UInt32 StandardPixelSize;

		FontPixelMode PixelMode;
		FontThickness Thickness;
		FontStyle Style;
	};

}
