#include "Memory.h"

namespace Portakal
{
#ifdef PORTAKAL_PLATFORM_WINDOWS
	void Memory::Copy(void* __restrict pDestination, const void* __restrict pSource, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			((byte*)(pDestination))[i] = ((byte*)(pSource))[i];
	}
	bool Memory::Check(const void* __restrict pA, const void* __restrict pB, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			if (((byte*)(pA))[i] != ((byte*)(pB))[i])
				return false;

		return true;
	}
	void Memory::Set(void* __restrict pDestination, const byte pValue, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			((byte*)(pDestination))[i] = pValue;
	}
#endif
}
