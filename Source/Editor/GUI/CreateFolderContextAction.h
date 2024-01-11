#pragma once
#include <Editor/GUI/IContextCreateAction.h>
#include "CreateFolderContextAction.reflected.h"

namespace Portakal
{
	PATTRIBUTE(ContextCreateItem, "Create Folder");
	PCLASS();
	class EDITOR_API CreateFolderContextAction : public IContextCreateAction
	{
	public:
		GENERATE_OBJECT;
	public:
		CreateFolderContextAction() :mOpen(false)
		{

		}
		~CreateFolderContextAction() = default;

		virtual bool OnAction(DomainFolder* pFolder) override;
		virtual bool OnTick(DomainFolder* pFolder) override;
		virtual void OnShutdown() override;
	private:
		String mName;
		bool mOpen;
	};
}

