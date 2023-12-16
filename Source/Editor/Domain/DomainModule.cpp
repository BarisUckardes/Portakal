#include "DomainModule.h"

#include <Editor/Domain/DomainAPI.h>
#include <Runtime/Platform/PlatformDirectory.h>

namespace Portakal
{
	bool DomainModule::OnInitialize()
	{
		return true;
	}

	void DomainModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}

	void DomainModule::OnPreTick()
	{
	}

	void DomainModule::OnTick()
	{
	}

	void DomainModule::OnPostTick()
	{
	}

	void DomainModule::OnPreInvalidate()
	{
	}

	void DomainModule::OnPostInvalidate()
	{
	}

	void DomainModule::OnEvent(WindowEventData& event)
	{
	}
}
