#include "ShaderFileOpenAction.h"
#include <Editor/Domain/DomainFile.h>
#include <Runtime/Resource/Scene/SceneResource.h>
#include <Editor/GUI/Object/EditorObjectAPI.h>

namespace Portakal
{
	void ShaderFileOpenAction::OnOpen(DomainFile* pFile)
	{
		//First load scene
		pFile->LoadSnyc();

		//Get sub resource and mark primal
		EditorObjectAPI::SignalObject(pFile->GetSubObject().QueryAs<Object>());
	}
}
