#pragma once
#include <Editor/GUI/ContextCreateItem.h>
#include <Editor/Domain/DomainFolder.h>
#include <Runtime/Memory/SharedHeap.h>
#include "IContextCreateAction.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class EDITOR_API IContextCreateAction : public Object
	{
	public:
		GENERATE_OBJECT;
	public:
		IContextCreateAction() = default;
		~IContextCreateAction() = default;

		virtual bool OnAction(DomainFolder* pFolder) = 0;
		virtual bool OnTick(DomainFolder* pFolder) = 0;
	};
}

