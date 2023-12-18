#pragma
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API InputElementSemantic : byte
    {
        Position,
        Normal,
        Tangent,
        Binormal,
        Color,
        TexCoord
        // TODO : Bone enums may be needed
    };
}
