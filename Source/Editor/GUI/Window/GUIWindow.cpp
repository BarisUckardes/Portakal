#include "GUIWindow.h"

namespace Portakal
{
	GUIWindow::GUIWindow() :
		mPosition({ 0,0 }),
		mSize({ 0,0 }),
		mDockState(GUIDirection::None),
		mVisible(false)
	{
	}
	void GUIWindow::OnShutdown()
	{
	}
	void GUIWindow::Show()
	{
	}
	void GUIWindow::Hide()
	{
	}
}
