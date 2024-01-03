#include "ImguiModule.h"

namespace Portakal
{
	void ImGuiModule::OnInitialize()
	{
		//Create renderer
		mRenderer = new ImGuiRenderer();
		
		//Create API
		mAPI = nullptr;
	}
	void ImGuiModule::OnFinalize()
	{
		mRenderer.Shutdown();
	}
	void ImGuiModule::OnTick()
	{

	}
}
