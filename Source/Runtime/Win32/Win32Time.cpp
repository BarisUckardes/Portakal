#include "Win32Time.h"

namespace Portakal
{
	LARGE_INTEGER Win32Time::sFrequency = {};

	bool Win32Time::Initialize()
	{
		return QueryPerformanceFrequency(&sFrequency);
	}
	void Win32Time::GetTimeStamp(TimeStamp& stamp)
	{
		SYSTEMTIME time = {};
		GetSystemTime(&time);


		stamp.Year = time.wYear;
		stamp.Month = time.wMonth;
		stamp.Day = time.wDay;
		stamp.Hour = time.wHour;
		stamp.Minute = time.wMinute;
		stamp.Second = time.wSecond;
		stamp.Milliseconds = time.wMilliseconds;

	}
	UInt64 Win32Time::GetCurrentTimeAsNanoseconds()
	{
		LARGE_INTEGER value = {};
		QueryPerformanceCounter(&value);

		value.QuadPart *= 1000000;
		value.QuadPart /= sFrequency.QuadPart;

		return value.QuadPart;
	}
}
