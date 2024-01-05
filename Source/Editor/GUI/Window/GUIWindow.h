#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Object/Object.h>
#include <Editor/GUI/GUIDirection.h>
#include "GUIWindow.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class RUNTIME_API GUIWindow : public Object
	{
		friend class GUIWindowAPI;
	public:
		GUIWindow() : mDockDirection(GUIDirection::None), mVisible(false)
		{

		}
		~GUIWindow() = default;

		FORCEINLINE GUIDirection GetDockDirection() const noexcept
		{
			return mDockDirection;
		}
		FORCEINLINE Vector2US GetSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE Vector2US GetPosition() const noexcept
		{
			return mPosition;
		}
		FORCEINLINE bool IsVisible() const noexcept
		{
			return mVisible;
		}

		virtual void OnShow() = 0;
		virtual void OnHide() = 0;
		virtual void OnPaint() = 0;
		virtual void OnInitialize() = 0;
	private:
		void _SetPosition(const Vector2US position);
		void _SetSize(const Vector2US size);
		void _SetVisibility(const Bool8 bState);
		void _SetDockDirection(const GUIDirection direction);
	private:
		GUIDirection mDockDirection;
		Vector2US mSize;
		Vector2US mPosition;
		Bool8 mVisible;
	};
}


















