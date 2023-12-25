#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API SceneAspect
	{
	public:
		FORCEINLINE SharedHeap<Scene> GetOwnerScene() const noexcept
		{
			return mOwnerScene;
		}

		virtual void OnInitialize() = 0;
		virtual void OnExecute() = 0;
		virtual void OnFinalize() = 0;
	private:
		SharedHeap<Scene> mOwnerScene;
	};
}
