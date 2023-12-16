#include "Win32Hardware.h"
#include <Windows.h>

namespace Portakal
{
	uint16 Win32Hardware::GetCpuThreadCount()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwNumberOfProcessors;
	}
	uint32 Win32Hardware::GetPageSize()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwPageSize;
	}
}
