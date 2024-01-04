#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API PlatformHardware final
	{
	public:
		static UInt16 GetCpuThreadCount();
		static UInt16 GetPageSize();
	public:
		PlatformHardware() = delete;
		~PlatformHardware() = delete;
	};
}
