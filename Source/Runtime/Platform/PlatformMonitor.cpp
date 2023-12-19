#include "PlatformMonitor.h"

#ifdef PORTAKAL_PLATFORM_WINDOWNS
#endif

namespace Portakal
{
	Array<SharedHeap<PlatformMonitor>> PlatformMonitor::GetAvailableMonitors()
	{
		return Array<SharedHeap<PlatformMonitor>>();
	}
	void PlatformMonitor::OnPositionUpdate(const Vector2US position)
	{
		mPosition = position;
	}
	void PlatformMonitor::OnSizeUpdate(const Vector2US size)
	{
		mSize = size;
	}
}
