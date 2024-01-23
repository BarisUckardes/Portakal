#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/ShaderCompiler/ShaderVariableFormat.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>

namespace Portakal
{
	struct RUNTIME_API ShaderIODescriptor
	{
		String Name;
		TextureFormat Format;
	};
}
