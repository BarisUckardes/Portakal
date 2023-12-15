#include "Core.h"

#include <Runtime/Containers/String.h>
//#include <Runtime/Platform/PlatformMessage.h>

#include <iostream>
#include <stdarg.h>
#include <cassert>

namespace Portakal
{
	void DevInfo(LogLevel type, const char* message, ...)
	{
		va_list args;
		va_start(args, message);

		switch (type)
		{
		case LogLevel::Info:
			printf("\033[36m[INFO]\033[39m -- ");
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

		vprintf(message, args);
		printf("\n");
		va_end(args);

		if (type == LogLevel::Fatal)
		{
			abort();
		}
	}

	void DevLog(const char* title, const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		printf("\033[36m[%s]\033[39m -- ", title);
		vprintf(message, args);
		printf("\n");
		va_end(args);
	}

	void DevSystem(bool condition, const char* title, const char* failed, const char* succeed)
	{
		if (!condition)
		{
			std::cout << "\033[31m[" << String(title).GetSource() << "]\033[39m -- " << String(failed).GetSource() << "\n";
			//PlatformMessage::ShowMessageBox(title, failed, Portakal::PlatformMessageBoxFlags::IconStop);
		}
		else
		{
			std::cout << "\033[32m[" << String(title).GetSource() << "]\033[39m -- " << String(succeed).GetSource() << "\n";
		}
	}

	void DevAssert(bool condition, const char* title, const char* failed, ...)
	{
		if (!condition)
		{
			va_list args;
			va_start(args, failed);
			printf("\033[31m[%s]\033[39m -- ", title);
			vprintf(failed, args);
			printf("\n");
			va_end(args);

			//PlatformMessage::ShowMessageBox(title, failed, Portakal::PlatformMessageBoxFlags::IconStop);
			assert(condition);
		}
	}
}
