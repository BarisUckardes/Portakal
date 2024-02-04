#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/ShaderCompiler/ShaderReflection.h>
#include <Runtime/Event/Event.h>
#include "ShaderResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API ShaderResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
		ShaderResource();
		~ShaderResource() = default;

		FORCEINLINE SharedHeap<Shader> GetShader() const noexcept
		{
			return mShader;
		}
		FORCEINLINE SharedHeap<ShaderReflection> GetReflection() const noexcept
		{
			return mReflection;
		}
		FORCEINLINE String GetSource() const noexcept
		{
			return mSource;
		}
		FORCEINLINE String GetEntryPoint() const noexcept
		{
			return mEntryPoint;
		}
		FORCEINLINE ShaderLanguage GetLanguage() const noexcept
		{
			return mLanguage;
		}
		FORCEINLINE ShaderStage GetStage() const noexcept
		{
			return mStage;
		}
		FORCEINLINE String GetErrorMessage() const noexcept
		{
			return mErrorMessage;
		}

		bool CompileShader(const String& source,const String& entryMethod, const ShaderLanguage language, const ShaderStage stage);
		void Clear();
		void RegisterOnNewShadersEvent(const Delegate<void, ShaderResource*>& del);
		void RemoveOnNewShadersEvent(const Delegate<void, ShaderResource*>& del);
	private:
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<Shader> mShader;
		SharedHeap<ShaderReflection> mReflection;
		String mSource;
		String mEntryPoint;
		String mErrorMessage;
		ShaderLanguage mLanguage;
		ShaderStage mStage;
		Event<void, ShaderResource*> mOnNewShadersEvent;
	};
}

