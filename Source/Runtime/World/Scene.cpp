#include "Scene.h"
#include <Runtime/World/SceneAPI.h>

namespace Portakal
{
    Scene::Scene() : mPrimal(false)
    {

    }
    SharedHeap<Scene> Scene::Create()
    {
        SharedHeap<Scene> pScene = new Scene();
        SceneAPI::_RegisterScene(pScene);
        return pScene;
    }
    Scene::~Scene()
    {
    }
    SharedHeap<Entity> Scene::CreateEntity()
    {
        //Create
        SharedHeap<Entity> pEntity = new Entity();

        //Set owner scene
        pEntity->_SetOwnerScene(this);

        mEntities.Add(pEntity);

        return pEntity;
    }
    void Scene::CreateAspect(const Type* pType)
    {
        //Create aspect
        SharedHeap<SceneAspect> pAspect = (SceneAspect*)pType->CreateDefaultHeapObject();

        //Set owner scene
        pAspect->_SetOwnerScene(this);

        //Initialize
        pAspect->OnInitialize();

        //Register
        mAspects.Add(pAspect);
    }
    void Scene::MarkPrimal()
    {
        SceneAPI::_SetScenePrimal(this);
    }
    void Scene::OnShutdown()
    {
        SceneAPI::_RemoveScene(this);
    }
    void Scene::_SetPrimalState(const Bool8 state)
    {
        mPrimal = state;
    }
}
