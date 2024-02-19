#pragma
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API InputElementSemantic : Byte
    {
        Position,
        Normal,
        Tangent,
        Binormal,
        Color,
        TexCoord
    };
}
