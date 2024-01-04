#include "Win32Hardware.h"
#include <Windows.h>

namespace Portakal
{
	Uint16 Win32Hardware::GetCpuThreadCount()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwNumberOfProcessors;
	}
	Uint32 Win32Hardware::GetPageSize()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwPageSize;
	}
}
