#include "SceneModule.h"

namespace Portakal
{
	void SceneModule::OnInitialize()
	{
		mAPI = new SceneAPI();
	}
	void SceneModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void SceneModule::OnTick()
	{
		for (const SharedHeap<Scene>& pScene : mAPI->mScenes)
			for (const SharedHeap<SceneAspect>& pAspect : pScene->GetAspects())
				pAspect->OnExecute();
	}
}
