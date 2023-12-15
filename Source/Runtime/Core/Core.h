#pragma once

/*
* Select corresponding primitive data type according to the underlying platform
*/
#if defined(_MSC_VER) && _MSC_VER >= 1910
typedef unsigned char uint8;
typedef unsigned char byte;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef char int8;
typedef short int16;
typedef int int32;
typedef long long int64;
#define uint64_max 0xFFFFFFFFFFFFFFFF
#endif

/*
* Flag helpers
*/
#define GENERATE_FLAGS(flagType,dataType)\
	FORCEINLINE static flagType operator |(const flagType a, const flagType b)\
	{\
		return  (flagType)((dataType)a | (dataType)b);\
	}\
	FORCEINLINE static bool operator &(const flagType a, const flagType b)\
	{\
		return ((dataType)a & (dataType)b);\
	}

/*
* Conversion helpers
*/
#define BYTE_TO_MB(byte) byte/1000000.0
#define MB_TO_BYTE(mb) mb*1000000.0
#define NANO_TO_SECONDS(nano) nano / 1000000000.0f
#define NANO_TO_MS(nano) nano / 1000000.0f
#define MS_TO_SECONDS(ms) ms / 1000.0f
#define SECONDS_TO_MS(seconds) seconds * 1000.0f
#define SECONDS_TO_NANO(seconds) seconds * 1000000000.0f
#define MS_TO_NANO(ms) ms * 1000000.0f
