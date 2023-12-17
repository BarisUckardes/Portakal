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

int main(const unsigned int argumentCount, const char** ppArguments)
{
	//Initialize platform
	Portakal::Platform::InitializePlatformDependencies();

	//Create window
	Portakal::WindowDesc windowDesc = {};
	windowDesc.Title = "Portakal Runtime Test";
	windowDesc.Position = { 100,100 };				
	windowDesc.Size = { 1024,1024 };
	windowDesc.pMonitor = nullptr;
	windowDesc.Mode = Portakal::WindowMode::Windowed;

	Portakal::SharedHeap<Portakal::PlatformWindow> pWindow = Portakal::PlatformWindow::Create(windowDesc);
	pWindow->Show();

	//Create graphics instance
	Portakal::GraphicsInstanceDesc instanceDesc = {};
	instanceDesc.Backend = Portakal::GraphicsBackend::Vulkan;
	Portakal::SharedHeap<Portakal::GraphicsInstance> pInstance = Portakal::GraphicsInstance::Create(instanceDesc);

	//Get adapter
	Portakal::SharedHeap<Portakal::GraphicsAdapter> pAdapter = pInstance->GetAdapters()[0];
	DEV_LOG("System", "Selecting [%s] device", *pAdapter->GetProductName());

	//Create device
	Portakal::SharedHeap<Portakal::GraphicsDevice> pDevice = pAdapter->CreateDevice();

	//Create swapchain
	Portakal::SwapchainDesc swapchainDesc = {};
	swapchainDesc.ColorFormat = Portakal::TextureFormat::R8_G8_B8_A8_UNorm;
	swapchainDesc.BufferCount = 3;
	swapchainDesc.DepthStencilFormat = Portakal::TextureFormat::None;
	swapchainDesc.pWindow = pWindow;
	swapchainDesc.pDevice = pDevice;
	Portakal::SharedHeap<Portakal::Swapchain> pSwapchain = pDevice->CreateSwapchain(swapchainDesc);
	pSwapchain->Present();
	while (!pWindow.IsShutdown())
	{
		pWindow->PollMessages();
	}

	pSwapchain.Shutdown();
	pDevice.Shutdown();
	pAdapter.Shutdown();
	pInstance.Shutdown();
	pWindow.Shutdown();
	return 0;
}
