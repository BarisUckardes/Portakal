#pragma once
#include <Editor/GUI/OpenAction/IFileOpenAction.h>
#include "ShaderFileOpenAction.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomFileOpenAction, "shader")
	PCLASS();
	class EDITOR_API ShaderFileOpenAction : public IFileOpenAction
	{
	public:
		ShaderFileOpenAction() = default;
		~ShaderFileOpenAction() = default;


		// Inherited via IFileOpenAction
		void OnOpen(DomainFile* pFile) override;
	};
}

