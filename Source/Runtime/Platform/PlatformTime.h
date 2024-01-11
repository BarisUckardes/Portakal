#pragma once
#include <Runtime/Time/TimeStamp.h>

namespace Portakal
{
	class RUNTIME_API PlatformTime final
	{
		friend class Platform;
	private:
		static bool Initialize();
	public:
		static void GetTimeStamp(TimeStamp& time);
		static UInt64 GetCurrentTimeAsNanoseconds();
	public:
		PlatformTime() = delete;
		~PlatformTime() = delete;
	};
}
