#include "PlatformThread.h"
#include <Runtime/Thread/ThreadJob.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Thread.h>
typedef Portakal::Win32Thread PlatformAbstraction;
#endif
namespace Portakal
{
	void PlatformThread::SleepCurrentThread(const UInt64 ms)
	{
		PlatformAbstraction::SleepCurrentThread(ms);
	}
	SharedHeap<PlatformThread> PlatformThread::Dispatch(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob)
	{
		return new PlatformAbstraction(stackSize,pJob);
	}
	PlatformThread::PlatformThread(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob) : mStackSize(stackSize),mJob(pJob)
	{
		pJob->_SetOwnerThread(this);
	}
}
