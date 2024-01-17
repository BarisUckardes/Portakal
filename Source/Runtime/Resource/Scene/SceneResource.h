#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/World/Scene.h>
#include <Runtime/Resource/Scene/SceneDescriptor.h>
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

		bool GenerateDescriptor(SceneDescriptor& descriptorOut) const noexcept;
	private:
		virtual void OnShutdown() override;
		virtual void OnNameChange(const String& name) override;
		virtual void OnIDChange(const Guid& id) override;
	private:
		SharedHeap<Scene> mScene;
	};
}

