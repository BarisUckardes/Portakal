#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API Win32Paths final
	{
	public:
		Win32Paths() = delete;
		~Win32Paths() = delete;
	public:
		static String GetProgramsPath();
		static String GetPersistentDataPath();
	};
}
