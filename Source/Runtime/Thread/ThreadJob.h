#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Thread/ThreadJobState.h>

namespace Portakal
{
	class PlatformThread;
	class PlatformCriticalSection;

	class RUNTIME_API ThreadJob : public Object
	{
		friend class PlatformThread;
	public:
		ThreadJob();
		~ThreadJob() = default;

		FORCEINLINE SharedHeap<PlatformThread> GetOwnerThread() const noexcept
		{
			return mOwnerThread;
		}
		FORCEINLINE ThreadJobState GetState() noexcept;

		void Run();
	protected:
		virtual void OnRun()
		{

		}
	private:
		void _SetOwnerThread(const SharedHeap<PlatformThread>& pThread);
		void SetState(const ThreadJobState state);
	private:
		SharedHeap<PlatformThread> mOwnerThread;
		SharedHeap<PlatformCriticalSection> mBarrier;
		ThreadJobState mState;
	};
}

