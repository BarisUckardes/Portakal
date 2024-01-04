#include "Win32Process.h"

namespace Portakal
{
	Win32Process::Win32Process(const String& path, const String& command) : PlatformProcess(path,command),mInformation()
	{
		STARTUPINFO info = {};
		ZeroMemory(&info, sizeof(info));

		CreateProcess(*path, (Char*)*command, NULL, NULL, FALSE, 0, NULL, NULL, &info, &mInformation);
	}
	Win32Process::~Win32Process()
	{
	}
	void Win32Process::Terminate()
	{
		TerminateProcess(mInformation.hProcess, 0);
		CloseHandle(mInformation.hProcess);
		CloseHandle(mInformation.hThread);
	}
	void Win32Process::WaitForFinish()
	{
		WaitForSingleObject(mInformation.hProcess, INFINITE);
		CloseHandle(mInformation.hProcess);
		CloseHandle(mInformation.hThread);
	}
}
