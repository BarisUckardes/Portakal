#pragma once
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Texture/TextureLoadResult.h>

namespace Portakal
{
	class RUNTIME_API TextureLoader final
	{
	public:
		static bool LoadFromPath(const String& path, TextureLoadResult& resultOut);
	public:
		TextureLoader() = delete;
		~TextureLoader() = delete;
	};
}
