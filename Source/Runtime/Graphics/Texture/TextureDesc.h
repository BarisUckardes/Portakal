#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Vector3.h>
#include <Runtime/Graphics/Texture/TextureSampleCount.h>
#include <Runtime/Graphics/Texture/TextureType.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Graphics/Texture/TextureUsage.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>

namespace Portakal
{
	struct RUNTIME_API TextureDesc
	{
		TextureType Type;
		TextureUsage Usage;
		TextureFormat Format;
		Vector3US Size;
		byte MipLevels;
		byte ArrayLevels;
		TextureSampleCount SampleCount;
		SharedHeap<GraphicsMemoryHeap> pHeap;
	};
}
