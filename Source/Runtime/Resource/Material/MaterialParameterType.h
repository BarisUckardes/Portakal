#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Available material parameter slot types
	/// </summary>
	enum class RUNTIME_API MaterialParameterType : Int64
	{
		None,
		Texture,
		Sampler,
		Buffer
	};
}
