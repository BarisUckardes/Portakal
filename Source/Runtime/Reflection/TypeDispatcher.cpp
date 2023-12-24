#include "TypeDispatcher.h"

namespace Portakal
{
	Type* TypeDispatcher::CreateType(const String& name, const uint32 size, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator,Type** ppAddress)
	{
		return new Type(name,size,mode,code,generator,ppAddress);
	}
	void TypeDispatcher::RegisterEnum(const String& name, const int64 value, Type* pTargetType)
	{
		pTargetType->_RegisterEnum(name, value);
	}
	void TypeDispatcher::RegisterField(const String& name, const uint32 offset, Type* pFieldType, Type* pTargetType)
	{
	}
	void TypeDispatcher::SetBaseType(Type* pTargetType, Type* pBaseType)
	{
		pTargetType->_SetBaseType(pBaseType);
	}
	Type** TypeDispatcher::GetTypeAddress(Type* pType)
	{
		return pType->mModuleAddress;
	}
}
