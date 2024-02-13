#include "Win32Mutex.h"

namespace Portakal
{
	Win32Mutex::Win32Mutex()
	{
		mHandle = CreateMutex(NULL, FALSE, NULL);
	}
	MutexWaitResult Win32Mutex::Lock(const UInt64 timeInMs)
	{
		const HRESULT result = WaitForSingleObject(mHandle,timeInMs);

		switch (result) {
		case WAIT_OBJECT_0:
			return MutexWaitResult::Signalled;
		case WAIT_TIMEOUT:
			return MutexWaitResult::Timeout;
		case WAIT_ABANDONED:
			return MutexWaitResult::Invalid;
		default:
			return MutexWaitResult::Invalid;
		};
	}
	Bool8 Win32Mutex::Release()
	{
		return ReleaseMutex(mHandle);
	}
	void Win32Mutex::OnShutdown()
	{
		CloseHandle(mHandle);
		mHandle = NULL;
	}
}
