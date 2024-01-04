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
		static void Copy(void* __restrict pDestination, const void* __restrict pSource, Uint64 pSizeInBytes);
		static Bool8 Check(const void* __restrict pA, const void* __restrict pB, const Uint64 sizeInBytes);
		static void Set(void* __restrict pDestination, const Byte value, const Uint64 sizeInBytes);
#endif
	public:
		Memory() = delete;
		~Memory() = delete;
	};
}
