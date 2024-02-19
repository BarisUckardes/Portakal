#include "Shader.h"

namespace Portakal
{
	Shader::~Shader()
	{

	}
	Shader::Shader(const ShaderDesc& desc, GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mStage(desc.Stage),mEntryMethod(desc.EntryMethod)
	{

	}
}
