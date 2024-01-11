#include "Win32Directory.h"
#include <Runtime/Platform/PlatformFile.h>
#include <mbstring.h>
#include <string>
#include <Shlwapi.h>

namespace Portakal
{
	Bool8 Win32Directory::Create(const String& path)
	{
		return CreateDirectoryA(*path,NULL) != 0;
	}
	Bool8 Win32Directory::Delete(const String& path)
	{
		//Get sub items
		Array<String> subItems;
		GetFileNames(path, subItems);

		//Iterate items and delete
		for (UInt32 i = 0; i < subItems.GetSize(); i++)
		{
			const String& itemPath = subItems[i];
			const Bool8 bIsFile = !Exists(itemPath);
			if (bIsFile)
				PlatformFile::Delete(itemPath);
			else
				Delete(itemPath);
		}

		RemoveDirectoryA(*path);

		return true;
	}
	String Win32Directory::GetName(const String& path)
	{
		return PathFindFileNameA(*path);
	}
	Bool8 Win32Directory::GetFileNames(const String& path, Array<String>& namesOut)
	{
		const String searchFilter = path + "*";

		WIN32_FIND_DATAA findData = { 0 };

		const HANDLE fileHandle = FindFirstFileA(*searchFilter, &findData);
		if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
			return false;

		do
		{
			const String folderName = findData.cFileName;
			if (folderName == "." || folderName == "..")
				continue;

			namesOut.Add(path + "\\" + folderName);
		} while (FindNextFileA(fileHandle, &findData));


		FindClose(fileHandle);
		return true;
	}
	Bool8 Win32Directory::GetFolderNames(const String& path, Array<String>& namesOut)
	{
		Array <String> items;
		GetFileNames(path, items);

		for (unsigned int itemIndex = 0; itemIndex < items.GetSize(); itemIndex++)
		{
			const String& item = items[itemIndex];
			if (Exists(item))
				namesOut.Add(item);
		}

		return true;
	}
	Bool8 Win32Directory::GetFileNamesViaExtension(const String& path, const String& extension, Array<String>& namesOut)
	{
		Array <String> files;
		GetFileNames(path, files);

		for (unsigned int fileIndex = 0; fileIndex < files.GetSize(); fileIndex++)
		{
			const String& file = files[fileIndex];

			if (!PlatformFile::Exists(file))
				return false;

			const String fileExtension = PlatformFile::GetExtension(file);
		}

		return true;
	}
	Bool8 Win32Directory::Exists(const String& path)
	{
		const DWORD diagnostics = GetFileAttributesA(*path);
		if (diagnostics == INVALID_FILE_ATTRIBUTES || diagnostics != FILE_ATTRIBUTE_DIRECTORY)
			return false;

		return true;
	}
}
