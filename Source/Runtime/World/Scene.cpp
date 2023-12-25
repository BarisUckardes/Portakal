#include "Scene.h"

namespace Portakal
{
    Scene::Scene()
    {
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
    void Scene::MarkPrimal()
    {
    }
}
