#pragma once
#include <Runtime/Platform/PlatformMonitor.h>
#include <Windows.h>

namespace Portakal
{
	class RUNTIME_API Win32Monitor : public PlatformMonitor
	{
	public:
		static Array<SharedHeap<PlatformMonitor>> GetAvailableMonitors();
		static SharedHeap<PlatformMonitor> GetPrimaryMonitor();
	public:
		Win32Monitor(const HMONITOR handle,
			const MonitorDisplayMode& currentDisplayMode,
			const Array<MonitorDisplayMode>& displayModes, const Int32 positionX,
			const Int32 positionY,const UInt16 width,const UInt16 height);
		~Win32Monitor() = default;


		FORCEINLINE HMONITOR GetWin32Handle() const noexcept
		{
			return mHandle;
		}
	private:
		virtual void OnShutdown() override;
	private:
		const HMONITOR mHandle;
	};
}
