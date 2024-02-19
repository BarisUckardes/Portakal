#pragma once
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Graphics/Sampler/SamplerFiltering.h>

namespace Portakal
{
	struct RUNTIME_API TextureCopyDesc
	{
		TextureAspectFlags SourceAspect;
		UInt32 SourceOffsetX;
		UInt32 SourceOffsetY;
		UInt32 SourceOffsetZ;
		Byte SourceArrayIndex;
		Byte SourceMipIndex;

		TextureAspectFlags DestinationAspect;
		UInt32 DestinationOffsetX;
		UInt32 DestinationOffsetY;
		UInt32 DestinationOffsetZ;
		Byte DestinationArrayIndex;
		Byte DestinationMipIndex;

		SamplerFiltering Filtering;
	};
}
