#include "BasicRenderAspect.h"
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Runtime/World/Scene.h>
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>

namespace Portakal
{
    static const Char gTestVertexShader[] = R""""(
			layout(set=0,binding=0) cbuffer vertexBuffer
            {
              float4x4 ProjectionMatrix;
            };
            struct VS_INPUT
            {
              float2 pos : POSITION;
              float2 uv  : TEXCOORD0;
              float4 col : COLOR0;
            };
            
            struct PS_INPUT
            {
              float4 pos : SV_POSITION;
              float2 uv  : TEXCOORD0;
              float4 col : COLOR0;
            };
            
            PS_INPUT main(VS_INPUT input)
            {
              PS_INPUT output;
              output.pos = mul( ProjectionMatrix, float4(input.pos.xy, 0.f, 1.f));
              output.col = input.col;
              output.uv  = input.uv;
              return output;
            }
)"""";;    static const Char gTestFragmentShader[] = R""""(
			struct PS_INPUT
            {
				float4 pos : SV_POSITION;
				float2 uv  : TEXCOORD0;
				float4 col : COLOR0;
            };
            layout(set=0,binding=1) sampler sampler0;
            layout(set=1,binding=0) Texture2D texture0;
            
            float4 main(PS_INPUT input) : SV_Target
            {
				float4 out_col =  input.col*texture0.Sample(sampler0,input.uv); 
				return out_col; 
            }
)"""";;
    void BasicRenderAspect::RegisterCamera(const BasicCamera* pCamera)
    {
        mCameras.Add(pCamera);
    }
    void BasicRenderAspect::RemoveCamera(const BasicCamera* pCamera)
    {
        mCameras.Remove(pCamera);
    }
    void BasicRenderAspect::RegisterRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Add(pRenderable);
    }
    void BasicRenderAspect::RemoveRenderable(const BasicRenderable* pRenderable)
    {
        mRenderables.Remove(pRenderable);
    }
    void BasicRenderAspect::OnInitialize()
    {
        //Load test mesh
        //Load test textures
        //Load&Create test shaders
		MemoryOwnedView* pVertexSPIRVBytes = nullptr;
		MemoryOwnedView* pFragmentSPIRVBytes = nullptr;

		ShaderCompiler::CompileToSPIRV(gTestVertexShader, "main", ShaderStage::VertexStage, ShaderLanguage::HLSL, &pVertexSPIRVBytes);
		ShaderCompiler::CompileToSPIRV(gTestFragmentShader, "main", ShaderStage::FragmentStage, ShaderLanguage::HLSL, &pFragmentSPIRVBytes);

		MemoryOwnedView* pVertexPlatformBytes = nullptr;
		MemoryOwnedView* pFragmentPlatformBytes = nullptr;

		const GraphicsBackend backend = GraphicsAPI::GetDefaultDevice()->GetBackend();
		ShaderCompiler::CompileFromSPIRV(pVertexSPIRVBytes, backend, &pVertexPlatformBytes);
		ShaderCompiler::CompileFromSPIRV(pFragmentSPIRVBytes, backend, &pFragmentPlatformBytes);

		ShaderDesc vertexShaderDesc = {};
		vertexShaderDesc.EntryPoint = "main";
		vertexShaderDesc.Language = ShaderLanguage::HLSL;
		vertexShaderDesc.Stage = ShaderStage::VertexStage;
		vertexShaderDesc.ByteCode = pVertexPlatformBytes;
		mVertexShader = GraphicsAPI::GetDefaultDevice()->CreateShader(vertexShaderDesc);

		ShaderDesc fragmentShaderDesc = {};
		fragmentShaderDesc.EntryPoint = "main";
		fragmentShaderDesc.Language = ShaderLanguage::HLSL;
		fragmentShaderDesc.Stage = ShaderStage::FragmentStage;
		fragmentShaderDesc.ByteCode = pFragmentPlatformBytes;
		mFragmentShader = GraphicsAPI::GetDefaultDevice()->CreateShader(fragmentShaderDesc);

		//Create mesh
        //Create textures
    }
	
    void BasicRenderAspect::OnExecute()
    {
		Scene* pScene = GetOwnerScene();
		DisplayAspect* pAspect = pScene->GetAspect<DisplayAspect>();
		if (pAspect == nullptr)
			return;

		SharedHeap<RenderTargetResource> pRenderTarget = pAspect->GetPrimaryDisplay();
		if (pRenderTarget.IsShutdown())
			return;

		if (mTexture.IsShutdown())
		{
			mTexture = new TextureResource();
			mTexture->Wrap(pRenderTarget->GetColorTargets()[0]);
			mTexture->CreateView(0, 0);

			CommandPoolDesc cmdPoolDesc = {};
			cmdPoolDesc.Type = CommandPoolType::Graphics;
			mCmdPool = GraphicsAPI::GetDefaultDevice()->CreateCommandPool(cmdPoolDesc);

			CommandListDesc cmdListDesc = {};
			cmdListDesc.pPool = mCmdPool;
			mCmdList = GraphicsAPI::GetDefaultDevice()->CreateCommandList(cmdListDesc);
		}

		//Render to target
		mCmdList->BeginRecording();
		CommandListTextureMemoryBarrierDesc preMemoryBarrierDesc = {};
		preMemoryBarrierDesc.ArrayIndex = 0;
		preMemoryBarrierDesc.MipIndex = 0;
		preMemoryBarrierDesc.AspectFlags = TextureAspectFlags::Color;
		preMemoryBarrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
		preMemoryBarrierDesc.SourceLayout = TextureMemoryLayout::Unknown;
		preMemoryBarrierDesc.SourceQueue = GraphicsQueueType::Graphics;
		preMemoryBarrierDesc.SourceStageFlags = PipelineStageFlags::Transfer;
		preMemoryBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
		preMemoryBarrierDesc.DestinationLayout = TextureMemoryLayout::TransferDestination;
		preMemoryBarrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
		preMemoryBarrierDesc.DestinationStageFlags = PipelineStageFlags::Transfer;
		mCmdList->SetTextureMemoryBarrier(mTexture->GetTexture().GetHeap(), preMemoryBarrierDesc);
		mCmdList->ClearTexture(mTexture->GetTexture().GetHeap(), 0, 0, Color4F::CornflowerBlue());
		CommandListTextureMemoryBarrierDesc postMemoryBarrierDesc = {};
		postMemoryBarrierDesc.ArrayIndex = 0;
		postMemoryBarrierDesc.MipIndex = 0;
		postMemoryBarrierDesc.AspectFlags = TextureAspectFlags::Color;
		postMemoryBarrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
		postMemoryBarrierDesc.SourceLayout = TextureMemoryLayout::Unknown;
		postMemoryBarrierDesc.SourceQueue = GraphicsQueueType::Graphics;
		postMemoryBarrierDesc.SourceStageFlags = PipelineStageFlags::Transfer;
		postMemoryBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ShaderRead;
		postMemoryBarrierDesc.DestinationLayout = TextureMemoryLayout::ShaderReadOnly;
		postMemoryBarrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
		postMemoryBarrierDesc.DestinationStageFlags = PipelineStageFlags::FragmentShader;
		mCmdList->SetTextureMemoryBarrier(mTexture->GetTexture().GetHeap(), postMemoryBarrierDesc);
		mCmdList->EndRecording();
		GraphicsAPI::GetDefaultDevice()->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, nullptr);
    }
}
