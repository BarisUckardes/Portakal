#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	/// <summary>
	/// Error platform implementation
	/// </summary>
	class RUNTIME_API PlatformError final
	{
	public:
		static String GetCurrentError();
	public:
		PlatformError() = delete;
		~PlatformError() = delete;
	};
}
