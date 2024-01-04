#include "Win32File.h"
#include <Windows.h>
#include <Shlwapi.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <strstream>
#include <iostream> 
#include <string> 
#include <sstream> 
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
    Bool8 Win32File::Exists(const String& path)
    {
        const DWORD diagnostics = GetFileAttributesA(*path);

        if (diagnostics == INVALID_FILE_ATTRIBUTES || diagnostics == FILE_ATTRIBUTE_DIRECTORY)
            return false;

        return true;
    }
    Bool8 Win32File::Create(const String& path)
    {
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        CloseHandle(fileHandle);

        return true;
    }
    Bool8 Win32File::Delete(const String& path)
    {
        return DeleteFileA(*path) != 0;
    }
    Bool8 Win32File::Write(const String& path, const String& content, const UInt64 offsetInBytes)
    {
        HANDLE fileHandle = NULL;

        //Create new file or write to existing
        if (Exists(path))
        {
            fileHandle = CreateFileA(*path,
                GENERIC_WRITE,
                0,
                NULL,
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        }
        else
        {
            fileHandle = CreateFileA(*path,
                GENERIC_WRITE,
                0,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        }

        //Check the handle
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        //Write to file
        DWORD writtenBytes = 0;
        const Bool8 bIsWriteSuccess = WriteFile(fileHandle, *content, content.GetSize(), &writtenBytes, NULL);

        //Close handle
        CloseHandle(fileHandle);

        return bIsWriteSuccess;
    }
    Bool8 Win32File::Write(const String& path, const MemoryView& view, const UInt64 offsetInBytes)
    {
        HANDLE fileHandle = NULL;

        //Create new file or write to existing
        if (Exists(path))
        {
            fileHandle = CreateFileA(*path,
                GENERIC_WRITE,
                0,
                NULL,
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        }
        else
        {
            fileHandle = CreateFileA(*path,
                GENERIC_WRITE,
                0,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        }

        //Write to file
        DWORD writtenBytes = 0;
        const Bool8 bIsWriteSuccess = WriteFile(fileHandle, view.GetMemory(), view.GetSize(), &writtenBytes, NULL);

        //Close handle
        CloseHandle(fileHandle);

        return bIsWriteSuccess;
    }
    Bool8 Win32File::Read(const String& path, String& contentOut, const UInt64 startByte, const UInt64 endByte)
    {
        //Get file size
        UInt64 fileSize = 0;
        if (!GetSize(path, fileSize))
        {
            DEV_LOG("Win32File", "Failed to get size of the file");
            return false;
        }

        //Get and check expected read range
        const UInt64 expectedReadRange = endByte == 0 ? fileSize : endByte - startByte;
        if (fileSize == 0 || expectedReadRange > fileSize)
            return false;

        //Open file
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        //Read file
        DWORD bytesRead = 0;
        OVERLAPPED overlappedData = { 0 };
        Byte* pBuffer = new Byte[expectedReadRange];
        if (ReadFile(fileHandle, pBuffer, expectedReadRange, &bytesRead, NULL) == 0)
        {
            CloseHandle(fileHandle);
            return false;
        }

        //Check 
        if (bytesRead != expectedReadRange)
            return false;

        contentOut = String((Char*)pBuffer, expectedReadRange);

        //Close handle
        CloseHandle(fileHandle);
        return true;
    }
    Bool8 Win32File::Read(const String& path, MemoryView& view, const UInt64 startByte, const UInt64 endByte)
    {
        //Get file size
        UInt64 fileSize = 0;
        if (!GetSize(path, fileSize))
        {
            DEV_LOG("Win32File", "Failed to get size of the file");
            return false;
        }

        //Get and check expected read range
        const UInt64 expectedReadRange = endByte == 0 ? fileSize : endByte - startByte;
        if (fileSize == 0 || expectedReadRange > fileSize)
            return false;

        //Open file
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        //Read file
        DWORD bytesRead = 0;
        OVERLAPPED overlappedData = { 0 };
        Byte* pBuffer = new Byte[expectedReadRange];
        if (!ReadFile(fileHandle, pBuffer, expectedReadRange, &bytesRead, NULL))
        {
            CloseHandle(fileHandle);
            return false;
        }

        //Check 
        if (bytesRead != expectedReadRange)
            return false;

        //Copy to memory view
        view = { pBuffer,expectedReadRange };

        //Close handle
        CloseHandle(fileHandle);
    }
    Bool8 Win32File::Copy(const String& sourcePath, const String& destinationPath)
    {
        return CopyFile(*sourcePath,*destinationPath,TRUE);
    }
    String Win32File::GetExtension(const String& path)
    {
        return PathFindExtensionA(*path);
    }
    String Win32File::RemoveExtension(const String& path)
    {
        Char* pData = path.GetSource();
        PathRemoveExtension(pData);
        return pData;
    }
    Bool8 Win32File::GetSize(const String& path, UInt64& sizeInBytesOut)
    {
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        sizeInBytesOut = GetFileSize(fileHandle, NULL);

        CloseHandle(fileHandle);

        return true;
    }
    String Win32File::GetName(const String& path)
    {
        const Char* pData = PathFindFileNameA(*path);
        return pData;
    }
    String Win32File::GetNameWithoutExtension(const String& path)
    {
        return String();
    }
    String Win32File::GetDirectory(const String& path)
    {
        String name = GetName(path);

        String output = path;
        output -= "\\" + name;

        return output;
    }
    Bool8 Win32File::GetFileLastChangeTime(const String& path,TimeStamp& timeOut)
    {
        //Open file
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        //Get file time
        FILETIME writeTime = {};
        if (GetFileTime(fileHandle, NULL, NULL, &writeTime))
        {
            DEV_LOG("Win32File", "Failed to get the GetFileTime");
            CloseHandle(fileHandle);
            return false;
        }

        //Close handle
        CloseHandle(fileHandle);

        //Convert to system time
        SYSTEMTIME systemTime = {};
        if (FileTimeToSystemTime(&writeTime, &systemTime))
        {
            DEV_LOG("Win32File", "Failed to convert File time to system time!");
            return false;
        }
        return false;

        timeOut.Year = systemTime.wYear;
        timeOut.Month = systemTime.wMonth;
        timeOut.Day = systemTime.wDay;
        timeOut.Hour = systemTime.wHour;
        timeOut.Minute = systemTime.wMinute;
        timeOut.Second = systemTime.wSecond;
        timeOut.Milliseconds = systemTime.wMilliseconds;

        return true;
    }
    Bool8 Win32File::GetFileCreateTime(const String& path,TimeStamp& timeOut)
    {
        //Open file
        const HANDLE fileHandle = CreateFileA(*path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (fileHandle == NULL || fileHandle == INVALID_HANDLE_VALUE)
            return false;

        //Get file time
        FILETIME writeTime = {};
        if (GetFileTime(fileHandle, NULL, NULL, &writeTime))
        {
            DEV_LOG("Win32File", "Failed to get the GetFileTime");
            CloseHandle(fileHandle);
            return false;
        }

        //Close handle
        CloseHandle(fileHandle);

        //Convert to system time
        SYSTEMTIME systemTime = {};
        if (FileTimeToSystemTime(&writeTime, &systemTime))
        {
            DEV_LOG("Win32File", "Failed to convert File time to system time!");
            return false;
        }
        return false;

        timeOut.Year = systemTime.wYear;
        timeOut.Month = systemTime.wMonth;
        timeOut.Day = systemTime.wDay;
        timeOut.Hour = systemTime.wHour;
        timeOut.Minute = systemTime.wMinute;
        timeOut.Second = systemTime.wSecond;
        timeOut.Milliseconds = systemTime.wMilliseconds;

        return true;
    }
}
