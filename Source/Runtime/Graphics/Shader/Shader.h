#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Shader/ShaderDesc.h>

namespace Portakal
{
	class RUNTIME_API Shader : public GraphicsDeviceObject
	{
	public:
		~Shader();

		FORCEINLINE ShaderStage GetStage() const noexcept
		{
			return mStage;
		}
		FORCEINLINE String GetEntryMethod() const noexcept
		{
			return mEntryMethod;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept
		{
			return GraphicsDeviceObjectType::Shader;
		}
	protected:
		Shader(const ShaderDesc& desc, GraphicsDevice* pDevice);
	private:
		const ShaderStage mStage;
		const String mEntryMethod;
	};
}
