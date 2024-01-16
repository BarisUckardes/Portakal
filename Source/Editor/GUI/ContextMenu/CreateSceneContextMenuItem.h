#pragma once
#include <Editor/GUI/ContextMenu/IContextMenuItem.h>
#include "CreateSceneContextMenuItem.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomContextMenuItem,"Create Scene")
	PCLASS();
	class EDITOR_API CreateSceneContextMenuItem : public IContextMenuItem
	{
		GENERATE_OBJECT;
	public:
		CreateSceneContextMenuItem() : mOpen(false)
		{

		}
		~CreateSceneContextMenuItem() = default;

	private:
		// Inherited via IContextMenuItem
		bool OnAction(DomainFolder* pFolder) override;
		bool OnTick(DomainFolder* pFolder) override;
	private:
		String mName;
		bool mOpen;
	};
}

