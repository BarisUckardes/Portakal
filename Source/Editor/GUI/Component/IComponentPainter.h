#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/World/Component.h>
#include <Editor/GUI/Component/CustomComponentPainter.h>
#include "IComponentPainter.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class EDITOR_API IComponentPainter : public Object
	{
		friend class EntityObjectPainter;
		GENERATE_OBJECT;
	public:
		IComponentPainter() = default;
		~IComponentPainter() = default;

		virtual void OnInitialize() = 0;
		virtual void OnPaint() = 0;
	protected:
		FORCEINLINE SharedHeap<Component> GetTargetComponent() const noexcept
		{
			return mTargetComponent;
		}
	private:
		void _SetComponent(const SharedHeap<Component>& pComponent);
	private:
		SharedHeap<Component> mTargetComponent;
	};
}


