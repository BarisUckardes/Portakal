#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class Type;
	class RUNTIME_API Class
	{
	public:
		FORCEINLINE virtual const Type* GetType() const noexcept { return nullptr; }
	};
}