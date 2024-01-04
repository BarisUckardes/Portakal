#pragma once
#include <Runtime/Math/Vector2.h>
#include <Runtime/Math/Vector3.h>

namespace Portakal
{
	/**
	 * @class BufferTextureCopyDesc
	 *
	 * @brief It is used to update a texture from another buffer or (vice versa?).
	 */
	struct RUNTIME_API BufferTextureCopyDesc
	{
		UInt64 BufferOffsetInBytes;
		Vector3US TextureOffsetInPixels;
		Vector3US TextureSize;
		Byte TextureMipIndex;
		Byte TextureArrayIndex;
	};
}
