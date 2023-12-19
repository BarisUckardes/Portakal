#pragma once

#if defined(_MSC_VER) && _MSC_VER >= 1910
typedef unsigned char uint8, byte;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;
#define uint64_max 0xFFFFFFFFFFFFFFFF
#endif

#if defined(__MSC_VERSION__) || defined(_MSC_VER)
#define NODISCARD_INLINE [[nodiscard]] __forceinline
#define NODISCARD_MSG(_Msg) [[nodiscard(_Msg)]]
#elif defined(__GNUC__) || defined(__GNUG__)
#define NODISCARD_INLINE __attribute__((warn_unused_result)) __attribute__((always_inline))
#define _NODISCARD_MSG(_Msg) [[nodiscard(_Msg)]]
#else
#define NODISCARD_INLINE __attribute__((warn_unused_result)) inline
#define _NODISCARD_MSG(_Msg) [[nodiscard(_Msg)]]
#endif

#define NODISCARD NODISCARD_MSG("This function or variable should be used, pOtherwise it is useless to declare it.")

namespace Portakal
{
    enum class LogLevel
	{
		Info,
		Verbose,
		Warning,
		Error,
		Fatal
	};

    void DevInfo(LogLevel pType, const char* pMessage,...);
    void DevLog(const char* pTitle, const char* pMessage,...);
    void DevSystem(bool pCondition, const char* pTitle, const char* pFailed, const char* pSucceed);
    void DevAssert(bool pCondition, const char* pTitle, const char* pFailed,...);
}

#ifdef PORTAKAL_DEBUG
#define DEV_SYSTEM(pCondition, pTitle, pFailed, pSucceed) Portakal::DevSystem(pCondition, pTitle, pFailed, pSucceed) // For one time check to see if the system items has been created successfully
#define DEV_ASSERT(pCondition, pTitle, pFailed, ...) Portakal::DevAssert(pCondition, pTitle, pFailed, __VA_ARGS__) // For multiple times error check to see if something is wrong
#else
#define DEV_SYSTEM(pCondition, pTitle, pMessage, pSucceed)
#define DEV_ASSERT(pCondition, pTitle, pMessage)
#endif

#define PE_INFO Portakal::LogLevel::Info
#define PE_VERBOSE Portakal::LogLevel::Verbose
#define PE_WARNING Portakal::LogLevel::Warning
#define PE_ERROR Portakal::LogLevel::Error
#define PE_FATAL Portakal::LogLevel::Fatal

#ifdef PORTAKAL_DEBUG
/**
 * @macro PORTAKAL_LOG
 *
 * @brief It can be used as logging macro. It can be used in higher level code such as game scripts.
 *
 * @throw PORTAKAL_LOG(PE_INFO, "Message", ...); is to print an info pMessage.
 * @throw PORTAKAL_LOG(PE_WARNING, "Message", ...); is to print an warning pMessage.
 * @throw PORTAKAL_LOG(PE_ERROR, "Message", ...); is to print an error pMessage.
 * @throw PORTAKAL_LOG(PE_FATAL, "Message", ...); is to print an fatal pMessage.
 */
#define PORTAKAL_LOG(Level, pMessage, ...) Portakal::DevInfo(Level, pMessage, __VA_ARGS__)
#define DEV_LOG(pTitle, pMessage, ...) Portakal::DevLog(pTitle, pMessage, __VA_ARGS__)
#else
#define DEV_LOG(pTitle, pMessage, ...)
#endif

#define GENERATE_FLAGS(flagType,dataType)\
	FORCEINLINE static flagType operator |(const flagType a, const flagType b)\
	{\
		return  (flagType)((dataType)a | (dataType)b);\
	}\
	FORCEINLINE static bool operator &(const flagType a, const flagType b)\
	{\
		return ((dataType)a & (dataType)b);\
	}

#define BYTE_TO_MB(byte) byte/1000000.0
#define MB_TO_BYTE(mb) mb*1000000.0
#define NANO_TO_SECONDS(nano) nano / 1000000000.0f
#define NANO_TO_MS(nano) nano / 1000000.0f
#define MS_TO_SECONDS(ms) ms / 1000.0f
#define SECONDS_TO_MS(seconds) seconds * 1000.0f
#define SECONDS_TO_NANO(seconds) seconds * 1000000000.0f
#define MS_TO_NANO(ms) ms * 1000000.0f