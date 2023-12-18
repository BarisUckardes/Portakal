#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API LogicOperation : byte
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
}
