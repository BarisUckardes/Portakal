#include "Type.h"

namespace Portakal
{
    Type::Type(const String& name, const uint32 size, const TypeModes mode, const TypeCodes code, DefaultHeapObjectGenerator defaultObjectGenerator) :
        mName(name), mSize(size), mMode(mode), mCode(code), mDefaultObjectGenerator(defaultObjectGenerator)
    {
    }
    Type::~Type()
    {
        //Do something here
    }
}
