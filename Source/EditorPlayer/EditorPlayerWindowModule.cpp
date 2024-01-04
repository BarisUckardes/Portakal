#include "EditorPlayerWindowModule.h"
#include <Runtime/Application/Application.h>
#include <Runtime/Platform/PlatformMonitor.h>

namespace Portakal
{
    void EditorPlayerWindowModule::OnInitialize()
    {
        //Get primary monitor
        SharedHeap<PlatformMonitor> pMonitor = PlatformMonitor::GetPrimaryMonitor();

        //Create window
        WindowDesc desc = {};
        desc.Size = pMonitor->GetSize();
        desc.Position = { 0,0 };
        desc.Title = "Portakal Editor Player";
        desc.Mode = WindowMode::Windowed;
        desc.pMonitor = pMonitor;
        mWindow = PlatformWindow::Create(desc);
    }
    void EditorPlayerWindowModule::OnFinalize()
    {
        mWindow.Shutdown();
    }
    void EditorPlayerWindowModule::OnTick()
    {
        if (mWindow.IsShutdown())
        {
            GetOwnerApplication()->PostQuitRequest("Editor player window is closed!");
            return;
        }

        mWindow->PollMessages();
    }
}
