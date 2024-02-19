#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Graphics/Texture/TextureSampleCount.h>
#include <Runtime/Graphics/Texture/TextureType.h>
#include <Runtime/Graphics/Texture/TextureUsage.h>
#include <Runtime/Graphics/Memory/GraphicsMemory.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{

	struct RUNTIME_API TextureDesc
	{
		TextureType Type;
		TextureUsage Usages;
		TextureFormat Format;
		UInt32 Width;
		UInt32 Height;
		UInt32 Depth;
		Byte ArrayLevels;
		Byte MipLevels;
		TextureSampleCount SampleCount;
		SharedHeap<GraphicsMemory> pMemory;
	};
}
