#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	/// <summary>
	/// Represents a buffer block member of a shader reflection binding
	/// </summary>
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
