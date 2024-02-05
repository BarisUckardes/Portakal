#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Available shader binding types for resources
	/// </summary>
	enum class RUNTIME_API ShaderTableBindingType : Byte
	{
		None,
		ConstantBuffer,
		Texture,
		Sampler
	};
}
