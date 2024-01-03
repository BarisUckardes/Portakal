#include "ImGuiRenderer.h"
#include <Runtime/Platform/PlatformClipboard.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Math/Matrix4x4F.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/ShaderCompiler/ShaderCompiler.h>
#include <Editor/ImGui/ImGuiTextureBinding.h>
#include <Editor/ImGui/ImGuiUtils.h>

#define IMGUI_MAX_RESOURCE_TABLES 8192
namespace Portakal
{
    static const char vertexShaderSource[] =
        "	layout(set=0,binding=0) cbuffer vertexBuffer \
            {\
              float4x4 ProjectionMatrix; \
            };\
            struct VS_INPUT\
            {\
              float2 pos : POSITION;\
              float2 uv  : TEXCOORD0;\
              float4 col : COLOR0;\
            };\
            \
            struct PS_INPUT\
            {\
              float4 pos : SV_POSITION;\
              float2 uv  : TEXCOORD0;\
              float4 col : COLOR0;\
            };\
            \
            PS_INPUT main(VS_INPUT input)\
            {\
              PS_INPUT output;\
              output.pos = mul( ProjectionMatrix, float4(input.pos.xy, 0.f, 1.f));\
              output.col = input.col;\
              output.uv  = input.uv;\
              return output;\
            }";

    static const char pixelShaderSource[] =
        "struct PS_INPUT\
            {\
            float4 pos : SV_POSITION;\
            float2 uv  : TEXCOORD0;\
            float4 col : COLOR0;\
            };\
            layout(set=0,binding=1) sampler sampler0;\
            layout(set=1,binding=0) Texture2D texture0;\
            \
            float4 main(PS_INPUT input) : SV_Target\
            {\
            float4 out_col =  input.col*texture0.Sample(sampler0,input.uv); \
            return out_col; \
            }";

    void SetClipboardTextCallback(void* userData, const char* text)
    {
        PlatformClipboard::SetClipboardText(text);
    }

    const char* GetClipboardTextCallback(void* userData)
    {
        return PlatformClipboard::GetClipboardText().GetSource();
    }

    ImGuiRenderer::ImGuiRenderer(const SharedHeap<GraphicsDevice>& pTargetDevice) : mDevice(pTargetDevice), mContext(nullptr), mCmdPool(nullptr), mCmdList(nullptr)
    {
        DEV_ASSERT(mDevice != nullptr, "ImGuiRenderer", "Given device is invalid");
        CreateImGuiResources();
        SetupDefaultTheme();
    }

    ImGuiRenderer::ImGuiRenderer() : mDevice(nullptr), mContext(nullptr), mCmdPool(nullptr), mCmdList(nullptr)
    {
        mDevice = GraphicsAPI::GetDefaultDevice();
        DEV_ASSERT(mDevice != nullptr, "ImGuiRenderer", "Default device is invalid");
        CreateImGuiResources();
        SetupDefaultTheme();
    }

    ImGuiRenderer::~ImGuiRenderer()
    {
        mDevice->WaitFences(mFence.GetHeapAddress(), 1);

        mFence->Shutdown();
    }

