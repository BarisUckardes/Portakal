#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/ShaderCompiler/ShaderVariableFormat.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>

namespace Portakal
{
	/// <summary>
	/// Single vertex input output semantic for shader reflection works
	/// </summary>
	struct RUNTIME_API ShaderIODescriptor
	{
		String Name;
		TextureFormat Format;
	};
}
