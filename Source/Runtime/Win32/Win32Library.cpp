#include "Win32Library.h"

namespace Portakal
{
    SharedHeap<PlatformLibrary> Win32Library::Load(const String& path)
    {
        return new Win32Library(path);
    }
    SharedHeap<PlatformLibrary> Win32Library::LoadCurrent()
    {
        return new Win32Library(GetModuleHandle(NULL));
    }
    Win32Library::Win32Library(HINSTANCE handle) : PlatformLibrary("Main"),mHandle(handle)
    {

    }
    Win32Library::Win32Library(const String& path) : PlatformLibrary(path)
    {
        mHandle = LoadLibrary(*path);
    }
    PlatformLibraryHandle Win32Library::GetSymbol(const String& name)
    {
        return GetProcAddress(mHandle, *name);
    }
    void Win32Library::OnShutdown()
    {
        FreeLibrary(mHandle);
    }
}
