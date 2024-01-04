#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API Win32Directory final
	{
	public:
		static Bool8 Create(const String& path);
		static Bool8 Delete(const String& path);
		static String GetName(const String& path);
		static Bool8 GetFileNames(const String& path, Array<String>& namesOut);
		static Bool8 GetFolderNames(const String& path, Array<String>& namesOut);
		static Bool8 GetFileNamesViaExtension(const String& path, const String& extension, Array<String>& namesOut);
		static Bool8 Exists(const String& path);
	public:
		Win32Directory() = delete;
		~Win32Directory() = delete;
	};
}
