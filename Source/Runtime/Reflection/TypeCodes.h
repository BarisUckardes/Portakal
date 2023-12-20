#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API TypeCodes : byte
	{
		Void,
		Composed,
		String,
		Char,
		Byte,
		Int16,
		UInt16,
		Int32,
		UInt32,
		Int64,
		UInt64,
		Float,
		Double
	};
}