#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Enum data type
	/// </summary>
	enum class RUNTIME_API EnumDataType : Byte
	{
		Byte,
		Char,
		UInt16,
		Int16,
		UInt32,
		Int32,
		UInt64,
		Int64
	};
}