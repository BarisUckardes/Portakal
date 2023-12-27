#pragma once

#include <Runtime/Math/Vector2.h>
#include <Editor/GUI/GUIViewportFlags.h>

namespace Portakal
{
	typedef uint32 GUIID;

	class EDITOR_API GUIViewport final
	{
	public:
		GUIViewport();
		~GUIViewport() = default;

		FORCEINLINE GUIID GetID() const { return mID; }
		FORCEINLINE GUIViewportFlags GetFlags() const { return mFlags; }
		FORCEINLINE Vector2F GetPosition() const { return mPosition; }
		FORCEINLINE Vector2F GetSize() const { return mSize; }
		FORCEINLINE Vector2F GetWorkPosition() const { return mWorkPosition; }
		FORCEINLINE Vector2F GetWorkSize() const { return mWorkSize; }
		FORCEINLINE float GetDPIScale() const { return mDPIScale; }
		FORCEINLINE GUIID GetParentViewportID() const { return mParentViewportID; }

	private:
		const GUIID mID;
		const GUIViewportFlags mFlags;
		const Vector2F mPosition;
		const Vector2F mSize;
		const Vector2F mWorkPosition;
		const Vector2F mWorkSize;
		const float mDPIScale;
		const GUIID mParentViewportID;
	};
}
