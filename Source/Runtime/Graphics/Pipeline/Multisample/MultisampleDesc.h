#pragma once
#include <Runtime/Graphics/Texture/TextureSampleCount.h>

namespace Portakal
{
    struct RUNTIME_API MultisampleDesc
    {
        bool bSampleShadingEnabled;
        TextureSampleCount Samples;
    };
}
