#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class ThreadJob;

	/// <summary>
	/// Thread platform implementation
	/// </summary>
	class RUNTIME_API PlatformThread : public Object
	{
	public:
		template<typename T,typename... TParameters>
		static SharedHeap<PlatformThread> Create(const UInt64 stackSize, TParameters... parameters)
		{
			SharedHeap<ThreadJob> pJob = new T(parameters...);

			return Dispatch(stackSize, pJob);
		}
		static SharedHeap<PlatformThread> Create(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob)
		{
			return Dispatch(stackSize, pJob);
		}
		static void SleepCurrentThread(const UInt64 ms);
		static UInt64 GetCurrentThreadID();
	private:
		static SharedHeap<PlatformThread> Dispatch(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob);
	public:
		~PlatformThread() = default;

		FORCEINLINE ThreadJob* GetJob() const noexcept
		{
			return mJob.GetHeap();
		}
		FORCEINLINE UInt64 GetStackSize() const noexcept
		{
			return mStackSize;
		}

		virtual void WaitForFinish()
		{

		}
	protected:
		PlatformThread(const UInt64 stackSize, const SharedHeap<ThreadJob>& pJob);
	private:
		SharedHeap<ThreadJob> mJob;
		UInt64 mStackSize;
	};
}
