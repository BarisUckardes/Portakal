#include "SceneResource.h"

namespace Portakal
{
    SceneResource::SceneResource()
    {
        mScene = Scene::Create();
    }

    void SceneResource::OnShutdown()
    {
        mScene.Shutdown();
    }
}
