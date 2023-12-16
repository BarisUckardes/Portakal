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


int main(const unsigned int argumentCount, const char** ppArguments)
{
	/*
	* Initialize platform
	*/
	Portakal::Platform::InitializePlatformDependencies();

	Portakal::WindowDesc windowDesc = {};
	windowDesc.Title = "Portakal Runtime Test";
	windowDesc.Position = { 100,100 };				
	windowDesc.Size = { 1024,1024 };
	windowDesc.pMonitor = nullptr;
	windowDesc.Mode = Portakal::WindowMode::Windowed;

	Portakal::SharedHeap<Portakal::PlatformWindow> pWindow = Portakal::PlatformWindow::Create(windowDesc);

	pWindow->Show();

	while (!pWindow.IsShutdown())
	{
		pWindow->PollMessages();
	}
	return 0;
}
