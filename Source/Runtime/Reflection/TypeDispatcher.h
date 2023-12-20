#pragma once
#include <Runtime/Reflection/Type.h>

namespace Portakal
{
	class RUNTIME_API TypeDispatcher final
	{
	public:
		static Type* CreateType(const String& name, const uint32, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator);
	public:
		TypeDispatcher() = delete;
		~TypeDispatcher() = delete;
	};
}
