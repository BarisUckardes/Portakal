#include "GUIRenderingContextCreateModule.h"

namespace Portakal
{
	void GUIRenderingContextCreateModule::OnInitialize()
	{
		// TODO: Add ImguiAPI later.
	}
	void GUIRenderingContextCreateModule::OnFinalize()
	{
		mGUIRenderingContext.Shutdown();
	}
	void GUIRenderingContextCreateModule::OnTick()
	{
	}
}