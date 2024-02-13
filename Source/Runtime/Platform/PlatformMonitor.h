#pragma once
#include <Runtime/Math/Vector2.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Monitor/MonitorDisplayMode.h>

namespace Portakal
{
	/// <summary>
	/// Monitor platform implementation
	/// </summary>
	class RUNTIME_API PlatformMonitor : public Object
	{
	public:
		static Array<SharedHeap<PlatformMonitor>> GetAvailableMonitors();
		static SharedHeap<PlatformMonitor> GetPrimaryMonitor();
	public:
		PlatformMonitor(const Vector2I position,const Vector2US size, const MonitorDisplayMode& currentMode, const Array<MonitorDisplayMode>& displayModes);
		~PlatformMonitor() = default;

		FORCEINLINE Vector2I GetPosition() const noexcept
		{
			return mPosition;
		}
		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE MonitorDisplayMode GetCurrentDisplayMode() const noexcept
		{
			return mCurrentDisplayMode;
		}
		FORCEINLINE Array<MonitorDisplayMode> GetDisplayModes() const noexcept
		{
			return mDisplayModes;
		}
	protected:
		void OnPositionUpdate(const Vector2I position);
		void OnSizeUpdate(const Vector2US size);
	private:
		Array<MonitorDisplayMode> mDisplayModes;
		MonitorDisplayMode mCurrentDisplayMode;
		Vector2I mPosition;
		Vector2US mSize;
	};
}
