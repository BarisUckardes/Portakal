#include "ShaderResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>

namespace Portakal
{
	ShaderResource::ShaderResource() : mLanguage(ShaderLanguage::Unknown),mStage(ShaderStage::VertexStage)
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}

	bool ShaderResource::CompileShader(const String& source, const String& entryMethod, const ShaderLanguage language, const ShaderStage stage)
	{
		if (IsShutdown())
			return false;
		if (mDevice.IsShutdown())
			return false;
		if (source.GetSize() == 0)
			return false;
		if (entryMethod.GetSize() == 0)
			return false;

		//Clear the former one
		Clear();

		//Compile to spirv
		MemoryOwnedView* pSPIRVBytes = nullptr;
		String errorMessage;
		if (!ShaderCompiler::CompileToSPIRV(source, entryMethod, stage, language, &pSPIRVBytes,mErrorMessage))
		{
			DEV_LOG("ShaderResource", "Failed to compile given shader text to SPIRV");

			//Invoke event
			mOnNewShadersEvent.Invoke(this);
			return false;
		}

		//Compile from spirv
		MemoryOwnedView* pPlatformBytes = nullptr;
		if (!ShaderCompiler::CompileFromSPIRV(pSPIRVBytes, mDevice->GetBackend(), &pPlatformBytes))
		{
			DEV_LOG("ShaderResource", "Failed to compile from SPIRV to platform bytes!");

			//Invoke event
			mOnNewShadersEvent.Invoke(this);
			return false;
		}

		//Create shader
		ShaderDesc desc = {};
		desc.ByteCode = pPlatformBytes;
		desc.Language = language;
		desc.EntryPoint = entryMethod;
		desc.Stage = stage;
		mShader = mDevice->CreateShader(desc);

		//Generate reflection
		mReflection = ShaderCompiler::GenerateReflectionFromSPIRV(pSPIRVBytes);

		//Delete owned memoris
		delete pSPIRVBytes;
		delete pPlatformBytes;

		//Set properties
		mSource = source;
		mEntryPoint = entryMethod;
		mLanguage = language;
		mStage = mStage;

		//Invoke event
		mOnNewShadersEvent.Invoke(this);

		return true;
	}

	
	void ShaderResource::Clear()
	{
		mSource = "";
		mEntryPoint = "";
		mErrorMessage = "";
		mLanguage = ShaderLanguage::Unknown;
		mStage = ShaderStage::VertexStage;
		mReflection.Deference();

		mShader.Shutdown();
	}
	void ShaderResource::RegisterOnNewShadersEvent(const Delegate<void, ShaderResource*>& del)
	{
		if (IsShutdown())
			return;

		mOnNewShadersEvent += del;
	}
	void ShaderResource::RemoveOnNewShadersEvent(const Delegate<void, ShaderResource*>& del)
	{
		if (IsShutdown())
			return;

		mOnNewShadersEvent -= del;
	}

	void ShaderResource::OnShutdown()
	{
		Clear();
	}
}
