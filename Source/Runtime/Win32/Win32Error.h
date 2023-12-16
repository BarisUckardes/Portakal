#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API Win32Error final
	{
	public:
		static String GetCurrentError();
	public:
		Win32Error() = delete;
		~Win32Error() = delete;
	};
}
