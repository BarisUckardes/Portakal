#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Shader/ShaderDesc.h>

namespace Portakal
{
    class RUNTIME_API Shader : public GraphicsDeviceObject {
    public:
        Shader(const ShaderDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mStage(desc.Stage), mEntryPoint(desc.EntryPoint),mLanguage(desc.Language)
        {

        }

        virtual ~Shader() = default;

        FORCEINLINE ShaderStage GetStage() const { return mStage; }
        FORCEINLINE ShaderLanguage GetLanguage() const noexcept { return mLanguage; }
        FORCEINLINE String GetEntryPoint() const { return mEntryPoint; }

        FORCEINLINE virtual GraphicsDeviceObjectType
        GetObjectType() const noexcept override { return GraphicsDeviceObjectType::Shader; }

    private:
        const ShaderStage mStage;
        const ShaderLanguage mLanguage;
        const String mEntryPoint;
    };

}