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
		friend class SceneAPI;
	public:
		static SharedHeap<Scene> Create();
	public:
		~Scene();

		FORCEINLINE Bool8 IsPrimal() const noexcept
		{
			return mPrimal;
		}
		FORCEINLINE const Array<SharedHeap<Entity>>& GetEntities() const noexcept
		{
			return mEntities;
		}
		FORCEINLINE const Array<SharedHeap<SceneAspect>>& GetAspects() const noexcept
		{
			return mAspects;
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
		virtual void OnShutdown() override;
	private:
		Scene();
		void _SetPrimalState(const Bool8 state);
	private:
		Array<SharedHeap<Entity>> mEntities;
		Array<SharedHeap<SceneAspect>> mAspects;
		Bool8 mPrimal;
	};
}
