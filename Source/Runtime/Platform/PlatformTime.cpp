#include "PlatformTime.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Time.h>
typedef Portakal::Win32Time PlatformAbstraction;
#endif
namespace Portakal
{
    bool PlatformTime::Initialize()
    {
        return PlatformAbstraction::Initialize();
    }
    void PlatformTime::GetTimeStamp(TimeStamp& time)
    {
        PlatformAbstraction::GetTimeStamp(time);
    }
    UInt64 PlatformTime::GetCurrentTimeAsNanoseconds()
    {
        return PlatformAbstraction::GetCurrentTimeAsNanoseconds();
    }
}
