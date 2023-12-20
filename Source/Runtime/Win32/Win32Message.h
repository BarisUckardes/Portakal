#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Message/MessageFlags.h>

namespace Portakal
{
	class RUNTIME_API Win32Message final
	{
	public:
		static void Show(const String& title, const String& message, const MessageFlags flags);
	public:
		Win32Message() = delete;
		~Win32Message() = delete;
	};
}
