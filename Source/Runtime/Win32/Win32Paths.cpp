#include "Win32Paths.h"
#include <Windows.h>
#include <shlobj_core.h>

namespace Portakal
{
    String Win32Paths::GetProgramsPath()
    {
        char buffer[MAX_PATH];
        SHGetSpecialFolderPathA(0, buffer, CSIDL_PROGRAM_FILES, FALSE);
        return buffer;
    }
    String Win32Paths::GetPersistentDataPath()
    {
        char buffer[MAX_PATH];
        SHGetSpecialFolderPathA(0, buffer, CSIDL_APPDATA, FALSE);
        return buffer;
    }
}
