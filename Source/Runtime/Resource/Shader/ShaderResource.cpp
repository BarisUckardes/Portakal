#include "ShaderResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>

namespace Portakal
{
	ShaderResource::ShaderResource() : mLanguage(ShaderLanguage::Unknown),mStage(ShaderStage::VertexStage)
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
		if (!ShaderCompiler::CompileFromSPIRV(pSPIRVBytes, mDevice->GetBackend(), &pPlatformBytes))
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

		//Generate reflection
		mReflection = ShaderCompiler::GenerateReflection(pSPIRVBytes);

		//Set properties
		mSource = source;
		mEntryPoint = entryMethod;
		mLanguage = language;
		mStage = mStage;
	}

	
	void ShaderResource::Clear()
	{
		mSource = "";
		mEntryPoint = "";
		mLanguage = ShaderLanguage::Unknown;
		mStage = ShaderStage::VertexStage;
		mReflection.Deference();

		mShader.Shutdown();
	}
	void ShaderResource::OnShutdown()
	{
		Clear();
	}
}
