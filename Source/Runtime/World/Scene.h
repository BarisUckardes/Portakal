#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/World/SceneAspect.h>
#include <Runtime/World/Entity.h>

namespace Portakal
{
	class SceneAspect;
	class Entity;
	class RUNTIME_API Scene : public Object
	{
	public:
		Scene();
		~Scene();

		FORCEINLINE bool IsPrimal() const noexcept
		{
			return mPrimal;
		}

		SharedHeap<Entity> CreateEntity();
		template<typename T,typename... TArgs>
		void CreateAspect(TArgs... args)
		{
			//Create aspect
			SharedHeap<SceneAspect> pAspect = new T(args...);

			//Set owner scene
			pAspect->_SetOwnerScene(this);

			//Register
			mAspects.Add(pAspect);
		}
		template<typename T>
		T* GetAspect() const noexcept
		{
			const Type* pTargetType = typeof(T);

			for (const SharedHeap<SceneAspect>& pAspect : mAspects)
			{
				if (pAspect->GetType() == pTargetType)
					return pAspect.GetHeap();
			}

			return nullptr;
		}
		void MarkPrimal();
	private:
		Array<SharedHeap<Entity>> mEntities;
		Array<SharedHeap<SceneAspect>> mAspects;
		bool mPrimal;
	};
}
