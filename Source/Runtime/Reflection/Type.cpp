#include "Type.h"

namespace Portakal
{
    Type::Type(const String& name, const uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator, const Array<Field*>& fields, const Array<Attribute*>& attributes, const Array<EnumValue>& enumValues, Type** ppModuleAddress):
        mName(name),mSize(size),mMode(mode),mCode(code),mDefaultObjectGenerator(defaultObjectGenerator),mFields(fields),mAttributes(attributes),mEnums(enumValues),mModuleAddress(ppModuleAddress)
    {

    }
    Type::~Type()
    {
        //Do something here
    }
}
