#include "ImGuiRenderStartModule.h"
#include <Runtime/Graphics/GraphicsAPI.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Editor/ImGui/ImGuiAPI.h>
#include <Runtime/Window/WindowAPI.h>

namespace Portakal
{
    void ImGuiRenderStartModule::OnInitialize()
    {
    }
    void ImGuiRenderStartModule::OnFinalize()
    {
    }
    void ImGuiRenderStartModule::OnTick()
    {
        //Get imgui renderer
        SharedHeap<ImGuiRenderer> pRenderer = ImGuiAPI::GetRenderer();
        if (pRenderer.IsShutdown())
        {
            DEV_LOG("ImGuiRenderStartModule", "No renderer found!");
            return;
        }

        //Get window
        SharedHeap<PlatformWindow> pWindow = WindowAPI::GetDefaultWindow();
        if (pWindow.IsShutdown())
        {
            DEV_LOG("ImGuiRendererStartModule", "No window found");
            return;
        }

        //Get window events
        const Array<WindowEventData>& events = pWindow->GetEvents();
        for (const WindowEventData& event : events)
        {
             switch (event.Type)
             {
                 case Portakal::WindowEventType::KeyboardDown:
                     pRenderer->OnKeyboardKeyDown(event.KeyboardKey);
                     break;
                 case Portakal::WindowEventType::KeyboardUp:
                     pRenderer->OnKeyboardKeyUp(event.KeyboardKey);
                     break;
                 case Portakal::WindowEventType::Char:
                     pRenderer->OnKeyboardChar(event.KeyboardChar);
                     break;
                 case Portakal::WindowEventType::MouseButtonDown:
                     pRenderer->OnMouseButtonDown(event.MouseButton);
                     break;
                 case Portakal::WindowEventType::MouseButtonUp:
                     pRenderer->OnMouseButtonUp(event.MouseButton);
                     break;
                 case Portakal::WindowEventType::MouseMoved:
                     pRenderer->OnMouseMoved(event.MousePosition);
                     break;
                 case Portakal::WindowEventType::MouseScrolled:
                     pRenderer->OnMouseWheel(event.MouseWheelDelta);
                     break;
                 default:
                     break;
             }
        }
        //Start rendering
        pRenderer->StartRendering(0.0016f); // 60fps dummy
    }
}
