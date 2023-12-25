#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Memory/SharedHeap.h>
#include "Component.reflected.h"

namespace Portakal
{
	class Entity;
	PCLASS();
	class RUNTIME_API Component : public Object
	{
		friend class Entity;
	public:
		FORCEINLINE SharedHeap<Entity> GetOwnerEntity() const noexcept
		{
			return mOwnerEntity;
		}

		virtual void OnInitialize() = 0;
		virtual void OnFinalize() = 0;
	private:
		void _SetOwnerEntity(Entity* pEntity);
	private:
		Entity* mOwnerEntity;
	};
}







