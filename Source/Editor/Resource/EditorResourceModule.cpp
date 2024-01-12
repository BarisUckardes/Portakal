#include "EditorResourceModule.h"

namespace Portakal
{
    void EditorResourceModule::OnInitialize()
    {
        mAPI = new EditorResourceAPI();
    }
    void EditorResourceModule::OnFinalize()
    {
        delete mAPI;
        mAPI = nullptr;
    }
    void EditorResourceModule::OnTick()
    {
    }
}
