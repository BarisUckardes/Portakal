#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	PCLASS();
	class RUNTIME_API TestClass : public Object
	{
	public:

	public:
		PFIELD();
		uint32 mMyType;
		PFIELD();
		String mMahString;

	};
}
