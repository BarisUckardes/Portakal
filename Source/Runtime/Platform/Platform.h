#pragma once
#include <Runtime/Platform/PlatformType.h>

namespace Portakal
{
	class RUNTIME_API Platform final
	{
	public:
		static PlatformType GetCurrentPlatform();
		static bool InitializePlatformDependencies();
	public:
		Platform() = delete;
		~Platform() = delete;
	};
}
