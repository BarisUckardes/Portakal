#include "PlatformMonitor.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Monitor.h>
typedef Portakal::Win32Monitor PlatformAbstraction;
#endif

namespace Portakal
{
	Array<SharedHeap<PlatformMonitor>> PlatformMonitor::GetAvailableMonitors()
	{
		return PlatformAbstraction::GetAvailableMonitors();
	}
	SharedHeap<PlatformMonitor> PlatformMonitor::GetPrimaryMonitor()
	{
		return PlatformAbstraction::GetPrimaryMonitor();
	}
	PlatformMonitor::PlatformMonitor(const Vector2I position,const Vector2US size, const MonitorDisplayMode& currentMode, const Array<MonitorDisplayMode>& displayModes) : mPosition(position),mSize(size), mCurrentDisplayMode(currentMode), mDisplayModes(displayModes)
	{

	}
	void PlatformMonitor::OnPositionUpdate(const Vector2I position)
	{
		mPosition = position;
	}
	void PlatformMonitor::OnSizeUpdate(const Vector2US size)
	{
		mSize = size;
	}
}
