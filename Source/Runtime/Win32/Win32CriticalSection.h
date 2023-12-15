#pragma once
#include <Runtime/Platform/PlatformCriticalSection.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32CriticalSection : public PlatformCriticalSection
	{
	public:
		Win32CriticalSection();
		~Win32CriticalSection() = default;

	private:
		void OnShutdown() override;
		void OnNameChange(const String& name) override;
		bool TryEnter() override;
		void Enter() override;
		void Leave() override;
	private:
		CRITICAL_SECTION mCS;
	};
}
