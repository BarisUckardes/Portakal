#include "WindowModule.h"
#include <Runtime/Window/WindowAPI.h>

namespace Portakal
{
	void WindowModule::OnInitialize()
	{
		mAPI = new WindowAPI();
		DEV_LOG("WindowModule", "Window API initialized!");
	}
	void WindowModule::OnTick()
	{

	}
	void WindowModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
		DEV_LOG("WindowMoudle", "Window API finalized!");
	}

	void WindowModule::OnPreInvalidation()
	{

	}
	void WindowModule::OnPostInvalidation()
	{

	}
}
