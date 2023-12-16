#pragma once
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	class RUNTIME_API PlatformGuid final
	{
	public:
		static void Create(Guid& id);
	public:
		PlatformGuid() = delete;
		~PlatformGuid() = delete;
	};
}
