#include <stdio.h>
#include <Runtime/Math/Math.h>
#include <Runtime/Math/Color4.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Math/Vector3.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Object/Object.h>
#include <Runtime/Object/API.h>
#include <Runtime/Platform/PlatformClipboard.h>
#include <Runtime/Platform/PlatformConsole.h>
#include <Runtime/Platform/PlatformCriticalSection.h>
#include <Runtime/Platform/PlatformDialog.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformError.h>
#include <Runtime/Platform/PlatformGuid.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Platform/Platform.h>
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include <Runtime/Graphics/Sampler/Sampler.h>
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Pipeline/Pipeline.h>
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <Runtime/Graphics/Resource/ResourceTablePool.h>

namespace Portakal
{
	SharedHeap<RenderPass> CreateRenderPass(Swapchain* pSwapchain,GraphicsDevice* pDevice)
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
	void RunVulkanTest()
	{
		//Initialize platform
		Platform::InitializePlatformDependencies();

		//Create window
		WindowDesc windowDesc = {};
		windowDesc.Title = "Portakal Runtime Test";
		windowDesc.Position = { 100,100 };
		windowDesc.Size = { 1024,1024 };
		windowDesc.pMonitor = nullptr;
		windowDesc.Mode = WindowMode::Windowed;

		SharedHeap<PlatformWindow> pWindow = PlatformWindow::Create(windowDesc);
		pWindow->Show();

		//Create graphics instance
		GraphicsInstanceDesc instanceDesc = {};
		instanceDesc.Backend = GraphicsBackend::Vulkan;
		SharedHeap<GraphicsInstance> pInstance = Portakal::GraphicsInstance::Create(instanceDesc);

		//Get adapter
		SharedHeap<GraphicsAdapter> pAdapter = pInstance->GetAdapters()[0];
		DEV_LOG("System", "Selecting [%s] device", *pAdapter->GetProductName());

		//Create device
		SharedHeap<GraphicsDevice> pDevice = pAdapter->CreateDevice();

		//Create swapchain
		SwapchainDesc swapchainDesc = {};
		swapchainDesc.ColorFormat = TextureFormat::R8_G8_B8_A8_UNorm;
		swapchainDesc.BufferCount = 3;
		swapchainDesc.DepthStencilFormat = TextureFormat::None;
		swapchainDesc.pWindow = pWindow;
		swapchainDesc.pDevice = pDevice;
		SharedHeap<Portakal::Swapchain> pSwapchain = pDevice->CreateSwapchain(swapchainDesc);


		//Create command pool
		SharedHeap<CommandPool> pCmdPool = pDevice->CreateCommandPool({ CommandPoolType::Graphics });

		//Create command list
		SharedHeap<CommandList> pCmdList = pDevice->CreateCommandList({ pCmdPool });

		//Create fence
		SharedHeap<Fence> pFence = pDevice->CreateFence();

		//Get swapchain textures
		Array<SharedHeap<Texture>> swapchainTextures = pSwapchain->GetTextures();

		//Create render pass set
		SharedHeap<RenderPass> pRenderPass = CreateRenderPass(pSwapchain.GetHeap(),pDevice.GetHeap());

		const byte presentImageIndexStatic = 0;
		byte presentImageIndex = 0;
		Vector2US lastWindowSize = pWindow->GetSize();
		while (!pWindow.IsShutdown())
		{
			//Poll window messages first
			pWindow->PollMessages();

			//Check if window resized and get new set of textures
			const Vector2US windowSize = pWindow->GetSize();
			if (lastWindowSize != windowSize)
			{
				DEV_LOG("System", "WindowSize changed %d,%d", windowSize.X, windowSize.Y);
				swapchainTextures = pSwapchain->GetTextures();
				pRenderPass.Shutdown();
				pRenderPass = CreateRenderPass(pSwapchain.GetHeap(), pDevice.GetHeap());
			}
			lastWindowSize = windowSize;

			//Begin recording
			pCmdList->BeginRecording();

			////Set texture layouts to color attachment
			//CommandListTextureMemoryBarrierDesc preRenderPassBarrierDesc = {};
			//preRenderPassBarrierDesc.MipIndex = 0;
			//preRenderPassBarrierDesc.ArrayIndex = 0;
			//preRenderPassBarrierDesc.AspectFlags = TextureAspectFlags::Color;

			//preRenderPassBarrierDesc.SourceLayout = TextureMemoryLayout::Present;
			//preRenderPassBarrierDesc.SourceQueue = GraphicsQueueType::Graphics;
			//preRenderPassBarrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::ColorAttachmentRead;
			//preRenderPassBarrierDesc.SourceStageFlags = PipelineStageFlags::ColorAttachmentOutput;

			//preRenderPassBarrierDesc.DestinationLayout = TextureMemoryLayout::ColorAttachment;
			//preRenderPassBarrierDesc.DestinationQueue = GraphicsQueueType::Graphics;
			//preRenderPassBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ColorAttachmentWrite;
			//preRenderPassBarrierDesc.DestinationStageFlags = PipelineStageFlags::ColorAttachmentOutput;
			//pCmdList->SetTextureMemoryBarrier(swapchainTextures[0].GetHeap(), preRenderPassBarrierDesc);

			////Begin render pass
			//pCmdList->BeginRenderPass(pPass);

			//End render pass
			pCmdList->EndRenderPass();

			//End recording
			pCmdList->EndRecording();

			//Submit commands to graphics queue with a fence
			pDevice->SubmitCommandLists(pCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, pFence.GetHeap());

			//Wait for fence to be signalled
			pDevice->WaitFences(pFence.GetHeapAddress(), 1);

			//Present
			pSwapchain->Present();

			//Wait for the present
			pSwapchain->WaitForPresent(presentImageIndex);

			//Increment the current index
			presentImageIndex = (presentImageIndex + 1) % pSwapchain->GetBufferCount();
		}

		//Wati device idle before shutdown
		pDevice->WaitDeviceIdle();

		pCmdList.Shutdown();
		pCmdPool.Shutdown();
		pFence.Shutdown();
		pRenderPass.Shutdown();
		pSwapchain.Shutdown();
		pDevice.Shutdown();
		pAdapter.Shutdown();
		pInstance.Shutdown();
		pWindow.Shutdown();
	}

	void RunD3D12Test()
	{
		//Initialize platform
		Platform::InitializePlatformDependencies();

		//Create window
		WindowDesc windowDesc = {};
		windowDesc.Title = "Portakal Runtime Test";
		windowDesc.Position = { 100,100 };
		windowDesc.Size = { 1024,1024 };
		windowDesc.pMonitor = nullptr;
		windowDesc.Mode = WindowMode::Windowed;

		SharedHeap<PlatformWindow> pWindow = PlatformWindow::Create(windowDesc);
		pWindow->Show();

		//Create graphics instance
		GraphicsInstanceDesc instanceDesc = {};
		instanceDesc.Backend = GraphicsBackend::DirectX12;
		SharedHeap<GraphicsInstance> pInstance = Portakal::GraphicsInstance::Create(instanceDesc);

		//Get adapter
		SharedHeap<GraphicsAdapter> pAdapter = pInstance->GetAdapters()[0];
		DEV_LOG("System", "Selecting [%s] device", *pAdapter->GetProductName());

		//Create device
		SharedHeap<GraphicsDevice> pDevice = pAdapter->CreateDevice();
	}
}

int main(const unsigned int argumentCount, const char** ppArguments)
{
	//Portakal::RunVulkanTest();
	Portakal::RunD3D12Test();
	return 0;
}