    void ImGuiRenderer::StartRendering(const float deltaTimeInMilliseconds)
    {
        ImGui::NewFrame();
    }
    void ImGuiRenderer::EndRendering(const SharedHeap<RenderPass>& pRenderPass, const Color4F clearColor)
    {
        //Get display size
        const Vector2US renderSize = pRenderPass->GetRenderRegion();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = { (float)renderSize.X,(float)renderSize.Y };
        io.DisplayFramebufferScale = { 1.0f,1.0f };

        //Render queued calls
        ImGui::Render();

        //Get draw data
        ImDrawData* pDrawData = ImGui::GetDrawData();

        //Allocate vertexes
        if (pDrawData->TotalVtxCount > mMesh->GetVertexCount())
            mMesh->AllocateVertexes(pDrawData->TotalVtxCount + 100, sizeof(ImDrawVert), mDeviceMemory, mHostMemory, true);

        //Allocate indexes
        if (pDrawData->TotalIdxCount > mMesh->GetIndexCount())
            mMesh->AllocateIndexes(pDrawData->TotalIdxCount + 100, sizeof(uint16), mDeviceMemory, mHostMemory, true);

        uint32 vertexOffset = 0;
        uint32 indexOffset = 0;

        //Iterate command lists
        for (uint32 cmdListIndex = 0; cmdListIndex < pDrawData->CmdListsCount; cmdListIndex++)
        {
            const ImDrawList* pCmdList = pDrawData->CmdLists[cmdListIndex];
            const uint32 vertexBufferSize = pCmdList->VtxBuffer.Size * sizeof(ImDrawVert);
            const uint32 indexBufferSize = pCmdList->IdxBuffer.Size * sizeof(uint16);

            mMesh->UpdateVertexes({ (byte*)pCmdList->VtxBuffer.Data,vertexBufferSize }, vertexOffset);
            mMesh->UpdateIndexes({ (byte*)pCmdList->IdxBuffer.Data,indexBufferSize }, indexOffset);

            vertexOffset += vertexBufferSize;
            indexOffset += indexBufferSize;
        }

        //Create projection matrix
        const float L = pDrawData->DisplayPos.x;
        const float R = L + pDrawData->DisplaySize.x;
        const float B = pDrawData->DisplayPos.y;
        const float T = B + pDrawData->DisplaySize.y;
        const float projectionData[] =
        {
            2.0f / (R - L),0,0,0,
            0,2.0f / (T - B),0,0,
            0,0,0.5f,0,
            (R + L) / (L - R),(T + B) / (B - T),0.5f,1.0f
        };

        //Set projection matrix host data
        GraphicsBufferHostUpdateDesc hostStagingBufferUpdateDesc = {};
        hostStagingBufferUpdateDesc.View = { (byte*)projectionData,sizeof(projectionData) };
        hostStagingBufferUpdateDesc.OffsetInBytes = 0;
        mDevice->UpdateHostBuffer(mStagingBuffer.GetHeap(), hostStagingBufferUpdateDesc);

        //Start command recording
        mCmdList->BeginRecording();

        //Copy host constant buffer to the device
        BufferBufferCopyDesc copyDesc = {};
        copyDesc.DestinationOffsetInBytes = 0;
        copyDesc.SourceOffsetInBytes = 0;
        copyDesc.SizeInBytes = sizeof(projectionData);
        mCmdList->CopyBufferToBuffer(mStagingBuffer.GetHeap(), mConstantBuffer.GetHeap(), copyDesc);

        //Bind pipeline
        mCmdList->SetPipeline(mPipeline);

        //Start rendering
        mCmdList->BeginRenderPass(pRenderPass, Color4F::CornflowerBlue());

        //Check the renderable range
        const bool bHasRenderableRange = pDrawData->DisplaySize.x > 0.0f && pDrawData->DisplaySize.y > 0.0f && pDrawData->CmdListsCount != 0;

        if (bHasRenderableRange)
        {
            /*
            * Set vertex&index buffers
            */
            mCmdList->SetVertexBuffer(mMesh->GetVertexBuffer());
            mCmdList->SetIndexBuffer(mMesh->GetIndexBuffer(), CommandListIndexBufferType::Unsigned_Short);

            /*
            * Set clip rects
            */
            pDrawData->ScaleClipRects(io.DisplayFramebufferScale);

            /*
            * Set viewport
            */
            ViewportDesc viewport = {};
            viewport.OffsetInPixels = { 0,0 };
            viewport.SizeInPixels = { (uint16)pDrawData->DisplaySize.x,(uint16)pDrawData->DisplaySize.y };
            viewport.DepthRange = { 0.0f,1.0f };
            mCmdList->SetViewports(&viewport, 1);

            /*
            * Draw
            */
            const Vector2F clipOffset = { pDrawData->DisplayPos.x,pDrawData->DisplayPos.y };
            uint32 drawVertexOffset = 0;
            uint32 drawIndexOffset = 0;
            ResourceTable* ppResourceSets[]
            {
                mStaticResourceTable.GetHeap(),
                nullptr
            };
            for (uint32 cmdListIndex = 0; cmdListIndex < pDrawData->CmdListsCount; cmdListIndex++)
            {
                ImDrawList* pDrawList = pDrawData->CmdLists[cmdListIndex];
                for (uint32 cmdIndex = 0; cmdIndex < pDrawList->CmdBuffer.Size; cmdIndex++)
                {
                    ImDrawCmd& cmd = pDrawList->CmdBuffer[cmdIndex];

                    const Vector2F clipMin =
                    {
                        cmd.ClipRect.x - clipOffset.X,
                        cmd.ClipRect.y - clipOffset.Y
                    };
                    const Vector2F clipMax =
                    {
                        cmd.ClipRect.z - clipOffset.X,
                        cmd.ClipRect.w - clipOffset.Y
                    };

                    if (clipMax.X <= clipMin.X || clipMax.Y <= clipMin.Y)
                        continue;

                    ScissorDesc scissor = {};
                    scissor.OffsetInPixels = { (uint32)clipMin.X,(uint32)clipMin.Y };
                    scissor.SizeInPixels = { (uint32)clipMax.X,(uint32)clipMax.Y };

                    mCmdList->SetScissors(&scissor, 1);

                    if (cmd.TextureId == nullptr) // default font texture
                    {
                        ppResourceSets[1] = mFontResourceTable.GetHeap();
                    }
                    else // custom texture
                    {

                    }

                    mCmdList->CommitResources({ ppResourceSets[0],ppResourceSets[1] });
                    mCmdList->DrawIndexed(cmd.ElemCount, (drawIndexOffset + cmd.IdxOffset), (drawVertexOffset + cmd.VtxOffset), 1, 0);
                }

                drawVertexOffset += pDrawList->VtxBuffer.Size;
                drawIndexOffset += pDrawList->IdxBuffer.Size;
            }
        }

        //End rendering
        mCmdList->EndRenderPass();

        //End recording
        mCmdList->EndRecording();

        //Submit commands and wait
        mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());
        mDevice->WaitFences(mFence.GetHeapAddress(), 1);
    }
    void ImGuiRenderer::CreateImGuiResources()
    {
        //Create imgui context
        mContext = ImGui::CreateContext();
        ImGui::SetCurrentContext(mContext);

        //Set IO flags
        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags = ImGuiBackendFlags_None;
        io.ConfigFlags = ImGuiConfigFlags_DockingEnable;

        //Set clipboard callbacks
        io.SetClipboardTextFn = SetClipboardTextCallback;
        io.GetClipboardTextFn = GetClipboardTextCallback;

        //Create device and host memory
        GraphicsMemoryHeapDesc deviceMemoryDesc = {};
        deviceMemoryDesc.SizeInBytes = MB_TO_BYTE(128);
        deviceMemoryDesc.Type = GraphicsMemoryType::Device;

        GraphicsMemoryHeapDesc hostMemoryDesc = {};
        hostMemoryDesc.SizeInBytes = MB_TO_BYTE(128);
        hostMemoryDesc.Type = GraphicsMemoryType::Host;

        mDeviceMemory = mDevice->CreateMemoryHeap(deviceMemoryDesc);
        mHostMemory = mDevice->CreateMemoryHeap(hostMemoryDesc);

        //Create staging buffer
        GraphicsBufferDesc stagingBufferDesc = {};
        stagingBufferDesc.Usage = GraphicsBufferUsage::TransferSource;
        stagingBufferDesc.pHeap = mHostMemory;
        stagingBufferDesc.SubItemCount = 1;
        stagingBufferDesc.SubItemSizeInBytes = MB_TO_BYTE(32);
        mStagingBuffer = mDevice->CreateBuffer(stagingBufferDesc);

        //Create constant buffer
        GraphicsBufferDesc constantBufferDesc = {};
        constantBufferDesc.Usage = GraphicsBufferUsage::ConstantBuffer | GraphicsBufferUsage::TransferDestination;
        constantBufferDesc.pHeap = mDeviceMemory;
        constantBufferDesc.SubItemCount = 1;
        constantBufferDesc.SubItemSizeInBytes = 64;
        mConstantBuffer = mDevice->CreateBuffer(constantBufferDesc);

        //Compile HLSL to SPIRV
        MemoryOwnedView* pVertexShaderSpirv = nullptr;
        MemoryOwnedView* pFragmentShaderSpirv = nullptr;

        ShaderCompiler::CompileToSPIRV(vertexShaderSource, "main", ShaderStage::VertexStage, ShaderLanguage::HLSL, &pVertexShaderSpirv);
        ShaderCompiler::CompileToSPIRV(pixelShaderSource, "main", ShaderStage::FragmentStage, ShaderLanguage::HLSL, &pFragmentShaderSpirv);

        //Compile HLSL to platform bytes
        MemoryOwnedView* pVertexShaderPlatformBytes = nullptr;
        MemoryOwnedView* pFragmentShaderPlatformBytes = nullptr;
        ShaderCompiler::CompileFromSPIRV(pVertexShaderSpirv, ShaderLanguage::HLSL, &pVertexShaderPlatformBytes);
        ShaderCompiler::CompileFromSPIRV(pFragmentShaderSpirv, ShaderLanguage::HLSL, &pFragmentShaderPlatformBytes);

        //Create shaders
        ShaderDesc vertexShaderDesc = {};
        vertexShaderDesc.Stage = ShaderStage::VertexStage;
        vertexShaderDesc.ByteCode = pVertexShaderPlatformBytes;
        vertexShaderDesc.EntryPoint = "main";

        ShaderDesc fragmentShaderDesc = {};
        fragmentShaderDesc.Stage = ShaderStage::FragmentStage;
        fragmentShaderDesc.ByteCode = pFragmentShaderPlatformBytes;
        fragmentShaderDesc.EntryPoint = "main";

        mVertexShader = mDevice->CreateShader(vertexShaderDesc);
        mFragmentShader = mDevice->CreateShader(fragmentShaderDesc);

        //Create sampler
        SamplerDesc samplerDesc = {};
        samplerDesc.AddressModeU = SamplerAddressMode::Repeat;
        samplerDesc.AddressModeV = SamplerAddressMode::Repeat;
        samplerDesc.AddressModeW = SamplerAddressMode::Repeat;
        samplerDesc.MinFilter = SamplerFiltering::Linear;
        samplerDesc.MagFilter = SamplerFiltering::Linear;
        samplerDesc.MipLodBias = 0;
        samplerDesc.CompareOperation = CompareOperation::Never;
        samplerDesc.ComparisonEnabled = false;
        samplerDesc.MinLod = 0;
        samplerDesc.MaxLod = 0;
        samplerDesc.MaxAnisotropy = 0;

        mSampler = mDevice->CreateSampler(samplerDesc);

        //Create input layout
        InputLayoutDesc inputStateDesc = {};
        InputBinding vertexInputBinding = {};
        vertexInputBinding.StepRate = InputBindingStepRate::Vertex;
        vertexInputBinding.Elements =
        {
            {TextureFormat::R32_G32_Float, InputElementSemantic::Position},
            {TextureFormat::R32_G32_Float, InputElementSemantic::TexCoord},
            {TextureFormat::R8_G8_B8_A8_UNorm, InputElementSemantic::Color}
        };
        inputStateDesc.Bindings.Add(vertexInputBinding);
        inputStateDesc.Topology = MeshTopology::TriangleList;

        //Create blending state
        BlendStateDesc blendingStateDesc = {};
        blendingStateDesc.bLogicOperationEnabled = false;
        blendingStateDesc.LogicOperation = LogicOperation::Clear;
        BlendStateAttachment blendingAttachment = {};
        blendingAttachment.Enabled = true;
        blendingAttachment.SourceColorFactor = BlendFactor::SrcAlpha;
        blendingAttachment.DestinationColorFactor = BlendFactor::OneMinusSrcAlpha;
        blendingAttachment.ColorOperation = BlendOperation::Add;
        blendingAttachment.SourceAlphaFactor = BlendFactor::One;
        blendingAttachment.DestinationAlphaFactor = BlendFactor::OneMinusSrcAlpha;
        blendingStateDesc.Attachments.Add(blendingAttachment);

        //Create rasterizer state
        RasterizerStateDesc rasterizerStateDesc = {};
        rasterizerStateDesc.IsFrontCounterClockwise = false;
        rasterizerStateDesc.CullFlags = FaceCullMode::None;
        rasterizerStateDesc.FillMode = PolygonMode::Fill;
        rasterizerStateDesc.DepthBiasEnabled = false;
        rasterizerStateDesc.DepthBiasClamp = 0;
        rasterizerStateDesc.DepthBiasFactor = 0;
        rasterizerStateDesc.DepthBiasSlope = 0;

        //Create depth stencil state
        DepthStencilStateDesc depthStencilStateDesc = {};
        depthStencilStateDesc.bDepthTestEnabled = false;
        depthStencilStateDesc.bDepthWriteEnabled = false;
        depthStencilStateDesc.bStencilTestEnabled = false;
        depthStencilStateDesc.StencilBackFace = {};
        depthStencilStateDesc.StencilFrontFace = {};

        //Create static resource layout
        ResourceLayoutDesc resourceLayoutDesc = {};
        ResourceTableLayoutDesc staticResourceLayoutDesc = {};
        staticResourceLayoutDesc.Entries =
        {
            {GraphicsResourceType::ConstantBuffer,ShaderStage::VertexStage,0},
            {GraphicsResourceType::Sampler,ShaderStage::FragmentStage,1}
        };
        mStaticResourceLayout = mDevice->CreateResourceTableLayout(staticResourceLayoutDesc);
        resourceLayoutDesc.ResourceLayouts.Add(mStaticResourceLayout.GetHeap());

        //Create dynamic resource layout
        ResourceTableLayoutDesc dynamicResourceLayoutDesc = {};
        dynamicResourceLayoutDesc.Entries =
        {
            {GraphicsResourceType::SampledTexture,ShaderStage::FragmentStage,0}
        };
        mFontResourceLayout = mDevice->CreateResourceTableLayout(dynamicResourceLayoutDesc);
        resourceLayoutDesc.ResourceLayouts.Add(mFontResourceLayout.GetHeap());

        //Create multipsample state desc
        MultisampleDesc multisampleDesc = {};
        multisampleDesc.bSampleShadingEnabled = false;
        multisampleDesc.Samples = TextureSampleCount::SAMPLE_COUNT_1;

        //Create output desc
        OutputMergerDesc outputState = {};
        outputState.ColorFormats = { TextureFormat::R8_G8_B8_A8_UNorm };

        //Create graphics device
        GraphicsPipelineDesc pipelineDesc = {};
        pipelineDesc.BlendState = blendingStateDesc;
        pipelineDesc.DepthStencilState = depthStencilStateDesc;
        pipelineDesc.InputLayout = inputStateDesc;
        pipelineDesc.Multisample = multisampleDesc;
        pipelineDesc.OutputMerger = outputState;
        pipelineDesc.RasterizerState = rasterizerStateDesc;
        pipelineDesc.ResourceLayout = resourceLayoutDesc;
        pipelineDesc.GraphicsShaders = { mVertexShader,mFragmentShader };
        mPipeline = mDevice->CreateGraphicsPipeline(pipelineDesc);

        //Create fence
        mFence = mDevice->CreateFence();

        //Create command pool
        CommandPoolDesc cmdPoolDesc = {};
        cmdPoolDesc.Type = CommandPoolType::Graphics;
        mCmdPool = mDevice->CreateCommandPool(cmdPoolDesc);

        CommandListDesc cmdListDesc = {};
        cmdListDesc.pPool = mCmdPool;
        mCmdList = mDevice->CreateCommandList(cmdListDesc);

        //Create texture data
        byte* pFontData = nullptr;
        int width;
        int height;
        int channelCount;
        io.Fonts->GetTexDataAsRGBA32(&pFontData, &width, &height, &channelCount);

        DEV_ASSERT(pFontData != nullptr && width != 0 && height != 0 && channelCount != 0, "ImGuiRenderer", "Failed to initialize, invalid default font texture!");


        //Create texture
        TextureDesc defaultFontTextureDesc = {};
        defaultFontTextureDesc.Type = TextureType::Texture2D;
        defaultFontTextureDesc.Usage = TextureUsage::Sampled | TextureUsage::TransferDestination;
        defaultFontTextureDesc.Format = TextureFormat::R8_G8_B8_A8_UNorm;
        defaultFontTextureDesc.Size = { (uint16)width,(uint16)height,1 };
        defaultFontTextureDesc.MipLevels = 1;
        defaultFontTextureDesc.ArrayLevels = 1;
        defaultFontTextureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
        defaultFontTextureDesc.pHeap = mDeviceMemory;

        mDefaultFontTexture = new TextureResource(mDevice);
        mDefaultFontTexture->AllocateTexture(defaultFontTextureDesc, mHostMemory, true, true);
        mDefaultFontTexture->Update(MemoryView(pFontData, width* height * 4), { 0,0,0 },TextureMemoryLayout::Unknown,GraphicsMemoryAccessFlags::Unknown,PipelineStageFlags::TopOfPipe,GraphicsQueueType::Graphics,0,0);
        mDefaultFontTexture->CreateView(0, 0);

        //Set texture memory barrier
        CommandListTextureMemoryBarrierDesc barrierDesc = {};
        barrierDesc.ArrayIndex = 0;
        barrierDesc.MipIndex = 0;
        barrierDesc.AspectFlags = TextureAspectFlags::Color;

        barrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
        barrierDesc.SourceLayout = TextureMemoryLayout::Unknown;
        barrierDesc.SourceQueue = GraphicsQueueType::Graphics;
        barrierDesc.SourceStageFlags = PipelineStageFlags::Transfer;

        barrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ShaderRead;
        barrierDesc.DestinationLayout = TextureMemoryLayout::ShaderReadOnly;
        barrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
        barrierDesc.DestinationStageFlags = PipelineStageFlags::FragmentShader;
        mCmdList->BeginRecording();
        mCmdList->SetTextureMemoryBarrier(mDefaultFontTexture->GetTexture().GetHeap(), barrierDesc);
        mCmdList->EndRecording();
        mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());
        mDevice->WaitFences(mFence.GetHeapAddress(), 1);

        //Create resource table pool
        ResourceTablePoolDesc tablePoolDesc = {};
        tablePoolDesc.Entries =
        {
            {GraphicsResourceType::ConstantBuffer,1},
            {GraphicsResourceType::Sampler,1},
            {GraphicsResourceType::SampledTexture,1}
        };
        tablePoolDesc.MaxTables = IMGUI_MAX_RESOURCE_TABLES;
        mResourcePool = mDevice->CreateResourceTablePool(tablePoolDesc);


        // Create static resource set
        ResourceTableDesc staticResourceTableDesc = {};
        staticResourceTableDesc.pOwnerPool = mResourcePool.GetHeap();
        staticResourceTableDesc.pTargetLayout = mStaticResourceLayout.GetHeap();
        mStaticResourceTable = mDevice->CreateResourceTable(staticResourceTableDesc);

        //Create font resource table
        ResourceTableDesc fontResourceTableDesc = {};
        fontResourceTableDesc.pOwnerPool = mResourcePool.GetHeap();
        fontResourceTableDesc.pTargetLayout = mFontResourceLayout.GetHeap();
        mFontResourceTable = mDevice->CreateResourceTable(fontResourceTableDesc);

        //Update static resource table
        ResourceTableUpdateDesc staticTableUpdateDesc = {};
        staticTableUpdateDesc.Entries =
        {
            {mConstantBuffer.QueryAs<GraphicsDeviceObject>(),GraphicsResourceType::ConstantBuffer,1,0,0,0},
            {mSampler.QueryAs<GraphicsDeviceObject>(),GraphicsResourceType::Sampler,1,0,1,1}
        };
        mDevice->UpdateResourceTable(mStaticResourceTable.GetHeap(), staticTableUpdateDesc);

        //Update font resource table
        ResourceTableUpdateDesc fontTableUpdateDesc = {};
        fontTableUpdateDesc.Entries =
        {
            {mDefaultFontTexture->GetView(0,0).GetHeap(),GraphicsResourceType::SampledTexture,0,0,0,0}
        };
        mDevice->UpdateResourceTable(mFontResourceTable.GetHeap(), fontTableUpdateDesc);

        //Create mesh
        mMesh = new MeshResource(mDevice);

        //Allocate vertex and index buffer
        mMesh->AllocateVertexes(6400, sizeof(ImDrawVert), mHostMemory, mDeviceMemory, true);
        mMesh->AllocateIndexes(6400, sizeof(uint16), mHostMemory, mDeviceMemory, true);
    }
    void ImGuiRenderer::SetupDefaultTheme()
    {
        /*
        * Setup default theme
        */
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowPadding = ImVec2(15, 15);
        style.WindowRounding = 5.0f;
        style.FramePadding = ImVec2(5, 5);
        style.FrameRounding = 4.0f;
        style.ItemSpacing = ImVec2(12, 8);
        style.ItemInnerSpacing = ImVec2(8, 6);
        style.IndentSpacing = 25.0f;
        style.ScrollbarSize = 15.0f;
        style.ScrollbarRounding = 9.0f;
        style.GrabMinSize = 5.0f;
        style.GrabRounding = 3.0f;

        style.Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
        style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style.Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
        style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
        style.Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
    }
}
