#pragma once
#include <Editor/GUI/Object/IObjectPainter.h>
#include <Runtime/World/Entity.h>
#include <Runtime/Containers/HashMap.h>
#include <Editor/GUI/Component/IComponentPainter.h>
#include "EntityObjectPainter.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomObjectPainter,typeof(Portakal::Entity))
	PCLASS();
	class EDITOR_API EntityObjectPainter : public IObjectPainter
	{
		GENERATE_OBJECT;
	public:
		EntityObjectPainter() = default;
		~EntityObjectPainter() = default;

	private:
		// Inherited via IObjectPainter
		void OnInitialize() override;
		void OnPaint() override;
	private:
		Array<Type*> mComponentTypes;
		HashMap<const Type*,const Type*> mPainterMap;
		HashMap<SharedHeap<Component>, SharedHeap<IComponentPainter>> mComponentMap;
		SharedHeap<Entity> mEntity;

	};
}

