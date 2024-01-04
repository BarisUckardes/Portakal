#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API Win32Hardware final
	{
	public:
		static Uint16 GetCpuThreadCount();
		static Uint32 GetPageSize();
	public:
		Win32Hardware() = delete;
		~Win32Hardware() = delete;
	};
}
