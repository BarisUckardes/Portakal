#include "Memory.h"

namespace Portakal
{
#ifdef PORTAKAL_PLATFORM_WINDOWS
	void Memory::Copy(void* pDestination, const void* pSource, const UInt64 sizeInBytes)
	{
		for (UInt64 i = 0; i < sizeInBytes; i++)
			((Byte*)(pDestination))[i] = ((Byte*)(pSource))[i];
	}
	Bool8 Memory::Check(const void* __restrict pA, const void* __restrict pB, const UInt64 sizeInBytes)
	{
		for (UInt64 i = 0; i < sizeInBytes; i++)
			if (((Byte*)(pA))[i] != ((Byte*)(pB))[i])
				return false;

		return true;
	}
	void Memory::Set(void* __restrict pDestination, const Byte value, const UInt64 sizeInBytes)
	{
		for (UInt64 i = 0; i < sizeInBytes; i++)
			((Byte*)(pDestination))[i] = value;
	}
#endif
}
