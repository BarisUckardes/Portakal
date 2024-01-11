#pragma once
#include <Windows.h>
#include <Runtime/Time/TimeStamp.h>

namespace Portakal
{
	class RUNTIME_API Win32Time final
	{
	private:
		static LARGE_INTEGER sFrequency;
	public:
		static bool Initialize();
		static void GetTimeStamp(TimeStamp& stamp);
		static UInt64 GetCurrentTimeAsNanoseconds();
	public:
		Win32Time() = delete;
		~Win32Time() = delete;
	};
}
