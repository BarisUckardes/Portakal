#include "Memory.h"

namespace Portakal
{
	void Memory::Copy(void* pDestination, const void* pSource, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			((byte*)(pDestination))[i] = ((byte*)(pSource))[i];
	}
	bool Memory::Check(const void* pA, const void* pB, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			if (((byte*)(pA))[i] != ((byte*)(pB))[i])
				return false;

		return true;
	}
	void Memory::Set(void* pDestination, const byte value, const uint64 sizeInBytes)
	{
		for (uint64 i = 0; i < sizeInBytes; i++)
			((byte*)(pDestination))[i] = value;
	}
}
