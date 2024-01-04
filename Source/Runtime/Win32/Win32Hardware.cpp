#include "Win32Hardware.h"
#include <Windows.h>

namespace Portakal
{
	UInt16 Win32Hardware::GetCpuThreadCount()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwNumberOfProcessors;
	}
	UInt32 Win32Hardware::GetPageSize()
	{
		SYSTEM_INFO info = {};
		GetSystemInfo(&info);
		return info.dwPageSize;
	}
}
