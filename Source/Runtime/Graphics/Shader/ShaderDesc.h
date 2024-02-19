#pragma once
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Containers/String.h>

namespace Portakal
{
	struct RUNTIME_API ShaderDesc
	{
		ShaderStage Stage;
		String EntryMethod;
		Byte* pByteCode;
		UInt64 ByteCodeLength;
	};
}
