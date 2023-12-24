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
#include <Runtime/Platform/PlatformMonitor.h>
#include <Runtime/Platform/PlatformLibrary.h>
#include <Runtime/Platform/PlatformMessage.h>
#include <Runtime/Platform/PlatformMutex.h>
#include <Runtime/Platform/PlatformProcess.h>
#include <Runtime/Platform/PlatformRegistry.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/ReflectionManifest.h>
#include <RuntimeTest/VulkanApplication.h>
#include <Runtime/Window/WindowModule.h>
#include <RuntimeTest/VulkanWindowCreateModule.h>
#include <RuntimeTest/VulkanGraphicsModule.h>
#include <Runtime/D3D12/Texture/D3DTexture.h>

namespace Portakal
{

	void RunVulkanTest()
	{
		//Initialize platform
		Platform::InitializePlatformDependencies();

		//Create application
		VulkanApplication* pApplication = new VulkanApplication();

		//Add modules
		pApplication->RegisterModule<WindowModule>(0);
		pApplication->RegisterModule<VulkanWindowCreateModule>(1);
		pApplication->RegisterModule<VulkanGraphicsModule>(2);

		//Run application
		pApplication->Run();
	}


	void RunD3DTest()
	{
		Platform::InitializePlatformDependencies();

		//Get monitor
		Array<SharedHeap<PlatformMonitor>> monitors = PlatformMonitor::GetAvailableMonitors();
		;
		//Create window
		WindowDesc windowDesc = {};
		windowDesc.Title = "Portakal Runtime Test";
		windowDesc.Position = { (monitors[0]->GetSize().X - 1280) / 2, (monitors[0]->GetSize().Y - 720) / 2 };
		windowDesc.Size = { 1280, 720 };
		windowDesc.pMonitor = monitors[0];
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

		SharedHeap<Texture> texturetest;

		TextureDesc textureDesc = {};
		textureDesc.Size = { 1280, 1, 1 };
		textureDesc.ArrayLevels = 1;
		textureDesc.MipLevels = 1;
		textureDesc.Format = TextureFormat::None;
		textureDesc.Usage = TextureUsage::ColorAttachment;
		textureDesc.Type = TextureType::Texture2D;
		textureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
		
		texturetest = pDevice->CreateTexture(textureDesc);
	}
}

int main(const unsigned int argumentCount, const char** ppArguments)
{
	Portakal::RunD3DTest();
	//Portakal::RunVulkanTest();
	return 0;
}
