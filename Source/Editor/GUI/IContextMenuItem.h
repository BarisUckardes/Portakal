#pragma once
#include <Editor/GUI/ContextMenuItem.h>
#include <Editor/Domain/DomainFolder.h>
#include <Runtime/Memory/SharedHeap.h>
#include "IContextMenuItem.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class EDITOR_API IContextMenuItem : public Object
	{
	public:
		GENERATE_OBJECT;
	public:
		IContextMenuItem() = default;
		~IContextMenuItem() = default;

		virtual bool OnAction(DomainFolder* pFolder) = 0;
		virtual bool OnTick(DomainFolder* pFolder) = 0;
	};
}











