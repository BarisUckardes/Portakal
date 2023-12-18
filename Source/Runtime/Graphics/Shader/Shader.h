#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Shader/ShaderDesc.h>

namespace Portakal
{
    class RUNTIME_API Shader : public GraphicsDeviceObject {
    public:
        Shader(const ShaderDesc& desc) : mStage(desc.Stage), mEntryPoint(desc.EntryPoint), mByteCode(desc.ByteCode) {}

        virtual ~Shader() = default;

        FORCEINLINE const ShaderStage GetStage() const { return mStage; }

        FORCEINLINE const String& GetEntryPoint() const { return mEntryPoint; }

        FORCEINLINE const MemoryView& GetByteCode() const { return mByteCode; }

        FORCEINLINE virtual GraphicsDeviceObjectType
        GetObjectType() const noexcept override { return GraphicsDeviceObjectType::Shader; }

    private:
        const ShaderStage mStage;
        const String mEntryPoint;
        const MemoryView mByteCode;
    };

}