#pragma once
#include <Editor/GUI/OpenAction/IFileOpenAction.h>
#include "SceneFileOpenAction.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomFileOpenAction,"scene")
	PCLASS();
	class EDITOR_API SceneFileOpenAction : public IFileOpenAction
	{
	public:
		SceneFileOpenAction() = default;
		~SceneFileOpenAction() = default;
		

		// Inherited via IFileOpenAction
		void OnOpen(DomainFile* pFile) override;

	};
}

