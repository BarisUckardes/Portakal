#include "GUIRenderingContextCreateModule.h"

namespace Portakal
{
	void GUIRenderingContextCreateModule::OnInitialize()
	{
		// TODO: Add ImguiAPI later.
	}
	void GUIRenderingContextCreateModule::OnFinalize()
	{
		mContext.Shutdown();
	}
	void GUIRenderingContextCreateModule::OnTick()
	{
	}
}