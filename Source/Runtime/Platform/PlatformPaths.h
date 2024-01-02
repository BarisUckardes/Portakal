#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API PlatformPaths final
	{
		friend class Platform;
	public:
		static String GetExecutablePath()
		{
			return sExecutablePath;
		}
	private:
		static void _SetExecutablePath(const String& path);
	private:
		static inline String sExecutablePath;
	public:
		PlatformPaths() = delete;
		~PlatformPaths() = delete;
	};
}
