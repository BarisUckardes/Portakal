#include "SamplerFileOpenAction.h"
#include <Editor/Domain/DomainFile.h>
#include <Editor/GUI/Object/EditorObjectAPI.h>
#include <Runtime/Resource/Sampler/SamplerResource.h>

namespace Portakal
{
	void SamplerFileOpenAction::OnOpen(DomainFile* pFile)
	{
		//First load the sampler
		pFile->LoadSync();

		//Get sub resource and signal object
		EditorObjectAPI::SignalObject(pFile->GetSubObject().QueryAs<Object>());

	}
}
