#pragma once
#include <Runtime/Platform/PlatformMutex.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Mutex : public PlatformMutex
	{
	public:
		Win32Mutex();
		~Win32Mutex() = default;

		FORCEINLINE HANDLE GetWin32Handle() const noexcept
		{
			return mHandle;
		}

		virtual MutexState Lock(const uint64 timeInMs) override;
		virtual bool Release() override;
		virtual void OnShutdown() override;
	private:
		HANDLE mHandle;
	};
}