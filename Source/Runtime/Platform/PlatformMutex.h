#pragma once
#include <Runtime/Thread/MutexState.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API PlatformMutex : public Object
	{
	public:
		static SharedHeap<PlatformMutex> Create();
	public:
		PlatformMutex() = default;
		~PlatformMutex() = default;

		virtual MutexState Lock(const Uint64 timeInMs = uint64_max) = 0;
		virtual Bool8 Release() = 0;
	};
}
