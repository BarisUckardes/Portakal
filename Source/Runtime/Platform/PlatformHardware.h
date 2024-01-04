#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API PlatformHardware final
	{
	public:
		static Uint16 GetCpuThreadCount();
		static Uint16 GetPageSize();
	public:
		PlatformHardware() = delete;
		~PlatformHardware() = delete;
	};
}
