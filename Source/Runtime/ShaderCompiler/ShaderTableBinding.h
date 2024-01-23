#pragma once
#include <Runtime/ShaderCompiler/ShaderTableBindingType.h>
#include <Runtime/ShaderCompiler/ShaderBlockMember.h>
#include <Runtime/Containers/String.h>

namespace Portakal
{
	struct RUNTIME_API ShaderTableBinding
	{
		UInt32 BindingIndex;
		ShaderTableBindingType Type;
		String Name;
		ShaderBlockMember BlockMember;
	};
}
