#include "VulkanGraphicsModule.h"
#include <Runtime/Window/WindowAPI.h>


namespace Portakal
{
	SharedHeap<RenderPass> CreateRenderPass(Swapchain* pSwapchain, GraphicsDevice* pDevice)
	{
		RenderPassDesc renderPassDesc = {};
		renderPassDesc.Size = { pSwapchain->GetSize().X,pSwapchain->GetSize().Y };
		renderPassDesc.DepthStencilAttachment = {};
		renderPassDesc.AttachmentViews;
		renderPassDesc.bSwapchain = true;
		for (const SharedHeap<TextureView>& view : pSwapchain->GetTextureViews())
			renderPassDesc.AttachmentViews.Add(view);

		//Create render attachment desc
		for (byte i = 0; i < pSwapchain->GetBufferCount(); i++)
		{
			RenderPassAttachmentDesc attachmentDesc = {};
			attachmentDesc.pTexture = pSwapchain->GetTextures()[i];
			attachmentDesc.ArrayLevel = 1;
			attachmentDesc.MipLevel = 1;
			attachmentDesc.ColorLoadOperation = RenderPassLoadOperation::Clear;
			attachmentDesc.ColorStoreOperation = RenderPassStoreOperation::Store;
			attachmentDesc.StencilLoadOperation = RenderPassLoadOperation::Load;
			attachmentDesc.StencilStoreOperation = RenderPassStoreOperation::Ignore;
			attachmentDesc.InputLayout = TextureMemoryLayout::ColorAttachment;
			attachmentDesc.OutputLayout = TextureMemoryLayout::Present;
			renderPassDesc.ColorAttachments.Add(attachmentDesc);
		}

		//Create subpass
		RenderPassSubpassDesc subpassDesc = {};
		subpassDesc.BindPoint = PipelineBindPoint::Graphics;
		subpassDesc.Inputs = { 0 };
		renderPassDesc.Subpasses.Add(subpassDesc);
		return pDevice->CreateRenderPass(renderPassDesc);
	}
	Array<SharedHeap<Texture>> swapchainTextures;
	bool bRed = true;
	void VulkanGraphicsModule::OnInitialize()
	{
		//Get default window
		mWindow = WindowAPI::GetDefaultWindow();

		//Create graphics instance
		GraphicsInstanceDesc instanceDesc = {};
		instanceDesc.Backend = GraphicsBackend::Vulkan;
		mInstance = Portakal::GraphicsInstance::Create(instanceDesc);

		//Get adapter
		mAdapter = mInstance->GetAdapters()[0];
		DEV_LOG("System", "Selecting [%s] device", *mInstance->GetName());

		//Create device
		mDevice = mAdapter->CreateDevice();

		//Create swapchain
		SwapchainDesc swapchainDesc = {};
		swapchainDesc.ColorFormat = TextureFormat::R8_G8_B8_A8_UNorm;
		swapchainDesc.BufferCount = 2;
		swapchainDesc.DepthStencilFormat = TextureFormat::None;
		swapchainDesc.pWindow = mWindow;
		swapchainDesc.pDevice = mDevice;
		swapchainDesc.PresentMode = PresentMode::VsyncQueued;
		mSwapchain = mDevice->CreateSwapchain(swapchainDesc);

		//Create command pool
		mCmdPool = mDevice->CreateCommandPool({ CommandPoolType::Graphics });

		//Create command list
		mCmdList = mDevice->CreateCommandList({ mCmdPool });

		//Create fence
		mFence = mDevice->CreateFence();

		//Get swapchain textures
		swapchainTextures = mSwapchain->GetTextures();

		//Create render pass set
		mRenderPass = CreateRenderPass(mSwapchain.GetHeap(), mDevice.GetHeap());
	}
	Vector2US lastWindowSize;
	byte presentImageIndex = 0;
	void VulkanGraphicsModule::OnTick()
	{
		//Check if window resized and get new set of textures + create new render pass
		const Vector2US windowSize = mWindow->GetSize();
		if (lastWindowSize != windowSize)
		{
			swapchainTextures = mSwapchain->GetTextures();
			mRenderPass.Shutdown();
			mRenderPass = CreateRenderPass(mSwapchain.GetHeap(), mDevice.GetHeap());
		}
		lastWindowSize = windowSize;

		//Begin recording
		mCmdList->BeginRecording();

		//Set pre barrier
		CommandListTextureMemoryBarrierDesc preRenderPassBarrier = {};
		preRenderPassBarrier.ArrayIndex = 0;
		preRenderPassBarrier.MipIndex = 0;
		preRenderPassBarrier.AspectFlags = TextureAspectFlags::Color;

		preRenderPassBarrier.SourceAccessFlags = GraphicsMemoryAccessFlags::ColorAttachmentRead;
		preRenderPassBarrier.SourceLayout = TextureMemoryLayout::Present;
		preRenderPassBarrier.SourceQueue = GraphicsQueueType::Graphics;
		preRenderPassBarrier.SourceStageFlags = PipelineStageFlags::ColorAttachmentOutput;

		preRenderPassBarrier.DestinationAccessFlags = GraphicsMemoryAccessFlags::ColorAttachmentRead | GraphicsMemoryAccessFlags::ColorAttachmentWrite;
		preRenderPassBarrier.DestinationLayout = TextureMemoryLayout::ColorAttachment;
		preRenderPassBarrier.DestinationQueue = GraphicsQueueType::Graphics;
		preRenderPassBarrier.DestinationStageFlags = PipelineStageFlags::ColorAttachmentOutput;
		mCmdList->SetTextureMemoryBarrier(swapchainTextures[presentImageIndex].GetHeap(), preRenderPassBarrier);

		//Begin render pass
		Color4F clearColor = bRed ? Color4F(1.0f, 0.0f, 0.0f, 1.0f) : Color4F(0.0f, 0.0f, 1.0f, 1.0f);
		mCmdList->BeginRenderPass(mRenderPass, clearColor, presentImageIndex);

		//End render pass
		mCmdList->EndRenderPass();

		//End recording
		mCmdList->EndRecording();

		//Submit commands to graphics queue with a fence
		mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());

		//Wait for fence to be signalled
		mDevice->WaitFences(mFence.GetHeapAddress(), 1);

		//Present
		if (mSwapchain->Present())
		{
			//Wait for the present
			mSwapchain->WaitForPresent(presentImageIndex);

			//Increment the current index
			presentImageIndex = (presentImageIndex + 1) % mSwapchain->GetBufferCount();
		}

		//Tick red
		bRed = !bRed;
	}
	void VulkanGraphicsModule::OnFinalize()
	{

	}
}
