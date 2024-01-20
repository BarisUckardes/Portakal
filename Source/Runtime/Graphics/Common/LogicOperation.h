#pragma once
#include <Runtime/Core/Core.h>
#include "LogicOperation.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API LogicOperation : Int64
	{
		Clear,
		Set,
		Copy,
		CopyInverted,
		NoOp,
		Invert,
		And,
		NotAnd,
		Or,
		Nor,
		Xor,
		Equal,
		AndReverse,
		AndInverted,
		OrReverse,
		OrInverted
	};

	GENERATE_FLAGS(LogicOperation, Byte);
}

