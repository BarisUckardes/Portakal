#include "Field.h"

namespace Portakal
{
	Field::Field(const String& name, const Type* pFieldType, const FieldMode mode, const Uint32 offset) :
		mName(name),mFieldType(pFieldType),mMode(mode),mOffset(offset)
	{

	}
	Field::~Field()
	{

	}
}
