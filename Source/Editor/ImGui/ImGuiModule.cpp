#include "ImguiModule.h"

namespace Portakal
{
	void ImGuiModule::OnInitialize()
	{
		//Create API
		mAPI = new ImGuiAPI();
	}
	void ImGuiModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void ImGuiModule::OnTick()
	{

	}
}
