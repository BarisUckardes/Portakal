#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/ShaderCompiler/ShaderTableBinding.h>

namespace Portakal
{
	struct RUNTIME_API ShaderTableDescriptor
	{
		UInt32 TableIndex;
		Array<ShaderTableBinding> Bindings;
	};
}
