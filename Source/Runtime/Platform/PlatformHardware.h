#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API PlatformHardware final
	{
	public:
		static uint16 GetCpuThreadCount();
		static uint16 GetPageSize();
	public:
		PlatformHardware() = delete;
		~PlatformHardware() = delete;
	};
}
