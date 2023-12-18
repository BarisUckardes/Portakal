#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>

namespace Portakal
{
    struct RUNTIME_API OutputMergerDesc
    {
        Array<TextureFormat> ColorFormats;
        TextureFormat DepthStencilFormat;
    };
}
