#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Reflection/Reflection.h>
#include "TestClass.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API TestClass : public Object
	{
		GENERATE_OBJECT;
	public:

	public:
		PFIELD();
		uint32 mMyType;
		PFIELD();
		String mMahString;
	};
}




























































































