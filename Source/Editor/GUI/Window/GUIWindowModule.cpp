#include "GUIWindowModule.h"
#include <Runtime/Window/WindowAPI.h>

namespace Portakal
{
	void GUIWindowModule::OnInitialize()
	{
		mAPI = new GUIWindowAPI();
	}
	void GUIWindowModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void GUIWindowModule::OnTick()
	{
		if (WindowAPI::GetDefaultWindow().IsShutdown())
			return;

		mAPI->Render();
	}
	void GUIWindowModule::OnPreInvalidation()
	{

	}
	void GUIWindowModule::OnPostInvalidation()
	{

	}
}
