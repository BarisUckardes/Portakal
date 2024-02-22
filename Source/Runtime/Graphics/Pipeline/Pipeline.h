#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Pipeline/GraphicsPipelineDesc.h>
#include <Runtime/Graphics/Pipeline/ComputePipelineDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    /**
     * @class Pipeline
     * 
     * @brief Pipeline is a specific device object to define every configuration 
     * of the related graphics component. For example, for some objects types, there 
     * may be multiple graphics pipeline objects or for some deep calculations 
     * we may need multiple compute pipeline objects. 
     * 
     * All the files in the subfolders of pipeline are specific descriptors to define every 
     * aspect of the pipeline stages which includes Input Layout, Blend State, Rasterizer State, 
     * Multisample State, Depth Stencil State, Output State and also Resource Layout to 
     * define the resources according to the pipeline they will be processed.
     * 
     */
    class RUNTIME_API Pipeline : public GraphicsDeviceObject
    {
    public:
        Pipeline(const GraphicsPipelineDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mBindPoint(PipelineBindPoint::Graphics),
            mBlendState(desc.BlendState), mDepthStencilState(desc.DepthStencilState),
            mInputLayout(desc.InputLayout), mMultisample(desc.Multisample),
            mRasterizerState(desc.RasterizerState),
            mResourceLayout(desc.ResourceLayout), mGraphicsShaders(desc.GraphicsShaders),mSubpassIndex(desc.SubpassIndex)
        {
        }

        Pipeline(const ComputePipelineDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice), mBindPoint(PipelineBindPoint::Compute),
            mBlendState(), mDepthStencilState(),
            mInputLayout(), mMultisample(),
            mRasterizerState(),
            mResourceLayout(), mComputeShaders({ desc.ComputeShader }),mSubpassIndex(255)
        {
        }

        ~Pipeline() = default;

        FORCEINLINE PipelineBindPoint GetBindPoint() const
        {
            return mBindPoint;
        }
        FORCEINLINE const BlendStateDesc& GetBlendState() const
        {
            return mBlendState;
        }
        FORCEINLINE const DepthStencilStateDesc& GetDepthStencilState() const
        {
            return mDepthStencilState;
        }
        FORCEINLINE const InputLayoutDesc& GetInputLayout() const
        {
            return mInputLayout;
        }
        FORCEINLINE const MultisampleDesc& GetMultisample() const
        {
            return mMultisample;
        }
        FORCEINLINE const RasterizerStateDesc& GetRasterizerState() const
        {
            return mRasterizerState;
        }
        FORCEINLINE const ResourceLayoutDesc& GetResourceLayout() const
        {
            return mResourceLayout;
        }
        FORCEINLINE const Array<SharedHeap<Shader>>& GetGraphicsShaders() const
        {
            return mGraphicsShaders;
        }
        FORCEINLINE const Array<SharedHeap<Shader>>& GetComputeShader() const
        {
            return mComputeShaders;
        }
        FORCEINLINE Byte GetSubpassIndex() const noexcept
        {
            return mSubpassIndex;
        }

        FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
        {
            return GraphicsDeviceObjectType::Pipeline;
        }

    private:
        const PipelineBindPoint mBindPoint;
        const BlendStateDesc mBlendState;
        const DepthStencilStateDesc mDepthStencilState;
        const InputLayoutDesc mInputLayout;
        const MultisampleDesc mMultisample;
        const RasterizerStateDesc mRasterizerState;
        const ResourceLayoutDesc mResourceLayout;
        const Array<SharedHeap<Shader>> mGraphicsShaders;
        const Array<SharedHeap<Shader>> mComputeShaders;
        const Byte mSubpassIndex;
    };

}
