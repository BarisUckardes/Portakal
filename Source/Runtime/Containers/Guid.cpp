#include "Guid.h"

namespace Portakal
{

    Guid Guid::Create()
    {
        Guid id = {};
       // PlatformGuid::Create(id);
        return id;
    }

    Guid Guid::Create(const uint32 a, const uint32 b, const uint32 c, const uint32 d)
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

    Guid::Guid(const uint32 a, const uint32 b, const uint32 c, const uint32 d)
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

    bool Guid::operator==(const Guid& other) const
    {
        return A == other.A && B == other.B && C == other.C && D == other.D;
    }

    bool Guid::operator!=(const Guid& other) const
    {
        return A != other.A || B != other.B || C != other.C || D != other.D;
    }


}