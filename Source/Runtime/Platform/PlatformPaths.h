#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	/// <summary>
	/// Paths platform implementation
	/// </summary>
	class RUNTIME_API PlatformPaths final
	{
		friend class Platform;
	public:
		static String GetExecutablePath()
		{
			return sExecutablePath;
		}
		static String GetProgramsPath();
		static String GetPersistentDataPath();
	private:
		static void _SetExecutablePath(const String& path);
	private:
		static inline String sExecutablePath;
	public:
		PlatformPaths() = delete;
		~PlatformPaths() = delete;
	};
}
