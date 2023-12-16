#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API PlatformIcon
	{
	public:
		static void LoadIconFromPath(const String& path);
	public:
		PlatformIcon() = delete;
		~PlatformIcon() = delete;
	};
}
