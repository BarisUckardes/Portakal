#include "Type.h"

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
    void Type::_RegisterField(const String& name, const uint32 offset, Type* pFieldType, Type* pTargetType)
    {

    }
    void Type::_SetBaseType(Type* pType)
    {
        mBaseType = pType;
    }
}
