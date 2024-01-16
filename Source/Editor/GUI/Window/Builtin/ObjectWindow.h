#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Editor/GUI/Object/IObjectPainter.h>
#include "ObjectWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ObjectWindow : public GUIWindow
	{
		GENERATE_OBJECT;
		friend class EditorObjectAPI;
	public:
		ObjectWindow() : mPainter(nullptr), mLocked(false)
		{

		}
		~ObjectWindow() = default;

		FORCEINLINE Bool8 IsLocked() const noexcept
		{
			return mLocked;
		}

		void Lock();
		void Unlock();
	private:
		void _Signal(Type* pPainterType, const SharedHeap<Object>& pObject);

		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	private:
		IObjectPainter* mPainter;
		Bool8 mLocked;
	};
}





































