#pragma once

namespace Portakal
{
	struct RUNTIME_API BufferTextureCopyDesc
	{
		UInt64 BufferOffsetInBytes;
		UInt32 TextureOffsetX;
		UInt32 TextureOffsetY;
		UInt32 TextureOffsetZ;
		UInt32 Width;
		UInt32 Height;
		UInt32 Depth;
		Byte TargetArrayIndex;
		Byte TargetMipIndex;
	};
}
