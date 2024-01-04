#include "GUIWindow.h"

namespace Portakal
{
	void GUIWindow::_SetPosition(const Vector2US position)
	{
		mPosition = position;
	}
	void GUIWindow::_SetSize(const Vector2US size)
	{
		mSize = size;
	}
	void GUIWindow::_SetVisibility(const Bool8 bState)
	{
		mVisible = bState;
	}
}
