#include "TypeDispatcher.h"

namespace Portakal
{
	Type* TypeDispatcher::CreateType(const String& name, const uint32 s,ze, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator)
	{
		return new Type(name,size,mode,code,generator);
	}
}
