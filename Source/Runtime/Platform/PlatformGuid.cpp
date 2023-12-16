#include "PlatformGuid.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Guid.h>
typedef Portakal::Win32Guid PlatformAbstraction;
#endif

namespace Portakal
{
    void PlatformGuid::Create(Guid& id)
    {
        PlatformAbstraction::Create(id);
    }
}