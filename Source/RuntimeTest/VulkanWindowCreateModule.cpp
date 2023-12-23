#include "VulkanWindowCreateModule.h"
#include <Runtime/Application/Application.h>

namespace Portakal
{
	void VulkanWindowCreateModule::OnInitialize()
	{
		//Get monitor
		Array<SharedHeap<PlatformMonitor>> monitors = PlatformMonitor::GetAvailableMonitors();

		//Create window
		WindowDesc windowDesc = {};
		windowDesc.Title = "Portakal Runtime Test";
		windowDesc.Position = { 100,100 };
		windowDesc.Size = { 1024,1024 };

		windowDesc.pMonitor = monitors[0];
		windowDesc.Mode = WindowMode::Fullscreen;

		mWindow = PlatformWindow::Create(windowDesc);
		mWindow->Show();
	}
	void VulkanWindowCreateModule::OnFinalize()
	{
		mWindow.Shutdown();
	}
	void VulkanWindowCreateModule::OnTick()
	{
		String reason = "Main window closed";
		if (mWindow.IsShutdown())
			GetOwnerApplication()->PostQuitRequest(reason);
	}
}
