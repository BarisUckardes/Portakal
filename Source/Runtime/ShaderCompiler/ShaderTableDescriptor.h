#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/ShaderCompiler/ShaderTableBinding.h>

namespace Portakal
{
	/// <summary>
	/// The descriptor of the shader bindings
	/// </summary>
	struct RUNTIME_API ShaderTableDescriptor
	{
		UInt32 TableIndex;
		Array<ShaderTableBinding> Bindings;
	};
}
