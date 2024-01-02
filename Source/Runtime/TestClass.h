#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/MyAttribute.h>
#include "TestClass.reflected.h"

namespace Portakal
{
	PATTRIBUTE(MyAttribute,);
	PCLASS();
	class RUNTIME_API TestClass : public Object
	{
		GENERATE_OBJECT;
	public:

		virtual void OnShutdown() override
		{

		}
	public:
		PFIELD();
		uint32 mMyType;
		PFIELD();
		String mMahString;
		PFIELD();
		SharedHeap<String> mMahObjectString;
		PFIELD();
		Array<String> mMahArray;
	};
}
































































































































































