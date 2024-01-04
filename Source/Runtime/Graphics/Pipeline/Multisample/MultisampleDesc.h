#pragma once
#include <Runtime/Graphics/Texture/TextureSampleCount.h>

namespace Portakal
{
    struct RUNTIME_API MultisampleDesc
    {
        Bool8 bSampleShadingEnabled;
        TextureSampleCount Samples;
    };
}
