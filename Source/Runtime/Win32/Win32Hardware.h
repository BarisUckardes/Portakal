#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API Win32Hardware final
	{
	public:
		static UInt16 GetCpuThreadCount();
		static UInt32 GetPageSize();
	public:
		Win32Hardware() = delete;
		~Win32Hardware() = delete;
	};
}
