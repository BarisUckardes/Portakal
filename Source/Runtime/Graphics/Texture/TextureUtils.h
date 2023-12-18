#pragma once
#include <Runtime/Core/Core.h>
#include "Runtime/Graphics/Texture/TextureFormat.h"

namespace Portakal
{
    class RUNTIME_API TextureUtils
    {
    public:
        TextureUtils() = delete;
        ~TextureUtils() = delete;

        static byte GetFormatSize(const TextureFormat format);
    };
}
