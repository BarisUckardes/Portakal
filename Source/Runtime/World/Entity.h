#pragma once
#include <Runtime/World/Component.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class Scene;
	class RUNTIME_API Entity final
	{
	public:
		FORCEINLINE const Array<SharedHeap<Entity>>& GetEntities() const noexcept
		{
			return mEntities;
		}
		FORCEINLINE const Array<SharedHeap<Component>>& GetComponents() const noexcept
		{
			return mComponents;
		}
		FORCEINLINE Entity* GetOwnerEntity() const noexcept
		{
			return mOwnerEntity;
		}
		FORCEINLINE Scene* GetOwnerScene() const noexcept
		{
			return mOwnerScene;
		}

		void SetOwnerEntity(const SharedHeap<Entity>& pOwnerEntity);
		SharedHeap<Component> AddComponent(const Type* pType);
		bool RemoveComponent(const Type* pType);
		bool HasComponent(const Type* pType) const noexcept;
		template<typename T,typename... TArgs>
		SharedHeap<T> AddComponent(TArgs... args)
		{
			//Create
			SharedHeap<T> pComponent = new T(args...);

			//Set owner entity
			SharedHeap<Component> pRawComponent = pComponent.QueryAs<Component>(pComponent);
			pRawComponent->_SetOwnerEntity(this);

			//Register component
			mComponents.Add(pRawComponent);

			return pComponent
		}
		template<typename T>
		bool HasComponent() const noexcept
		{
			const Type* pTargetType = typeof(T);
			for (const SharedHeap<Component>& pComponent : mComponents)
			{
				if (pTargetType == pComponent->GetType())
					return true;
			}

			return false;
		}
	private:
		Array<SharedHeap<Entity>> mEntities;
		Array<SharedHeap<Component>> mComponents;
		Entity* mOwnerEntity;
		Scene* mOwnerScene;
	};
}
