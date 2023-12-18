#pragma once
#include <Runtime/Math/Vector2.h>
#include <Runtime/Math/Vector3.h>

namespace Portakal
{
	/**
	 * @struct BufferTextureCopyDescriptor
	 *
	 * @brief It is used to update a texture from another buffer or (vice versa?).
	 */
	struct RUNTIME_API BufferTextureCopyDesc
	{
		uint64 BufferOffsetInBytes;
		Vector3UI TextureOffsetInPixels;
		Vector3UI TextureSize;
		byte TextureMipIndex;
		byte TextureArrayIndex;
	};
}
