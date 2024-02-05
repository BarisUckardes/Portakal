#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Object/API.h>
#include <Runtime/World/Scene.h>

namespace Portakal
{
	/// <summary>
	/// API for the scene works
	/// </summary>
	class RUNTIME_API SceneAPI : public API<SceneAPI>
	{
		friend class SceneModule;
		friend class Scene;
	public:
		static SharedHeap<Scene> GetPrimalScene();
		static Array<SharedHeap<Scene>> GetScenes();
		static void TransitionSync(const String& resourceName);
	private:
		static void _RegisterScene(const SharedHeap<Scene>& pScene);
		static void _RemoveScene(Scene* pTargetScene);
		static void _SetScenePrimal(Scene* pTargetScene);
	private:
		SceneAPI();
		~SceneAPI();
	private:
		Array<SharedHeap<Scene>> mScenes;
		SharedHeap<Scene> mPrimalScene;
	};
}
