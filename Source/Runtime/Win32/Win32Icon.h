#pragma once
#include <Runtime/Containers/String.h>
#include <RUntime/Platform/PlatformWindow.h>

namespace Portakal
{
	class RUNTIME_API Win32Icon final
	{
	public:
		static bool LoadIconFromPath(const String& path, const PlatformWindow* pTargetWindow);
	public:
		Win32Icon() = delete;
		~Win32Icon() = delete;
	};
}
