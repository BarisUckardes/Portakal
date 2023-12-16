#pragma once
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	class RUNTIME_API Win32Guid final
	{
	public:
		static void Create(Guid& id);
	public:
		Win32Guid() = delete;
		~Win32Guid() = delete;

	};
}
