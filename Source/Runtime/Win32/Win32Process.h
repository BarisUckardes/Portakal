#pragma once
#include <Runtime/Platform/PlatformProcess.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Process : public PlatformProcess
	{
	public:
		Win32Process(const String& path, const String& command);
		~Win32Process();

	private:
		virtual void Terminate() override;
		virtual void WaitForFinish() override;
	private:
		PROCESS_INFORMATION mInformation;
	};
}
