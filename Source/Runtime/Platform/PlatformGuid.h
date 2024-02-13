#pragma once
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	/// <summary>
	/// Guid platform implementation
	/// </summary>
	class RUNTIME_API PlatformGuid final
	{
	public:
		static void Create(Guid& id);
	public:
		PlatformGuid() = delete;
		~PlatformGuid() = delete;
	};
}
