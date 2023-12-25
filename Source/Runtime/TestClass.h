#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Reflection/Reflection.h>
#include "TestClass.reflected.h"

namespace Portakal
{
	class MyAttribute : public Attribute
	{
	public:
		MyAttribute(uint32 a,uint32 b,uint32 c)
		{
			a = a;
			b = b;
			c = c;
		}

	private:
		uint32 a;
		uint32 b;
		uint32 c;
	};

	PCLASS();
	PATTRIBUTE(MyAttribute, 1, 2, 3);
	PATTRIBUTE(MyAttribute, 2, 5, 7);
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








































































