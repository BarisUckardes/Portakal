#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include "ShaderResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API ShaderResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
		ShaderResource(const SharedHeap<GraphicsDevice>& pDevice);
		ShaderResource();
		~ShaderResource() = default;

		FORCEINLINE SharedHeap<Shader> GetShader() const noexcept
		{
			return mShader;
		}
		FORCEINLINE String GetSource() const noexcept
		{
			return mSource;
		}

		void CompileShader(const String& source,const String& entryMethod, const ShaderLanguage language, const ShaderStage stage);
		void Clear();
	private:
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<Shader> mShader;
		String mSource;
	};
}

