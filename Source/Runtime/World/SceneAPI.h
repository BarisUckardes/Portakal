#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Object/API.h>
#include <Runtime/World/Scene.h>

namespace Portakal
{
	class RUNTIME_API SceneAPI : public API<SceneAPI>
	{
		friend class SceneModule;
	public:
		static SharedHeap<Scene> GetPrimalScene();
		static Array<SharedHeap<Scene>> GetScenes();
	private:
		static void _RegisterScene(const SharedHeap<Scene>& pScene);
		static void _RemoveScene(Scene* pScene);
		static void _SetScenePrimal(Scene* pScene);
	private:
		SceneAPI();
		~SceneAPI();
	private:
		Array<SharedHeap<Scene>> mScenes;
		HashMap<Scene*, SharedHeap<Scene>> mMap;
		SharedHeap<Scene> mPrimalScene;
	};
}
