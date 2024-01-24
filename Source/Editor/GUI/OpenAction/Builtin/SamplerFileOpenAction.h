#pragma once
#include <Editor/GUI/OpenAction/IFileOpenAction.h>
#include "SamplerFileOpenAction.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomFileOpenAction, "sampler");
	PCLASS();
	class EDITOR_API SamplerFileOpenAction : public IFileOpenAction
	{
	public:
		SamplerFileOpenAction() = default;
		~SamplerFileOpenAction() = default;

		// Inherited via IFileOpenAction
		void OnOpen(DomainFile* pFile) override;

	};
}

