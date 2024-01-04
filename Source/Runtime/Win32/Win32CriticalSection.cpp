#include "Win32CriticalSection.h"

namespace Portakal
{
    Win32CriticalSection::Win32CriticalSection()
    {
        InitializeCriticalSectionAndSpinCount(&mCS, uint64_max);
    }
    void Win32CriticalSection::OnShutdown()
    {
        DeleteCriticalSection(&mCS);
    }
    void Win32CriticalSection::OnNameChange(const String& name)
    {

    }
    Bool8 Win32CriticalSection::TryEnter()
    {
        return TryEnterCriticalSection(&mCS);
    }
    void Win32CriticalSection::Enter()
    {
        EnterCriticalSection(&mCS);
    }
    void Win32CriticalSection::Leave()
    {
        LeaveCriticalSection(&mCS);
    }
}
