#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API Win32Hardware final
	{
	public:
		static uint16 GetCpuThreadCount();
		static uint32 GetPageSize();
	public:
		Win32Hardware() = delete;
		~Win32Hardware() = delete;
	};
}
