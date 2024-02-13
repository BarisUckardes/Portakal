#pragma once
#include <Runtime/Thread/MutexWaitResult.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	/// <summary>
	/// Mutex platform implementation
	/// </summary>
	class RUNTIME_API PlatformMutex : public Object
	{
	public:
		static SharedHeap<PlatformMutex> Create();
	public:
		PlatformMutex() = default;
		~PlatformMutex() = default;

		virtual MutexWaitResult Lock(const UInt64 timeInMs = uint64_max) = 0;
		virtual Bool8 Release() = 0;
	};
}
