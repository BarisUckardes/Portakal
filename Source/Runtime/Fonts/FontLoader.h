#pragma once
#include <Runtime/Core/Core.h>

#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Texture/TextureLoadResult.h>

namespace Portakal
{
	class RUNTIME_API FontLoader
	{
	public:
		static Bool8 LoadFromPath(const String& path, TextureLoadResult& resultOut);
	public:
		FontLoader() = delete;
		~FontLoader() = delete;
	};
}
