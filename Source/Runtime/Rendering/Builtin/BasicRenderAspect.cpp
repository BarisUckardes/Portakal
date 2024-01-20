#include "BasicRenderAspect.h"
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Runtime/World/Scene.h>
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>
#include <Runtime/Resource/Mesh/MeshLoader.h>
#include <Runtime/Graphics/Texture/TextureLoader.h>
#include <Runtime/Rendering/Builtin/BasicMeshVertex.h>
#include <Runtime/Math/Matrix4x4.h>

namespace Portakal
{
    static const Char gTestVertexShader[] = R""""(
layout(set=0,binding=0) cbuffer vertexBuffer         
{
	float4x4 Mvp;
};
struct VS_INPUT
{
    float3 pos : POSITION;
    float3 normal : NORMAL;
    float3 tangent : TANGENT0;
    float3 bitangent : TANGENT1;
    float2 uv : TEXCOORD0;
};
            
struct PS_INPUT
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
	float3 normal : TEXCOORD1;
	float3 tangent : TEXCOORD2;
	float3 bitangent : TEXCOORD3;
};
            
PS_INPUT main(VS_INPUT input)
{
    PS_INPUT output;
    output.pos = float4(input.pos, 1.0f)*Mvp;
	output.normal = input.normal;
	output.tangent = input.tangent;
	output.bitangent = input.bitangent;
    output.uv = input.uv;
    return output;
}
)"""";;    static const Char gTestFragmentShader[] = R""""(
			struct PS_INPUT
			{
				float4 pos : SV_POSITION;
				float2 uv : TEXCOORD0;
				float3 normal : TEXCOORD1;
			};

          
			float4 main(PS_INPUT input) : SV_Target
			{
				float4 out_col = float4(input.normal,1.0f);
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
		MeshLoadResult meshLoadResult = {};
		MeshLoader::LoadMesh(R"(D:\Projects\glTF-Sample-Models\2.0\DamagedHelmet\glTF\DamagedHelmet.gltf)",meshLoadResult);

        //Load test textures
		TextureLoadResult colorTextureResult = {};
		TextureLoader::LoadFromPath(R"(D:\Projects\glTF-Sample-Models\2.0\DamagedHelmet\glTF\Default_albedo.jpg)", colorTextureResult);

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
		Array<BasicMeshVertex> vertexes;
		Array<UInt32> indexes;
		const SubMeshResult& subMesh = meshLoadResult.Meshes[0];
		const UInt32 vertexCount = subMesh.Positions.GetSize();
		for (UInt32 i = 0; i < vertexCount; i++)
		{
			BasicMeshVertex vertex = {};
			vertex.Position = subMesh.Positions[i];
			vertex.Normal = subMesh.Normals[i];
			vertex.Tangent = subMesh.Tangents[i];
			vertex.Bitangent = subMesh.Bitangents[i];
			vertex.Uv = subMesh.Uvs[0][i];
			vertexes.Add(vertex);
		}
		indexes = subMesh.Indexes;

		GraphicsMemoryHeapDesc deviceHeapDesc = {};
		deviceHeapDesc.Type = GraphicsMemoryType::Device;
		deviceHeapDesc.SizeInBytes = MB_TO_BYTE(2048);
		mDeviceHeap = GraphicsAPI::GetDefaultDevice()->CreateMemoryHeap(deviceHeapDesc);

		GraphicsMemoryHeapDesc hostHeapDesc = {};
		hostHeapDesc.Type = GraphicsMemoryType::Host;
		hostHeapDesc.SizeInBytes = MB_TO_BYTE(2048);
		mHostHeap = GraphicsAPI::GetDefaultDevice()->CreateMemoryHeap(hostHeapDesc);

		mMesh = new MeshResource();
		mMesh->AllocateVertexes(vertexes.GetSize(), sizeof(BasicMeshVertex),mDeviceHeap, mHostHeap, true);
		mMesh->AllocateIndexes(indexes.GetSize(), sizeof(UInt32), mDeviceHeap, mHostHeap, true);

		mMesh->UpdateVertexes({vertexes.GetData(),vertexes.GetSize()*sizeof(BasicMeshVertex)},0);
		mMesh->UpdateIndexes({ indexes.GetData(),indexes.GetSize() * sizeof(UInt32) }, 0);

        //Create textures

		//Command list and fences
		CommandPoolDesc cmdPoolDesc = {};
		cmdPoolDesc.Type = CommandPoolType::Graphics;
		mCmdPool = GraphicsAPI::GetDefaultDevice()->CreateCommandPool(cmdPoolDesc);

		CommandListDesc cmdListDesc = {};
		cmdListDesc.pPool = mCmdPool;
		mCmdList = GraphicsAPI::GetDefaultDevice()->CreateCommandList(cmdListDesc);

		mFence = GraphicsAPI::GetDefaultDevice()->CreateFence();

		//Create buffers
		GraphicsBufferDesc constantBufferDeviceDesc = {};
		constantBufferDeviceDesc.Usage = GraphicsBufferUsage::ConstantBuffer | GraphicsBufferUsage::TransferDestination;
		constantBufferDeviceDesc.SubItemCount = 1;
		constantBufferDeviceDesc.SubItemSizeInBytes = 64;
		constantBufferDeviceDesc.pHeap = mDeviceHeap;
		mConstantBufferDevice = GraphicsAPI::GetDefaultDevice()->CreateBuffer(constantBufferDeviceDesc);

		GraphicsBufferDesc constantBufferHostDesc = {};
		constantBufferHostDesc.Usage = GraphicsBufferUsage::ConstantBuffer | GraphicsBufferUsage::TransferSource;
		constantBufferHostDesc.SubItemCount = 1;
		constantBufferHostDesc.SubItemSizeInBytes = 64;
		constantBufferHostDesc.pHeap = mHostHeap;
		mConstantBufferHost = GraphicsAPI::GetDefaultDevice()->CreateBuffer(constantBufferHostDesc);

		//Create resource table pool
		ResourceTablePoolDesc tablePoolDesc = {};
		tablePoolDesc.MaxTables = 1;
		tablePoolDesc.Entries.Add({GraphicsResourceType::ConstantBuffer,1});
		mResourceTablePool = GraphicsAPI::GetDefaultDevice()->CreateResourceTablePool(tablePoolDesc);

		//Create resource views
		ResourceTableLayoutDesc tableLayoutDesc = {};
		tableLayoutDesc.Entries.Add({GraphicsResourceType::ConstantBuffer,ShaderStage::VertexStage,0});
		mResourceLayout = GraphicsAPI::GetDefaultDevice()->CreateResourceTableLayout(tableLayoutDesc);

		//Create tables
		ResourceTableDesc tableDesc = {};
		tableDesc.pOwnerPool = mResourceTablePool.GetHeap();
		tableDesc.pTargetLayout = mResourceLayout.GetHeap();
		mResourceTable = GraphicsAPI::GetDefaultDevice()->CreateResourceTable(tableDesc);

		//Update resource table
		ResourceTableUpdateDesc tableUpdateDesc = {};
		tableUpdateDesc.Entries.Add({mConstantBufferDevice.QueryAs<GraphicsDeviceObject>(),GraphicsResourceType::ConstantBuffer,1,0,0,0});
		GraphicsAPI::GetDefaultDevice()->UpdateResourceTable(mResourceTable.GetHeap(), tableUpdateDesc);
	}

	bool bInitialized = false;
    void BasicRenderAspect::OnExecute()
    {
		Scene* pScene = GetOwnerScene();
		DisplayAspect* pAspect = pScene->GetAspect<DisplayAspect>();
		if (pAspect == nullptr)
			return;

		SharedHeap<RenderTargetResource> pRenderTarget = pAspect->GetPrimaryDisplay();
		if (pRenderTarget.IsShutdown())
			return;

		if (!bInitialized)
		{
			//Create pipeline
			GraphicsPipelineDesc pipelineDesc = {};

			//Render pass
			pipelineDesc.SubpassIndex = 0;
			pipelineDesc.pRenderPass = pRenderTarget->GetRenderPass();

			//Blend
			BlendStateDesc blendState = {};
			BlendStateAttachment blendAttachment;
			blendAttachment.DestinationColorFactor = BlendFactor::One;
			blendAttachment.SourceColorFactor = BlendFactor::One;
			blendAttachment.ColorOperation = BlendOperation::Add;
			blendAttachment.SourceAlphaFactor = BlendFactor::One;
			blendAttachment.DestinationAlphaFactor = BlendFactor::One;
			blendAttachment.AlphaOperation = BlendOperation::Add;
			blendAttachment.WriteMask = BlendColorWriteMask::All;
			blendAttachment.Enabled = false;
			blendState.Attachments.Add(blendAttachment);
			blendState.bLogicOperationEnabled = false;
			blendState.LogicOperation = LogicOperation::Clear;
			pipelineDesc.BlendState = blendState;

			//Rasterizer
			RasterizerStateDesc rasterizerState = {};
			rasterizerState.IsFrontCounterClockwise = true;
			rasterizerState.FillMode = PolygonMode::Fill;
			rasterizerState.DepthBiasSlope = 0;
			rasterizerState.DepthBiasFactor = 0;
			rasterizerState.DepthBiasEnabled = false;
			rasterizerState.DepthBiasClamp = 0;
			rasterizerState.CullFlags = FaceCullMode::None;
			pipelineDesc.RasterizerState = rasterizerState;

			//Depth stencil
			DepthStencilStateDesc depthStencilState = {};
			depthStencilState.bDepthTestEnabled = false;
			depthStencilState.bDepthWriteEnabled = false;
			depthStencilState.bStencilTestEnabled = false;
			depthStencilState.DepthTestOperation = CompareOperation::Never;
			depthStencilState.StencilFrontFace = {};
			depthStencilState.StencilBackFace = {};
			pipelineDesc.DepthStencilState = depthStencilState;

			//Multipsample
			MultisampleDesc multisampleDesc = {};
			multisampleDesc.bSampleShadingEnabled = false;
			multisampleDesc.Samples = TextureSampleCount::SAMPLE_COUNT_1;
			pipelineDesc.Multisample = multisampleDesc;

			//Viewport
			ViewportDesc viewport = {};
			viewport.DepthRange = { 0.0f,1.0f };
			viewport.OffsetInPixels = { 0,0 };
			viewport.SizeInPixels = { 512,512 };
			pipelineDesc.Viewport = viewport;

			//Shaders
			pipelineDesc.GraphicsShaders.Add(mVertexShader);
			pipelineDesc.GraphicsShaders.Add(mFragmentShader);

			//Inputlayout
			InputLayoutDesc inputLayout = {};
			InputBinding binding0 = {};
			binding0.StepRate = InputBindingStepRate::Vertex;
			binding0.Elements =
			{
				{ TextureFormat::R32_G32_B32_Float,InputElementSemantic::Position },
				{ TextureFormat::R32_G32_B32_Float,InputElementSemantic::Normal },
				{ TextureFormat::R32_G32_B32_Float,InputElementSemantic::Tangent },
				{ TextureFormat::R32_G32_B32_Float,InputElementSemantic::Tangent },
				{ TextureFormat::R32_G32_Float,InputElementSemantic::TexCoord }
			};
			inputLayout.Bindings.Add(binding0);
			inputLayout.Topology = MeshTopology::TriangleList;
			pipelineDesc.InputLayout = inputLayout;

			//Resource layout
			pipelineDesc.ResourceLayout.ResourceLayouts.Add(mResourceLayout.GetHeap());

			mPipeline = GraphicsAPI::GetDefaultDevice()->CreateGraphicsPipeline(pipelineDesc);
			bInitialized = true;
		}

		//Update mvp buffer host information
		const Vector3F modelPosition = { 0,0,5 };
		const Vector3F modelRotation = { 0,0,0 };
		const Vector3F modelScale = { 1,1,1 };
		const Vector3F cameraPosition = { 0,0,0 };
		const Vector3F cameraLookDirection = { 0,0,1 };

		const Matrix4x4F modelMatrix =
			Matrix4x4F::Translation(modelPosition) *
			Matrix4x4F::Scale(modelScale) *
			Matrix4x4F::RotationX(modelRotation.X) *
			Matrix4x4F::RotationY(modelRotation.Y) *
			Matrix4x4F::RotationZ(modelRotation.Z);
		const Matrix4x4F viewMatrix = Matrix4x4F::Identity();
		const Matrix4x4F projectionMatrix = Matrix4x4F::Perspective(1000, 0.1f, 1.0f, 1.0f);
		const Matrix4x4F mvp = modelMatrix * viewMatrix * projectionMatrix;
		const Matrix4x4F test = Matrix4x4F::Identity();
		GraphicsBufferHostUpdateDesc constantHostBufferUpdateDesc = {};
		constantHostBufferUpdateDesc.OffsetInBytes = 0;
		constantHostBufferUpdateDesc.View = { (Byte*) & test,sizeof(test)};
		GraphicsAPI::GetDefaultDevice()->UpdateHostBuffer(mConstantBufferHost.GetHeap(), constantHostBufferUpdateDesc);

		mCmdList->BeginRecording();

		//Update mvp buffer device information
		BufferBufferCopyDesc copyDesc = {};
		copyDesc.DestinationOffsetInBytes = 0;
		copyDesc.SourceOffsetInBytes = 0;
		copyDesc.SizeInBytes = 64;
		mCmdList->CopyBufferToBuffer(mConstantBufferHost.GetHeap(), mConstantBufferDevice.GetHeap(), copyDesc);

		//Set pipeline
		mCmdList->SetPipeline(mPipeline);

		//Set render pass
		mCmdList->BeginRenderPass(pRenderTarget->GetRenderPass(), Color4F::CornflowerBlue(), 0);

		//Set vertex buffer
		mCmdList->SetVertexBuffer(mMesh->GetVertexBuffer());

		//Set index buffer
		mCmdList->SetIndexBuffer(mMesh->GetIndexBuffer(), CommandListIndexBufferType::Unsigned_Int);

		//Scissors
		ScissorDesc scissor;
		scissor.OffsetInPixels = { 0,0 };
		scissor.SizeInPixels = { 512,512 };
		mCmdList->SetScissors(&scissor, 1);

		//Commit resources
		mCmdList->CommitResources(mResourceTable.GetHeapAddress(), 1);

		//Draw
		mCmdList->DrawIndexed(mMesh->GetIndexCount(), 0, 0, 1, 0);

 		mCmdList->EndRenderPass();

		mCmdList->EndRecording();
		GraphicsAPI::GetDefaultDevice()->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());
		GraphicsAPI::GetDefaultDevice()->WaitFences(mFence.GetHeapAddress(), 1);
    }
}
