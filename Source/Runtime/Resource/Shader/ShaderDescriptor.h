#pragma once
#include <Runtime/Containers/String.h>
#include "ShaderDescriptor.reflected.h"
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>

namespace Portakal
{
	PCLASS();

	/// <summary>
	/// Descriptor for shader
	/// </summary>
	struct RUNTIME_API ShaderDescriptor
	{
		PFIELD();
		String Source;
		PFIELD();
		String EntryMethodName;
		PFIELD();
		ShaderStage Stage;
		PFIELD();
		ShaderLanguage Language;
	};
}

