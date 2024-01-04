#include "Type.h"
#include <Runtime/Reflection/Field.h>

namespace Portakal
{
    void* Type::CreateDefaultHeapObject() const noexcept
    {
        return mDefaultObjectGenerator();
    }
    Bool8 Type::IsSubClassOf(const Type* pType) const noexcept
    {
        if (pType == mBaseType)
            return true;
        if (mBaseType == nullptr)
            return false;

        return mBaseType->IsSubClassOf(pType);
    }
    Type::Type(const String& name, const Uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator,Type** ppModuleAddress) :
        mName(name), mSize(size), mMode(mode), mCode(code), mDefaultObjectGenerator(defaultObjectGenerator),mBaseType(nullptr),mModuleAddress(ppModuleAddress)
    {

    }
    Type::~Type()
    {
        //Do something here
    }
    void Type::_RegisterEnum(const String& name, const Int64 value)
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
