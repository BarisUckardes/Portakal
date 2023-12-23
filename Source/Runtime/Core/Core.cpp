#include "Core.h"

#include <Runtime/Containers/String.h>
//#include <Runtime/Platform/PlatformMessage.h>

#include <iostream>
#include <stdarg.h>
#include <cassert>

namespace Portakal
{
	void DevInfo(LogLevel pType, const char* pMessage, ...)
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

	void DevSuccess(const char* pTitle, const char* pMessage, ...)
	{
		va_list args;
		va_start(args, pMessage);
		printf("\033[32m[%s]\033[39m -- ", pTitle);
		vprintf(pMessage, args);
		printf("\n");
		va_end(args);
	}

	void DevLog(const char* pTitle, const char* pMessage, ...)
	{
		va_list args;
		va_start(args, pMessage);
		printf("\033[36m[%s]\033[39m -- ", pTitle);
		vprintf(pMessage, args);
		printf("\n");
		va_end(args);
	}

	void DevSystem(bool pCondition, const char* pTitle, const char* pFailed, const char* pSucceed)
	{
		if (!pCondition)
		{
			std::cout << "\033[31m[" << String(pTitle).GetSource() << "]\033[39m -- " << String(pFailed).GetSource() << "\n";
			//PlatformMessage::ShowMessageBox(pTitle, pFailed, Portakal::PlatformMessageBoxFlags::IconStop);
		}
		else
		{
			std::cout << "\033[32m[" << String(pTitle).GetSource() << "]\033[39m -- " << String(pSucceed).GetSource() << "\n";
		}
	}

	void DevAssert(bool pCondition, const char* pTitle, const char* pFailed, ...)
	{
		if (!pCondition)
		{
			va_list args;
			va_start(args, pFailed);
			printf("\033[31m[%s]\033[39m -- ", pTitle);
			vprintf(pFailed, args);
			printf("\n");
			va_end(args);

			//PlatformMessage::ShowMessageBox(pTitle, pFailed, Portakal::PlatformMessageBoxFlags::IconStop);
			assert(pCondition);
		}
	}
}
