#include "GUIWindowAPI.h"

#include <Editor/GUI/Window/Templates/WorldGUIWindow.h>

namespace Portakal
{
	const Array<SharedHeap<GUIWindow>>& GUIWindowAPI::GetWindows()
	{
		GUIWindowAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mWindows;
	}
	GUIWindowAPI::GUIWindowAPI()
	{
		mWindows.Add(new WorldGUIWindow());
	}
	GUIWindowAPI::~GUIWindowAPI()
	{

	}
	void GUIWindowAPI::RemoveWindow(const SharedHeap<GUIWindow>& window)
	{
		if (!mWindows.Remove(window))
		{
			DEV_LOG("GUIWindowAPI", "Shutdown GUIWindowAPI");
		}
	}
}