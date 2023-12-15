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

    Guid::Guid(const Guid& pOther)
    {
        A = pOther.A;
        B = pOther.B;
        C = pOther.C;
        D = pOther.D;
    }

    Guid& Guid::operator=(const Guid& pOther)
    {
        A = pOther.A;
        B = pOther.B;
        C = pOther.C;
        D = pOther.D;
        return *this;
    }

    Guid& Guid::operator=(Guid&& pOther) noexcept
    {
        A = pOther.A;
        B = pOther.B;
        C = pOther.C;
        D = pOther.D;
        return *this;
    }

    bool Guid::operator==(const Guid& pOther) const
    {
        return A == pOther.A && B == pOther.B && C == pOther.C && D == pOther.D;
    }

    bool Guid::operator!=(const Guid& pOther) const
    {
        return A != pOther.A || B != pOther.B || C != pOther.C || D != pOther.D;
    }


}