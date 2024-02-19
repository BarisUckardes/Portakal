#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// General type codes
	/// </summary>
	enum class RUNTIME_API TypeCodes : Byte
	{
		Void,
		Composed,
		String,
		Char,
		Byte,
		Bool,
		Int16,
		UInt16,
		Int32,
		UInt32,
		Int64,
		UInt64,
		Float32,
		Double
	};
}