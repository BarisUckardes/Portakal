#pragma once
#include <Runtime/Core/Core.h>
#include <Editor/GUI/OpenAction/CustomFileOpenAction.h>
#include "IFileOpenAction.reflected.h"

namespace Portakal
{
	class DomainFile;
	PCLASS(Virtual);
	class EDITOR_API IFileOpenAction
	{
	public:
		IFileOpenAction() = default;
		~IFileOpenAction() = default;

		virtual void OnOpen(DomainFile* pFile) = 0;
	};
}

