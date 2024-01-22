#include "EditorPlayerGDeviceModule.h"
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Window/WindowAPI.h>
#include <Runtime/TestClass.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	void EditorPlayerGDeviceModule::OnInitialize()
	{
		//Get window
		SharedHeap<PlatformWindow> pWindow = WindowAPI::GetDefaultWindow();
		if (pWindow == nullptr)
		{
			DEV_LOG("EditorPlayerGDeviceModule", "Failed to retrieve the PlatformWindow!");
			return;
		}

		//Create instance
		GraphicsInstanceDesc instanceDesc = {};
		instanceDesc.Backend = GraphicsBackend::Vulkan;
		mInstance = GraphicsInstance::Create(instanceDesc);
		if (mInstance.IsShutdown())
		{
			DEV_LOG("EditorPlayerGDeviceModule", "No instance found!");
			return;
		}

		//Get adapter
		mAdapter = mInstance->GetAdapters()[0];
		if (mAdapter.IsShutdown())
		{
			DEV_LOG("EditorPlayerGDeviceModule", "No adapter found!");
			return;
		}

		//Create device
		mDevice = mAdapter->CreateDevice();

		//Create swapchain
		SwapchainDesc swapchainDesc = {};
		swapchainDesc.BufferCount = 2;
		swapchainDesc.ColorFormat = TextureFormat::R8_G8_B8_A8_UNorm;
		swapchainDesc.DepthStencilFormat = TextureFormat::None;
		swapchainDesc.pDevice = mDevice;
		swapchainDesc.pWindow = pWindow;
		swapchainDesc.PresentMode = PresentMode::VsyncImmediate;
		mSwapchain = mDevice->CreateSwapchain(swapchainDesc);

		//Set memory profile
		GraphicsAPI::SetMemoryProfile(MB_TO_BYTE(2048), MB_TO_BYTE(2048));
		GraphicsAPI::SetResourceProfile(4096, 4096);
	}
	void EditorPlayerGDeviceModule::OnFinalize()
	{

	}
	void EditorPlayerGDeviceModule::OnTick()
	{

	}
}
