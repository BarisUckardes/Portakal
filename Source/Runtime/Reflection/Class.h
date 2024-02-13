#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class Type;

	/// <summary>
	/// Root class for all reflectable objects
	/// </summary>
	class RUNTIME_API Class
	{
	public:
		FORCEINLINE virtual Type* GetType() const noexcept { return nullptr; }
	};
}