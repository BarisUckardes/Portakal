#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Memory utility tool
	/// </summary>
	class RUNTIME_API Memory final
	{
	public:
		static void Copy(void* pDestination, const void* pSource, const uint64 sizeInBytes);
		static bool Check(const void* pA, const void* pB, const uint64 sizeInBytes);
		static void Set(void* pDestination, const byte value, const uint64 sizeInBytes);
	public:
		Memory() = delete;
		~Memory() = delete;
	};
}
