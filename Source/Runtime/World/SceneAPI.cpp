#include "SceneAPI.h"
#include <Runtime/Resource/ResourceAPI.h>
#include <Runtime/Resource/Scene/SceneResource.h>

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
	void SceneAPI::TransitionSync(const String& resourceName)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Get resource
		SharedHeap<Resource> sceneResource = ResourceAPI::GetResource(resourceName);
		if (sceneResource.IsShutdown())
			return;

		//Load scene
		sceneResource->LoadSync();

		//Set scene primal
		sceneResource.QueryAs<SceneResource>()->GetScene()->MarkPrimal();
	}
	void SceneAPI::_RegisterScene(const SharedHeap<Scene>& pScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mScenes.Add(pScene);
	}
	void SceneAPI::_RemoveScene(Scene* pTargetScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Look for the scene
		for (UInt32 i = 0; i < pAPI->mScenes.GetSize(); i++)
		{
			const SharedHeap<Scene>& pScene = pAPI->mScenes[i];
			if (pScene.GetHeap() == pTargetScene)
			{
				pAPI->mScenes.RemoveAt(i);
			}
		}
		
		if (pTargetScene == pAPI->mPrimalScene.GetHeap())
			pAPI->mPrimalScene = nullptr;

		pTargetScene->_SetPrimalState(false);
	}
	void SceneAPI::_SetScenePrimal(Scene* pTargetScene)
	{
		SceneAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Remove the primal mark of the previous primal scene
		if (!pAPI->mPrimalScene.IsShutdown())
			pAPI->mPrimalScene->_SetPrimalState(false);

		//Set scene primal
		for (UInt32 i = 0; i < pAPI->mScenes.GetSize(); i++)
		{
			const SharedHeap<Scene>& pScene = pAPI->mScenes[i];
			if (pScene.GetHeap() == pTargetScene)
			{
				pScene->_SetPrimalState(true);
				pAPI->mPrimalScene = pScene;
				break;
			}
		}
	}
	SceneAPI::SceneAPI()
	{

	}
	SceneAPI::~SceneAPI()
	{

	}
}
