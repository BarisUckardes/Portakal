#pragma once
#include <Runtime/Core/Core.h>
#include "CompareOperation.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API CompareOperation : Int64
	{
		Never,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreaterEqual,
		Always
	};

	GENERATE_FLAGS(CompareOperation, Byte);
}

