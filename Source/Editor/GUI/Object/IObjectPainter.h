#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Editor/GUI/Object/CustomObjectPainter.h>
#include <Runtime/Memory/SharedHeap.h>
#include "IObjectPainter.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class EDITOR_API IObjectPainter : public Object
	{
		GENERATE_OBJECT;
		friend class ObjectWindow;
	public:
		IObjectPainter() = default;
		~IObjectPainter() = default;

		virtual void OnInitialize() = 0;
		virtual void OnPaint() = 0;
	protected:
		FORCEINLINE SharedHeap<Object> GetTargetObject() const noexcept
		{
			return mTargetObject;
		}
	private:
		void _SetTargetObject(const SharedHeap<Object>& pObject);
	private:
		SharedHeap<Object> mTargetObject;
	};
}

