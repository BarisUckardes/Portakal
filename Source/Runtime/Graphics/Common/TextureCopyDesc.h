#pragma once
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Graphics/Sampler/SamplerFiltering.h>
#include <Runtime/Math/Vector3.h>

namespace Portakal
{
	struct RUNTIME_API TextureCopyDesc
	{
		TextureAspectFlags SourceAspect;
		Vector3UI SourceOffset;
		Byte SourceArrayIndex;
		Byte SourceMipIndex;

		TextureAspectFlags DestinationAspect;
		Vector3UI DestinationOffset;
		Byte DestinationArrayIndex;
		Byte DestinationMipIndex;

		SamplerFiltering Filtering;
	};
}
