#include "ShaderResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>

namespace Portakal
{
	ShaderResource::ShaderResource(const SharedHeap<GraphicsDevice>& pDevice)
	{
		mDevice = pDevice;
	}
	ShaderResource::ShaderResource()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}

	void ShaderResource::CompileShader(const String& source, const String& entryMethod, const ShaderLanguage language, const ShaderStage stage)
	{
		if (mDevice.IsShutdown())
			return;
		if (source.GetSize() == 0)
			return;
		if (entryMethod.GetSize() == 0)
			return;

		//Clear the former one
		Clear();

		//Compile to spirv
		MemoryOwnedView* pSPIRVBytes = nullptr;
		if (!ShaderCompiler::CompileToSPIRV(source, entryMethod, stage, language, &pSPIRVBytes))
		{
			DEV_LOG("ShaderResource", "Failed to compile given shader text to SPIRV");
			return;
		}

		//Compile from spirv
		MemoryOwnedView* pPlatformBytes = nullptr;
		if (!ShaderCompiler::CompileFromSPIRV(pSPIRVBytes, language, &pPlatformBytes))
		{
			DEV_LOG("ShaderResource", "Failed to compile from SPIRV to platform bytes!");
			return;
		}

		//Create shader
		ShaderDesc desc = {};
		desc.ByteCode = pPlatformBytes;
		desc.Language = language;
		desc.EntryPoint = entryMethod;
		desc.Stage = stage;
		mShader = mDevice->CreateShader(desc);

		mSource = source;
	}

	
	void ShaderResource::Clear()
	{
		mShader.Shutdown();
	}
	void ShaderResource::OnShutdown()
	{
		Clear();
	}
}
