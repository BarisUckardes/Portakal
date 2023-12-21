#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API PlatformProcess : public Object
	{
	public:
		PlatformProcess(const String& path, const String& command);
		~PlatformProcess() = default;

		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE String GetCommand() const noexcept
		{
			return mCommand;
		}

		virtual void Terminate() = 0;
		virtual void WaitForFinish() = 0;
	protected:
		virtual void OnShutdown() override;
	private:
		const String mPath;
		const String mCommand;
	};
}
