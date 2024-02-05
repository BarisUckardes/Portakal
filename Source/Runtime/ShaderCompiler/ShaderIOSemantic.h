#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Vertex input semantics for shader reflection works
	/// </summary>
	enum class RUNTIME_API ShaderIOSemantic
	{
        Position,
        Normal,
        Tangent,
        Binormal,
        Color,
        TexCoord
	};
}
