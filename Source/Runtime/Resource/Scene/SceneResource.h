#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/World/Scene.h>
#include "SceneResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API SceneResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
		SceneResource();
		~SceneResource() = default;

		FORCEINLINE Scene* GetScene() const noexcept
		{
			return mScene.GetHeap();
		}

	private:
		virtual void OnShutdown() override;
	private:
		SharedHeap<Scene> mScene;
	};
}

