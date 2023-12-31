#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Vector3.h>
#include <Runtime/Graphics/Texture/TextureAspectFlags.h>
#include <Runtime/Graphics/Sampler/SamplerFiltering.h>

namespace Portakal
{
	/**
	 * @struct TextureCopyDesc
	 *
	 * @brief It is used to update a texture from another texture.
	 */
	struct RUNTIME_API TextureCopyDesc
	{
		Vector3UI SourceOffset;
		TextureAspectFlags SourceAspectFlags;
		byte SourceArrayIndex;
		byte SourceMipIndex;

		Vector3UI DestinationOffset;
		TextureAspectFlags DestinationAspectFlags;
		byte DestinationArrayIndex;
		byte DestinationMipIndex;

		SamplerFiltering Filtering;
	};
}
