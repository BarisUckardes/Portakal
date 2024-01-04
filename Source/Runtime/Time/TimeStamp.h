#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    struct RUNTIME_API TimeStamp
    {
        TimeStamp() : Year(0), Month(0), Day(0), Hour(0), Minute(0), Second(0), Milliseconds(0)
        {

        }

        Uint16 Year;
        Byte Month;
        Byte Day;
        Byte Hour;
        Byte Minute;
        Byte Second;
        Uint64 Milliseconds;
    };

    static Bool8 operator==(const TimeStamp& a, const TimeStamp& b)
    {
        return
            a.Day == b.Day &&
            a.Hour == b.Hour &&
            a.Milliseconds == b.Milliseconds &&
            a.Minute == b.Minute &&
            a.Month == b.Month &&
            a.Second == b.Second &&
            a.Year == a.Year;
    }
    static Bool8 operator!=(const TimeStamp& a, const TimeStamp& b)
    {
        return
            a.Day != b.Day ||
            a.Hour != b.Hour ||
            a.Milliseconds != b.Milliseconds ||
            a.Minute != b.Minute ||
            a.Month != b.Month ||
            a.Second != b.Second ||
            a.Year != a.Year;
    }
    static Bool8 operator > (const TimeStamp& a, const TimeStamp& b)
    {
        return
            a.Year > b.Year ||
            a.Month > b.Month ||
            a.Day > b.Day ||
            a.Hour > b.Hour ||
            a.Minute > b.Minute ||
            a.Second > b.Second ||
            a.Milliseconds > b.Milliseconds;
    }
}
