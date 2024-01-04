#include "Guid.h"
#include <Runtime\Platform\PlatformGuid.h>

namespace Portakal
{

    Guid Guid::Create()
    {
        Guid id = {};
        PlatformGuid::Create(id);
        return id;
    }

    Guid Guid::Create(const Uint32 a, const Uint32 b, const Uint32 c, const Uint32 d)
    {
        return Guid(a, b, c, d);
    }

    Guid Guid::Zero()
    {
        return Guid(0, 0, 0, 0);
    }

    Guid::Guid() : A(0), B(0), C(0), D(0)
    {
    }

    Guid::Guid(const Uint32 a, const Uint32 b, const Uint32 c, const Uint32 d)
    {
        A = a;
        B = b;
        C = c;
        D = d;
    }

    Guid::Guid(const Guid& other)
    {
        A = other.A;
        B = other.B;
        C = other.C;
        D = other.D;
    }

    Guid& Guid::operator=(const Guid& other)
    {
        A = other.A;
        B = other.B;
        C = other.C;
        D = other.D;
        return *this;
    }

    Guid& Guid::operator=(Guid&& other) noexcept
    {
        A = other.A;
        B = other.B;
        C = other.C;
        D = other.D;
        return *this;
    }

    Bool8 Guid::operator==(const Guid& other) const
    {
        return A == other.A && B == other.B && C == other.C && D == other.D;
    }

    Bool8 Guid::operator!=(const Guid& other) const
    {
        return A != other.A || B != other.B || C != other.C || D != other.D;
    }


}