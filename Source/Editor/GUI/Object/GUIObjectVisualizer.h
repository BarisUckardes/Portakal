#pragma once

#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
	class EDITOR_API GUIObjectVisualizer
	{
	public:
		virtual void OnInitialize() = 0;
		virtual void OnShutdown() = 0;
		virtual void OnPaint() = 0;

	protected:
		FORCEINLINE const SharedHeap<Object>& GetGUIObject() const noexcept { return mGUIObject; }

	private:
		void SetObject(const SharedHeap<Object>& pObject) noexcept { mGUIObject = pObject; }

		SharedHeap<Object> mGUIObject;
	};
}
