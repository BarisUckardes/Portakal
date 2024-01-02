#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include "SceneAspect.reflected.h"

namespace Portakal
{
	class Scene;
	PCLASS(Virtual);
	class RUNTIME_API SceneAspect : public Object
	{
		GENERATE_OBJECT;
		friend class Scene;
	public:
		virtual void OnInitialize() = 0;
		virtual void OnExecute() = 0;
		virtual void OnFinalize() = 0;
	protected:
		FORCEINLINE Scene* GetOwnerScene() const noexcept
		{
			return mOwnerScene;
		}
	private:
		void _SetOwnerScene(Scene* pScene);
	private:
		Scene* mOwnerScene;
	};
}
















































































































