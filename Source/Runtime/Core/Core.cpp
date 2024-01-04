#include "Core.h"

#include <Runtime/Containers/String.h>
#include <Runtime/Platform/PlatformMessage.h>

#include <iostream>
#include <stdarg.h>
#include <cassert>

namespace Portakal
{
	void DevInfo(LogLevel pType, const Char* pMessage, ...)
	{
		va_list args;
		va_start(args, pMessage);

		switch (pType)
		{
		case LogLevel::Info:
			printf("\033[36m[INFO]\033[39m -- ");
			break;
		case LogLevel::Verbose:
			printf("\033[32m[VERBOSE]\033[39m -- ");
			break;
		case LogLevel::Warning:
			printf("\033[33m[WARNING]\033[39m -- ");
			break;
		case LogLevel::Error:
			printf("\033[31m[ERROR]\033[39m -- ");
			break;
		case LogLevel::Fatal:
			printf("\033[35m[FATAL]\033[39m -- ");
			break;
		default:
			break;
		}

		vprintf(pMessage, args);
		printf("\n");
		va_end(args);

		if (pType == LogLevel::Fatal)
		{
			abort();
		}
	}

	void DevSuccess(const Char* pTitle, const Char* pMessage, ...)
	{
		va_list args;
		va_start(args, pMessage);
		printf("\033[32m[%s]\033[39m -- ", pTitle);
		vprintf(pMessage, args);
		printf("\n");
		va_end(args);
	}

	void DevLog(const Char* pTitle, const Char* pMessage, ...)
	{
		va_list args;
		va_start(args, pMessage);
		printf("\033[36m[%s]\033[39m -- ", pTitle);
		vprintf(pMessage, args);
		printf("\n");
		va_end(args);
	}

	void DevSystem(Bool8 pCondition, const Char* pTitle, const Char* pFailed, const Char* pSucceed)
	{
		if (!pCondition)
		{
			std::cout << "\033[31m[" << String(pTitle).GetSource() << "]\033[39m -- " << String(pFailed).GetSource() << "\n";
			PlatformMessage::Show(pTitle, pFailed, Portakal::MessageFlags::IconStop);
			assert(pCondition);
		}
		else
		{
			std::cout << "\033[32m[" << String(pTitle).GetSource() << "]\033[39m -- " << String(pSucceed).GetSource() << "\n";
		}
	}

	void DevAssert(Bool8 pCondition, const Char* pTitle, const Char* pFailed, ...)
	{
		if (!pCondition)
		{
			va_list args;
			va_start(args, pFailed);
			printf("\033[31m[%s]\033[39m -- ", pTitle);
			vprintf(pFailed, args);
			printf("\n");
			va_end(args);

			PlatformMessage::Show(pTitle, pFailed, Portakal::MessageFlags::IconStop);
			assert(pCondition);
		}
	}
}
