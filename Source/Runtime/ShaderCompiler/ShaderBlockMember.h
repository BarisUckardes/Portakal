#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API ShaderBlockMember
	{
		String Name;
		UInt32 Offset;
		UInt32 AbsoluteOffset;
		UInt32 Size;
		UInt32 PaddedSize;
		Array<ShaderBlockMember> Members;
	};
}
