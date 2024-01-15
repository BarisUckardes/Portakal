#include "PlatformFile.h"
#include <Runtime/Win32/Win32File.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
typedef Portakal::Win32File PlatformAbstraction;
#endif

namespace Portakal
{
    Bool8 PlatformFile::Exists(const String& path)
    {
        return PlatformAbstraction::Exists(path);
    }

    Bool8 PlatformFile::Create(const String& path)
    {
        return PlatformAbstraction::Create(path);
    }

    Bool8 PlatformFile::Delete(const String& path)
    {
        return PlatformAbstraction::Delete(path);
    }

    Bool8 PlatformFile::Write(const String& path, const String& content,
        const unsigned long long int offsetInBytes)
    {
        return PlatformAbstraction::Write(path, content, offsetInBytes);
    }

    Bool8 PlatformFile::Write(const String& path, const MemoryView& view,
        const unsigned long long int offsetInBytes)
    {
        return PlatformAbstraction::Write(path, view, offsetInBytes);
    }

    Bool8 PlatformFile::Read(const String& path, String& contentOut,
        const unsigned long long int startByte, const unsigned long long int endByte)
    {
        return PlatformAbstraction::Read(path, contentOut, startByte, endByte);
    }

    Bool8 PlatformFile::Read(const String& path, MemoryView& view, const unsigned long long int startByte,
        const unsigned long long int endByte)
    {
        return PlatformAbstraction::Read(path, view, startByte, endByte);
    }

    Bool8 PlatformFile::Copy(const String& sourcePath, const String& destinationPath)
    {
        return PlatformAbstraction::Copy(sourcePath, destinationPath);
    }

    String PlatformFile::GetExtension(const String& path)
    {
        return PlatformAbstraction::GetExtension(path);
    }

    String PlatformFile::RemoveExtension(const String& path)
    {
        return PlatformAbstraction::RemoveExtension(path);
    }

    Bool8 PlatformFile::GetSize(const String& path, unsigned long long int& sizeInBytesOut)
    {
        return PlatformAbstraction::GetSize(path, sizeInBytesOut);
    }

    String PlatformFile::GetName(const String& path)
    {
        return PlatformAbstraction::GetName(path);
    }

    String PlatformFile::GetNameWithoutExtension(const String& path)
    {
        const Int32 index = path.FindIndex('.');
        if (index == -1)
            return path;
        return PlatformFile::GetName(path.GetSubset(0, index));
    }

    String PlatformFile::GetDirectory(const String& path)
    {
        return PlatformAbstraction::GetDirectory(path);
    }

    Bool8 PlatformFile::GetFileLastChangeTime(const String& path,TimeStamp& timeOut)
    {
        return PlatformAbstraction::GetFileLastChangeTime(path,timeOut);
    }
    Bool8 PlatformFile::GetFileCreateTime(const String& path, TimeStamp& timeOut)
    {
        return PlatformAbstraction::GetFileCreateTime(path,timeOut);
    }
}
