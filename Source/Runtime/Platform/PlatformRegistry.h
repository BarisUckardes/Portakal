#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API PlatformRegistry final
	{
	public:
		static void CreateKey(const String& position);
		static void SetValue(const String& position, const String& valueName, const String& value);
	public:
		PlatformRegistry() = delete;
		~PlatformRegistry() = delete;
	};
}
