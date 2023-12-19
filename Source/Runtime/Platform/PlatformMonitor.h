#pragma once
#include <Runtime/Math/Vector2.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API PlatformMonitor : public Object
	{
		static Array<SharedHeap<PlatformMonitor>> GetAvailableMonitors();
	public:

		FORCEINLINE Vector2US GetPosition() const noexcept
		{
			return mPosition;
		}
		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
	protected:
		void OnPositionUpdate(const Vector2US position);
		void OnSizeUpdate(const Vector2US size);
	private:
		Vector2US mPosition;
		Vector2US mSize;
	};
}
