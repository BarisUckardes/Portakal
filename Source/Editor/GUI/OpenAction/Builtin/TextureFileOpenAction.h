#pragma once
#include <Editor/GUI/OpenAction/IFileOpenAction.h>
#include "TextureFileOpenAction.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomFileOpenAction, "texture");
	PCLASS();
	class EDITOR_API TextureFileOpenAction : public IFileOpenAction
	{
	public:
		TextureFileOpenAction() = default;
		~TextureFileOpenAction() = default;


		// Inherited via IFileOpenAction
		void OnOpen(DomainFile* pFile) override;

	};
}

