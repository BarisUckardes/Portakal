#include "Field.h"

namespace Portakal
{
	Field::Field(const String& name, const Type* pFieldType, const Type* pArrayElementType, const FieldMode mode, const uint32 offset) :
		mName(name),mFieldType(pFieldType),mArrayElementType(pArrayElementType),mMode(mode),mOffset(offset)
	{

	}
	Field::~Field()
	{

	}
}
