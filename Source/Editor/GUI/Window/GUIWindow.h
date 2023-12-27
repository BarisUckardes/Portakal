#pragma once

#include <Runtime/Object/Object.h>
#include <Runtime/Math/Vector2.h>

#include <Editor/GUI/GUIDirection.h>

namespace Portakal
{
	class EDITOR_API GUIWindow : public Object
	{
		friend class GUIWindowModule;

	public:
		GUIWindow();
		~GUIWindow() override = default;

		FORCEINLINE Vector2UI GetSize() const noexcept { return mSize; }
		FORCEINLINE Vector2I GetPosition() const noexcept { return mPosition; }
		FORCEINLINE bool IsVisible() const noexcept { return mVisible; }
		FORCEINLINE GUIDirection GetDockState() const noexcept { return mDockState; }

		virtual void OnShow() = 0;
		virtual void OnHide() = 0;
		virtual void OnPaint() = 0;
		virtual void OnInitialize() = 0;
		virtual void OnShutdown() override;

		void Show();
		void Hide();

	private:
		void SetPosition(const Vector2I position) { mPosition = position; }
		void SetSize(const Vector2UI size) { mSize = size; }
		void SetVisible(const bool visible) { mVisible = visible; }
		void SetDockState(const GUIDirection dockState) { mDockState = dockState; }
	private:
		Vector2UI mSize;
		Vector2I mPosition;
		bool mVisible;
		GUIDirection mDockState;
	};
}
