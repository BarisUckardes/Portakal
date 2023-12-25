#include "SceneAPI.h"

namespace Portakal
{
	SharedHeap<Scene> SceneAPI::GetPrimalScene()
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mPrimalScene;
	}
	Array<SharedHeap<Scene>> SceneAPI::GetScenes()
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mScenes;
	}
	void SceneAPI::_RegisterScene(const SharedHeap<Scene>& pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mScenes.Add(pScene);
		pAPI->mMap.Insert(pScene.GetHeap(), pScene);

		if (pAPI->mScenes.GetSize() == 1)
			pAPI->mPrimalScene = pScene;
	}
	void SceneAPI::_RemoveScene(Scene* pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		const int32 index = pAPI->mMap.FindIndex(pScene);
		if (index == -1) // WTF
			return;

		pAPI->mMap.Remove(pScene);
		pAPI->mScenes.RemoveAt(index);

		if (pAPI->mScenes.GetSize() == 1)
			pAPI->mPrimalScene = pAPI->mScenes[0];
	}
	void SceneAPI::_SetScenePrimal(Scene* pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		const int32 index = pAPI->mMap.FindIndex(pScene);
		if (index == -1) // WTF
			return;

		//TODO: Remove the primal mark of the previous primal scene
		if (!pAPI->mPrimalScene.IsShutdown())
		{

		}
	}
	SceneAPI::SceneAPI()
	{

	}
	SceneAPI::~SceneAPI()
	{

	}
}
