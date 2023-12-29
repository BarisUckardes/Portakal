#include "DomainModule.h"
#include <Editor/Domain/DomainAPI.h>

namespace Portakal
{
	void DomainModule::OnInitialize()
	{
		mAPI = new DomainAPI("");
	}
	void DomainModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void DomainModule::OnTick()
	{
	}
}
