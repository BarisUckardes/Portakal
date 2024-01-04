#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Object/Object.h>
#include "GUIWindow.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class RUNTIME_API GUIWindow : public Object
	{
		friend class GUIWindowAPI;
	public:
		GUIWindow() = default;
		~GUIWindow() = default;

		virtual void OnShow() = 0;
		virtual void OnHide() = 0;
		virtual void OnPaint() = 0;
		virtual void OnInitialize() = 0;
	private:
		void _SetPosition(const Vector2US position);
		void _SetSize(const Vector2US size);
		void _SetVisibility(const Bool8 bState);
	private:
		Vector2US mSize;
		Vector2US mPosition;
		Bool8 mVisible;
	};
}














