#include "ThreadJob.h"
#include <Runtime/Platform/PlatformThread.h>
#include <Runtime/Platform/PlatformCriticalSection.h>

namespace Portakal
{
	ThreadJob::ThreadJob() : mState(ThreadJobState::Idle)
	{
		mBarrier = PlatformCriticalSection::Create();
	}

	ThreadJobState ThreadJob::GetState() noexcept
	{
		mBarrier->Enter();
		const ThreadJobState state = mState;
		mBarrier->Leave();
		return mState;
	}
	void ThreadJob::Run()
	{
		SetState(ThreadJobState::Working);
		OnRun();
		SetState(ThreadJobState::Finished);
	}
	void ThreadJob::_SetOwnerThread(const SharedHeap<PlatformThread>& pThread)
	{
		mOwnerThread = pThread;
	}
	void ThreadJob::SetState(const ThreadJobState state)
	{
		mBarrier->Enter();
		mState = state;
		mBarrier->Leave();
	}
}
