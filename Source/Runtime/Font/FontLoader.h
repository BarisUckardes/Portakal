#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Texture/TextureLoadResult.h>

namespace Portakal
{
	class FontBuffer;

	class RUNTIME_API FontLoader
	{
	public:
		static SharedHeap<FontBuffer> LoadFromPath(const String& path);
	public:
		FontLoader() = delete;
		~FontLoader() = delete;
	};
}
