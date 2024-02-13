#pragma once
#include <Runtime/Platform/PlatformType.h>

namespace Portakal
{
	/// <summary>
	/// Main platform utilities
	/// </summary>
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
