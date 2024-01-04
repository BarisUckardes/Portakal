#include "TypeDispatcher.h"
#include <RUntime/Reflection/Field.h>
namespace Portakal
{
	Type* TypeDispatcher::CreateType(const String& name, const Uint32 size, const TypeModes mode, const TypeCodes code, const DefaultHeapObjectGenerator generator,Type** ppAddress)
	{
		return new Type(name,size,mode,code,generator,ppAddress);
	}
	void TypeDispatcher::RegisterEnum(const String& name, const Int64 value, Type* pTargetType)
	{
		pTargetType->_RegisterEnum(name, value);
	}
	void TypeDispatcher::RegisterField(const String& name, const Uint32 offset, Type* pFieldType, const FieldMode mode, Type* pTargetType)
	{
		Field* pField = new Field(name, pFieldType, mode, offset);
		pTargetType->_RegisterField(pField);
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
