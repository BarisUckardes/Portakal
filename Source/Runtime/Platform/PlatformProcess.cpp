#include "PlatformProcess.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Process.h>
typedef Portakal::Win32Process PlatformAbstraction;
#endif

namespace Portakal
{
    PlatformProcess::PlatformProcess(const String& path, const String& command) : mPath(path),mCommand(command)
    {

    }
    void PlatformProcess::OnShutdown()
    {
        WaitForFinish();
    }
}
