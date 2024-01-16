#include "SceneFileOpenAction.h"
#include <Editor/Domain/DomainFile.h>
#include <Runtime/Resource/Scene/SceneResource.h>

namespace Portakal
{
	void SceneFileOpenAction::OnOpen(DomainFile* pFile)
	{
		//First load scene
		pFile->LoadSnyc();

		//Get sub resource and mark primal
		SharedHeap<SceneResource> pScene = pFile->GetSubObject().QueryAs<SceneResource>();
		pScene->GetScene()->MarkPrimal();
	}
}
