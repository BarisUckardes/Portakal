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
	}
	void SceneAPI::_RemoveScene(Scene* pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		const Int32 index = pAPI->mMap.FindIndex(pScene);
		if (index == -1) // WTF
			return;

		pAPI->mMap.Remove(pScene);
		pAPI->mScenes.RemoveAt(index);

		if (pScene == pAPI->mPrimalScene.GetHeap())
			pAPI->mPrimalScene = nullptr;

		pScene->_SetPrimalState(false);
	}
	void SceneAPI::_SetScenePrimal(Scene* pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		const Int32 index = pAPI->mMap.FindIndex(pScene);
		if (index == -1) // WTF
			return;

		//Remove the primal mark of the previous primal scene
		if (!pAPI->mPrimalScene.IsShutdown())
			pAPI->mPrimalScene->_SetPrimalState(false);

		//Set scene primal
		pAPI->mPrimalScene = pAPI->mMap[index].GetValue();
		pAPI->mPrimalScene->_SetPrimalState(true);
	}
	SceneAPI::SceneAPI()
	{

	}
	SceneAPI::~SceneAPI()
	{

	}
}
