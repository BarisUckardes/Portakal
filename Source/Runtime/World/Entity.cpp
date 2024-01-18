#include "Entity.h"

namespace Portakal
{
	Bool8 Entity::HasComponent(const Type* pType) const noexcept
	{
		return Bool8();
	}
	SharedHeap<Component> Entity::AddComponent(const Type* pType)
	{
		SharedHeap<Component> pComponent = (Component*)pType->CreateDefaultHeapObject();
		pComponent->_SetOwnerEntity(this);
		pComponent->OnInitialize();

		mComponents.Add(pComponent);

		return pComponent;
	}
	Bool8 Entity::RemoveComponent(const Type* pType)
	{
		return Bool8();
	}
	void Entity::_SetOwnerScene(Scene* pScene)
	{
		mOwnerScene = pScene;
	}
	void Entity::OnShutdown()
	{

	}
}
