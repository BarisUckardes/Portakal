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
	}
}
