#include "Type.h"
#include <Runtime/Reflection/Field.h>

namespace Portakal
{
    Type::Type(const String& name, const uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator,Type** ppModuleAddress) :
        mName(name), mSize(size), mMode(mode), mCode(code), mDefaultObjectGenerator(defaultObjectGenerator),mBaseType(nullptr),mModuleAddress(ppModuleAddress)
    {

    }
    Type::~Type()
    {
        //Do something here
    }
    void Type::_RegisterEnum(const String& name, const int64 value)
    {
        mEnums.Add({ name,value });
    }
    void Type::_RegisterField(Field* pField)
    {
        mFields.Add(pField);
    }
    void Type::_SetBaseType(Type* pType)
    {
        mBaseType = pType;
    }
    void Type::_RegisterAttribute(Attribute* pAttribute)
    {
        mAttributes.Add(pAttribute);
    }
}
