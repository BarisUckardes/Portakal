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

//#include <Runtime/ShaderCompiler/ShaderCompiler.h>

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

    ImGuiRenderer::ImGuiRenderer(const SharedHeap<GraphicsDevice>& pTargetDevice) : mDevice(pTargetDevice), mContext(nullptr), mCommandPool(nullptr), mCommandList(nullptr)
    {
        DEV_ASSERT(mDevice != nullptr, "ImGuiRenderer", "Given device is invalid");
        CreateImGuiResources();
        SetupDefaultTheme();
    }

    ImGuiRenderer::ImGuiRenderer() : mDevice(nullptr), mContext(nullptr), mCommandPool(nullptr), mCommandList(nullptr)
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
}
