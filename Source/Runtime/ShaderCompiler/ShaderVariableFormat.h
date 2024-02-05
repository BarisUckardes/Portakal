#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Variable data formats for a shader field
	/// </summary>
	enum class RUNTIME_API ShaderVariableFormat : Byte
	{
		Bool8,
		UInt8,
		Int8,
		UInt16,
		Int16,
		UInt32,
		Int32,
		UInt64,
		Int64,
		Float32,
		Float64
	};
}
