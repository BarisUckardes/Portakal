#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Time/TimeStamp.h>

namespace Portakal
{
	class RUNTIME_API Win32File final
	{
	public:
		static Bool8 Exists(const String& path);
		static Bool8 Create(const String& path);
		static Bool8 Delete(const String& path);
		static Bool8 Write(const String& path, const String& content, const UInt64 offsetInBytes = 0);
		static Bool8 Write(const String& path, const MemoryView& view, const UInt64 offsetInBytes = 0);
		static Bool8 Read(const String& path, String& contentOut, const UInt64 startByte = 0, const UInt64 endByte = 0);
		static Bool8 Read(const String& path, MemoryView& view, const UInt64 startByte = 0, const UInt64 endByte = 0);
		static Bool8 Copy(const String& sourcePath, const String& destinationPath);
		static String GetExtension(const String& path);
		static String RemoveExtension(const String& path);
		static Bool8 GetSize(const String& path, UInt64& sizeInBytesOut);
		static String GetName(const String& path);
		static Bool8 Rename(const String& file, const String& name);
		//static String GetNameWithoutExtension(const String& path);
		static String GetDirectory(const String& path);
		static Bool8 GetFileLastChangeTime(const String& path,TimeStamp& timeSOut);
		static Bool8 GetFileCreateTime(const String& path,TimeStamp& timesOut);
	public:
		Win32File() = delete;
		~Win32File() = delete;
	};
}
