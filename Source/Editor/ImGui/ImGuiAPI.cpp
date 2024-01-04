#include "ImGuiAPI.h"

namespace Portakal
{
    SharedHeap<ImGuiRenderer> ImGuiAPI::GetRenderer()
    {
        ImGuiAPI* pAPI = GetUnderlyingAPI();
        if (pAPI == nullptr)
            return nullptr;

        return pAPI->mRenderer;
    }
    ImGuiAPI::ImGuiAPI()
    {
        mRenderer = new ImGuiRenderer();
    }
    ImGuiAPI::~ImGuiAPI()
    {
        mRenderer.Shutdown();
    }
}
