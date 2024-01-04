#pragma once
#include <Runtime/Platform/PlatformType.h>

namespace Portakal
{
	class RUNTIME_API Platform final
	{
	public:
		static PlatformType GetCurrentPlatform();
		static Bool8 InitializePlatformDependencies(const String& executablePath);
	public:
		Platform() = delete;
		~Platform() = delete;
	};
}
