#pragma once
#include <Runtime/Math/Vector2.h>

namespace Portakal
{
    /**
     * @class ScissorDesc
     * 
     * @brief It is used to define the rendered area in that specified 
     * viewport. Helps us to prevent unnecessary rendering.
     */
    struct RUNTIME_API ScissorDesc
    {
        Vector2UI SizeInPixels;
        Vector2UI OffsetInPixels;
    };
}
