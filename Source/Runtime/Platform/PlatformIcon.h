#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Platform/PlatformWindow.h>

namespace Portakal
{
	/// <summary>
	/// Icon platform implementation
	/// </summary>
	class RUNTIME_API PlatformIcon
	{
	public:
		static Bool8 LoadIconFromPath(const String& path,const PlatformWindow* pTargetWindow);
	public:
		PlatformIcon() = delete;
		~PlatformIcon() = delete;
	};
}
