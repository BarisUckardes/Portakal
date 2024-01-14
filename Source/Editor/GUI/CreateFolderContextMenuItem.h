#pragma once
#include <Editor/GUI/IContextMenuItem.h>
#include "CreateFolderContextMenuItem.reflected.h"

namespace Portakal
{
	PATTRIBUTE(ContextMenuItem, "Create Folder");
	PCLASS();
	class EDITOR_API CreateFolderContextMenuItem : public IContextMenuItem
	{
	public:
		GENERATE_OBJECT;
	public:
		CreateFolderContextMenuItem() :mOpen(false)
		{

		}
		~CreateFolderContextMenuItem() = default;

		virtual bool OnAction(DomainFolder* pFolder) override;
		virtual bool OnTick(DomainFolder* pFolder) override;
		virtual void OnShutdown() override;
	private:
		String mName;
		bool mOpen;
	};
}



























