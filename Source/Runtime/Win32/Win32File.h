#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Time/TimeStamp.h>

namespace Portakal
{
	class RUNTIME_API Win32File final
	{
	public:
		static bool Exists(const String& path);
		static bool Create(const String& path);
		static bool Delete(const String& path);
		static bool Write(const String& path, const String& content, const uint64 offsetInBytes = 0);
		static bool Write(const String& path, const MemoryView& view, const uint64 offsetInBytes = 0);
		static bool Read(const String& path, String& contentOut, const uint64 startByte = 0, const uint64 endByte = 0);
		static bool Read(const String& path, MemoryView& view, const uint64 startByte = 0, const uint64 endByte = 0);
		static bool Copy(const String& sourcePath, const String& destinationPath);
		static String GetExtension(const String& path);
		static String RemoveExtension(const String& path);
		static bool GetSize(const String& path, uint64& sizeInBytesOut);
		static String GetName(const String& path);
		static String GetNameWithoutExtension(const String& path);
		static String GetDirectory(const String& path);
		static bool GetFileLastChangeTime(const String& path,TimeStamp& timeSOut);
		static bool GetFileCreateTime(const String& path,TimeStamp& timesOut);
	public:
		Win32File() = delete;
		~Win32File() = delete;
	};
}
