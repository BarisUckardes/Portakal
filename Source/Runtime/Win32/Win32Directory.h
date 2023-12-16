#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API Win32Directory final
	{
	public:
		static bool Create(const String& path);
		static bool Delete(const String& path);
		static String GetName(const String& path);
		static bool GetFileNames(const String& path, Array<String>& namesOut);
		static bool GetFolderNames(const String& path, Array<String>& namesOut);
		static bool GetFileNamesViaExtension(const String& path, const String& extension, Array<String>& namesOut);
		static bool Exists(const String& path);
	public:
		Win32Directory() = delete;
		~Win32Directory() = delete;
	};
}
