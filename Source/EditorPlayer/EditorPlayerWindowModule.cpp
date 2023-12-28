#include "EditorPlayerWindowModule.h"
#include <Runtime/Application/Application.h>

namespace Portakal
{
    void EditorPlayerWindowModule::OnInitialize()
    {
        //Create window
        WindowDesc desc = {};
        desc.Size = { 1024,1024 };
        desc.Position = { 100,100 };
        desc.Title = "Portakal Editor Player";
        desc.Mode = WindowMode::Windowed;
        desc.pMonitor = nullptr;
        mWindow = PlatformWindow::Create(desc);
    }
    void EditorPlayerWindowModule::OnFinalize()
    {
        mWindow.Shutdown();
    }
    void EditorPlayerWindowModule::OnTick()
    {
        if (mWindow.IsShutdown())
            GetOwnerApplication()->PostQuitRequest("Editor player window is closed!");
    }
}
