#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/**
	 * @class Memory
	 * @brief Memory utility tool
	 */
	class RUNTIME_API Memory final
	{
	public:
#ifdef PORTAKAL_PLATFORM_WINDOWS
		static void Copy(void* __restrict pDestination, const void* __restrict pSource, uint64 pSizeInBytes);
		static bool Check(const void* __restrict pA, const void* __restrict pB, const uint64 sizeInBytes);
		static void Set(void* __restrict pDestination, const byte pValue, const uint64 sizeInBytes);
#endif
	public:
		Memory() = delete;
		~Memory() = delete;
	};
}
