#include "PlatformFile.h"
#include <Runtime/Win32/Win32File.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
typedef Portakal::Win32File PlatformAbstraction;
#endif

namespace Portakal
{
    bool PlatformFile::Exists(const String& path)
    {
        return PlatformAbstraction::Exists(path);
    }

    bool PlatformFile::Create(const String& path)
    {
        return PlatformAbstraction::Create(path);
    }

    bool PlatformFile::Delete(const String& path)
    {
        return PlatformAbstraction::Delete(path);
    }

    bool PlatformFile::Write(const String& path, const String& content,
        const unsigned long long int offsetInBytes)
    {
        return PlatformAbstraction::Write(path, content, offsetInBytes);
    }

    bool PlatformFile::Write(const String& path, const MemoryView& view,
        const unsigned long long int offsetInBytes)
    {
        return PlatformAbstraction::Write(path, view, offsetInBytes);
    }

    bool PlatformFile::Read(const String& path, String& contentOut,
        const unsigned long long int startByte, const unsigned long long int endByte)
    {
        return PlatformAbstraction::Read(path, contentOut, startByte, endByte);
    }

    bool PlatformFile::Read(const String& path, MemoryView& view, const unsigned long long int startByte,
        const unsigned long long int endByte)
    {
        return PlatformAbstraction::Read(path, view, startByte, endByte);
    }

    bool PlatformFile::Copy(const String& sourcePath, const String& destinationPath)
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

    bool PlatformFile::GetSize(const String& path, unsigned long long int& sizeInBytesOut)
    {
        return PlatformAbstraction::GetSize(path, sizeInBytesOut);
    }

    String PlatformFile::GetName(const String& path)
    {
        return PlatformAbstraction::GetName(path);
    }

    String PlatformFile::GetNameWithoutExtension(const String& path)
    {
        return PlatformAbstraction::GetNameWithoutExtension(path);
    }

    String PlatformFile::GetDirectory(const String& path)
    {
        return PlatformAbstraction::GetDirectory(path);
    }

    bool PlatformFile::GetFileLastChangeTime(const String& path,TimeStamp& timeOut)
    {
        return PlatformAbstraction::GetFileLastChangeTime(path,timeOut);
    }
    bool PlatformFile::GetFileCreateTime(const String& path, TimeStamp& timeOut)
    {
        return PlatformAbstraction::GetFileCreateTime(path,timeOut);
    }
}
