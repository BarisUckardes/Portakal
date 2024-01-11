#pragma once
#include <Runtime/Platform/PlatformThread.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Thread : public PlatformThread
	{
	public:
		static void SleepCurrentThread(const UInt64 ms);
	private:
		static void DispatchThread(void* pSelf);
	public:
		Win32Thread(const UInt64 stackSize,const SharedHeap<ThreadJob>& pJob);
		~Win32Thread() = default;

		FORCEINLINE HANDLE GetWin32Handle() const noexcept
		{
			return mHandle;
		}
	private:
		HANDLE mHandle;
	};
}
