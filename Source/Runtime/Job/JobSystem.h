#pragma once
#include <Runtime/Platform/PlatformThread.h>
#include <Runtime/Object/API.h>
#include <Runtime/Job/IJob.h>
#include <Runtime/Platform/PlatformCriticalSection.h>

namespace Portakal
{
	class RUNTIME_API JobSystem : public API<JobSystem>
	{
	public:
		template<typename T,typename... TParameters>
		static void SubmitJob(TParameters... parameters)
		{
			//Get and validate api
			JobSystem* pAPI = GetUnderlyingAPI();
			if (pAPI == nullptr)
				return;

			//Create job
			T* pJob = new T(parameters...);

			//Acquire lock
			pAPI->mBarrier->Enter();

			//First check if available workers available
			for (Worker& worker : pAPI->mWorkers)
			{

			}

			//If not submit to queue
			//pAPI->mQueue.Enqueue(pJob);
			
			//Leave lock
			pAPI->mBarrier->Leave();
		}
	private:
		struct JobQueueEntry
		{
			UInt64 Priority;
			IJob* pJob;
		};
		struct Worker
		{
			SharedHeap<PlatformThread> pThread;
			//Job
		};
	public:
		JobSystem(const UInt32 workerThreadCount);
		~JobSystem();

	private:
		const UInt32 mWorkerThreadCount;
		Array<Worker> mWorkers;
		SharedHeap<PlatformCriticalSection> mBarrier;
		//TODO: Queue<JobQueueEntry> mQueue;
	};
}
