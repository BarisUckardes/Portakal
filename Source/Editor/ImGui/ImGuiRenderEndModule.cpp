#include "ImGuiRenderEndModule.h"
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Editor/ImGui/ImGuiAPI.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Runtime/Window/WindowAPI.h>

namespace Portakal
{
    void ImGuiRenderEndModule::OnInitialize()
    {

    }
    void ImGuiRenderEndModule::OnFinalize()
    {
        for (SharedHeap<RenderTarget>& pRenderTarget : mRenderTargets)
            pRenderTarget.Shutdown();

        mRenderTargets.Clear();
    }
    void ImGuiRenderEndModule::OnTick()
    {
        //Get and validate imgui renderer
        SharedHeap<ImGuiRenderer> pRenderer = ImGuiAPI::GetRenderer();
        if (pRenderer.IsShutdown())
            return;
        
        //Get window
        SharedHeap<PlatformWindow> pWindow = WindowAPI::GetDefaultWindow();
        if (pWindow.IsShutdown())
        {
            DEV_LOG("ImGuiRendererStartModule", "No window found");
            return;
        }

        //Get main swapchain
        SharedHeap<Swapchain> pSwapchain = pRenderer->GetDevice()->GetMainSwapchain();

        //Check if render target needs a refresh
        if (pSwapchain->GetSize() != mLastSwapchainSize)
        {
            //Invalidate render target
            SharedHeap<GraphicsDevice> pTargetDevice = pRenderer->GetDevice();
            InvalidateRenderTarget(pTargetDevice);

            //Call on resize
            pRenderer->OnResized(pSwapchain->GetSize());

            //Register
            mLastSwapchainSize = pSwapchain->GetSize();
        }

        //End rendering session and render
        pRenderer->EndRendering(mRenderTargets[mSwapchainBufferIndex], Color4F::CornflowerBlue());

        //Present
        pSwapchain->Present();
        pSwapchain->WaitForPresent(mSwapchainBufferIndex);
        mSwapchainBufferIndex = (mSwapchainBufferIndex + 1) % pSwapchain->GetBufferCount();
    }
    void ImGuiRenderEndModule::OnPreInvalidation()
    {

    }
    void ImGuiRenderEndModule::OnPostInvalidation()
    {

    }
    void ImGuiRenderEndModule::InvalidateRenderTarget(const SharedHeap<GraphicsDevice>& pDevice)
    {
        //Get swapchain
        SharedHeap<Swapchain> pMainSwapchain = pDevice->GetMainSwapchain();
        if (pMainSwapchain.IsShutdown())
            return;

        //Clear former render targets
        mRenderTargets.Clear();

        //Create new render targets
        Array<SharedHeap<Texture>> textures = pMainSwapchain->GetTextures();
        Array<SharedHeap<TextureView>> views = pMainSwapchain->GetTextureViews();
        for (int i = 0; i < textures.GetSize(); i++)
        {
            const SharedHeap<Texture>& pTexture = textures[i];
            const SharedHeap<TextureView>& pView = views[i];

            //Create render pass
            RenderPassDesc desc = {};
            desc.Size = { pTexture->GetSize().X,pTexture->GetSize().Y };
            desc.AttachmentViews.Add(pView);
            RenderPassAttachmentDesc colorAttachmentDesc = {};
            colorAttachmentDesc.ArrayLevel = 0;
            colorAttachmentDesc.MipLevel = 0;
            colorAttachmentDesc.ColorLoadOperation = RenderPassLoadOperation::Clear;
            colorAttachmentDesc.ColorStoreOperation = RenderPassStoreOperation::Store;
            colorAttachmentDesc.InputLayout = TextureMemoryLayout::Present;
            colorAttachmentDesc.OutputLayout = TextureMemoryLayout::Present;
            colorAttachmentDesc.pTexture = pTexture;
            colorAttachmentDesc.StencilLoadOperation = RenderPassLoadOperation::Clear;
            colorAttachmentDesc.StencilStoreOperation = RenderPassStoreOperation::Store;
            desc.ColorAttachments.Add(colorAttachmentDesc);
            RenderPassSubpassDesc subpassDesc = {};
            subpassDesc.BindPoint = PipelineBindPoint::Graphics;
            subpassDesc.DepthStencilInput = 0;
            subpassDesc.Attachments.Add(0);
            desc.Subpasses.Add(subpassDesc);

            SharedHeap<RenderTarget> pRenderTarget = new RenderTarget();
            pRenderTarget->Create(desc);
            mRenderTargets.Add(pRenderTarget);
        }
    }
}
