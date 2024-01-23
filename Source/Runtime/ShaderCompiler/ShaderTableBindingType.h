#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API ShaderTableBindingType : Byte
	{
		None,
		ConstantBuffer,
		Texture,
		Sampler
	};
}
