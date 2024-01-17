#include "SceneResource.h"

namespace Portakal
{
    SceneResource::SceneResource()
    {
        mScene = Scene::Create();
    }

    void EntityCollectResource(const SharedHeap<Entity>& pEntity, SceneDescriptor& descriptor)
    {
        //Get the components of this entity
        const Array<SharedHeap<Component>> components = pEntity->GetComponents();
        for (const SharedHeap<Component>& pComponent : components)
        {
            const Type* pType = pComponent->GetType();
            const Array<Field*> fields = pType->GetFields();
            for (const Field* pField : fields)
            {
                const Type* pFieldType = pField->GetType();
                if (pFieldType->IsSubClassOf(typeof(ResourceSubObject)))
                {
                    const Guid id = pField->GetValue<Guid>(pComponent.GetHeap());
                    if(!descriptor.Resources.Has(id))
                        descriptor.Resources.Add(id);
                }
            }
        }

        //Get the sub entities
        const Array<SharedHeap<Entity>> subEntities = pEntity->GetEntities();
        for (const SharedHeap<Entity>& pSubEntity : subEntities)
            EntityCollectResource(pSubEntity, descriptor);
    }
    void CollectComponent(const SharedHeap<Component>& pComponent, SceneEntityDescriptor& entityDescriptor)
    {
        SceneComponentDescriptor componentDescriptor = {};
        componentDescriptor.Name = pComponent->GetName();
        componentDescriptor.ID = pComponent->GetID();
        componentDescriptor.TypeName = pComponent->GetType()->GetName();

        //Collect fields
        const Array<Field*> fields = pComponent->GetType()->GetFields();
        for (const Field* pField : fields)
        {
            SceneComponentFieldDescriptor fieldDescriptor = {};
            fieldDescriptor.FieldName = pField->GetName();
            fieldDescriptor.Mode = pField->GetMode();
            //TODO: fieldDescriptor.FieldValue = ;
            componentDescriptor.Fields.Add(fieldDescriptor);
        }

        entityDescriptor.Components.Add(componentDescriptor);
    }
    void CollectEntity(const SharedHeap<Entity>& pEntity,SceneDescriptor& descriptor)
    {
        SceneEntityDescriptor entityDescriptor = {};
        entityDescriptor.Name = pEntity->GetName();
        entityDescriptor.ID = pEntity->GetID();

        //Collect components
        const Array<SharedHeap<Component>>& components = pEntity->GetComponents();
        for (const SharedHeap<Component>& pComponent : components)
            CollectComponent(pComponent, entityDescriptor);

        descriptor.Entities.Add(entityDescriptor);
    }
    bool SceneResource::GenerateDescriptor(SceneDescriptor& descriptor) const noexcept
    {
        //Validate scene integrity
        if (mScene.IsShutdown())
            return false;

        //Get aspects
        const Array<SharedHeap<SceneAspect>>& aspects = mScene->GetAspects();
        for (const SharedHeap<SceneAspect>& pAspect : aspects)
            descriptor.Aspects.Add(pAspect->GetType()->GetName());

        //Search for resources
        const Array<SharedHeap<Entity>>& entities = mScene->GetEntities();
        for (const SharedHeap<Entity>& pEntity : entities)
            EntityCollectResource(pEntity, descriptor);

        //Get entities
        for (const SharedHeap<Entity>& pEntity : entities)
            CollectEntity(pEntity, descriptor);

        return true;
    }

    void SceneResource::OnShutdown()
    {
        mScene.Shutdown();
    }
    void SceneResource::OnNameChange(const String& name)
    {
        if (!mScene.IsShutdown())
        {
            mScene->SetName(name);
        }
    }
    void SceneResource::OnIDChange(const Guid& id)
    {
        if (!mScene.IsShutdown())
        {
            mScene->OverrideID(id);
        }
    }
}
