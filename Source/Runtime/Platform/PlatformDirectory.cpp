#include "PlatformDirectory.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Directory.h>
typedef Portakal::Win32Directory PlatformAbstraction;
#endif

namespace Portakal
{
	Bool8 PlatformDirectory::Create(const String& path)
	{
		return PlatformAbstraction::Create(path);
	}
	Bool8 PlatformDirectory::Delete(const String& path)
	{
		return PlatformAbstraction::Delete(path);
	}
	String PlatformDirectory::GetName(const String& path)
	{
		return PlatformAbstraction::GetName(path);
	}
	Bool8 PlatformDirectory::GetFileNames(const String& path, Array<String>& namesOut)
	{
		return PlatformAbstraction::GetFileNames(path,namesOut);
	}
	Bool8 PlatformDirectory::GetFolderNames(const String& path, Array<String>& foldersOut)
	{
		return PlatformAbstraction::GetFolderNames(path,foldersOut);
	}
	Bool8 PlatformDirectory::GetFileNamesViaExtension(const String& path, const String& extension, Array<String>& namesOut)
	{
		return PlatformAbstraction::GetFileNamesViaExtension(path,extension,namesOut);
	}
	Bool8 PlatformDirectory::Exists(const String& path)
	{
		return PlatformAbstraction::Exists(path);
	}
}
