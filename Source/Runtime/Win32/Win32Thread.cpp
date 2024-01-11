#include "Win32Thread.h"
#include <Runtime/Thread/ThreadJob.h>

namespace Portakal
{
	void Win32Thread::SleepCurrentThread(const UInt64 ms)
	{
		Sleep(ms);
	}
	void Win32Thread::DispatchThread(void* pSelf)
	{
		ThreadJob* pJob = (ThreadJob*)pSelf;
		pJob->Run();
	}
	Win32Thread::Win32Thread(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob) : PlatformThread(stackSize,pJob)
	{
		mHandle = CreateThread(NULL,stackSize,(LPTHREAD_START_ROUTINE)Win32Thread::DispatchThread,pJob.GetHeap(),NULL,NULL);
	}
}
