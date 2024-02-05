#pragma once
#include <Runtime/World/Component.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Containers/Array.h>
#include "Entity.reflected.h"

namespace Portakal
{
	class Scene;
	PCLASS();

	/// <summary>
	/// Represents a collection of components which determines the final behaviour of the entity.
	/// </summary>
	class RUNTIME_API Entity final : public Object
	{
		GENERATE_OBJECT;
		friend class Scene;
	public:
		FORCEINLINE const Array<SharedHeap<Component>>& GetComponents() const noexcept
		{
			return mComponents;
		}
		FORCEINLINE Scene* GetOwnerScene() const noexcept
		{
			return mOwnerScene;
		}

		Bool8 HasComponent(const Type* pType) const noexcept;
		SharedHeap<Component> AddComponent(const Type* pType);
		Bool8 RemoveComponent(const Type* pType);

		template<typename T,typename... TArgs>
		SharedHeap<T> AddComponent(TArgs... args)
		{
			//Create
			SharedHeap<T> pComponent = new T(args...);

			//Set owner entity
			SharedHeap<Component> pRawComponent = pComponent.QueryAs<Component>();
			pRawComponent->_SetOwnerEntity(this);

			//Register component
			mComponents.Add(pRawComponent);

			return pComponent;
		}

		template<typename T>
		Bool8 HasComponent() const noexcept
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
		void _SetOwnerScene(Scene* pScene);
		virtual void OnShutdown() override;
	private:
		Array<SharedHeap<Component>> mComponents;
		Entity* mOwnerEntity;
		Scene* mOwnerScene;
	};
}

