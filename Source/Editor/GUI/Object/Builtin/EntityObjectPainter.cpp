#include "EntityObjectPainter.h"
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Editor/GUI/Component/IComponentPainter.h>
#include <Editor/GUI/Component/Builtin/DefaultComponentPainter.h>
#include <imgui.h>


namespace Portakal
{
	void EntityObjectPainter::OnInitialize()
	{
		//Get all component sub types
		Array<Type*> painters = ReflectionAPI::GetSubTypes(typeof(IComponentPainter));
		for (Type* pPainterType : painters)
		{
			//Get attribute
			CustomComponentPainter* pAttribute = pPainterType->GetAttribute<CustomComponentPainter>();
			if (pAttribute == nullptr)
				continue;

			mPainterMap.Insert(pAttribute->GetTargetType(), pPainterType);
		}

		//Get entity
		mEntity = GetTargetObject().QueryAs<Entity>();

		//Get component types
		mComponentTypes = ReflectionAPI::GetSubTypes(typeof(Component));
	}
	void EntityObjectPainter::OnPaint()
	{
		//Validate entity
		if (mEntity.IsShutdown())
		{
			ImGui::Text("Entity is shutdown!");
			return;
		}

		//Iterate component
		Array<SharedHeap<Component>> components = mEntity->GetComponents();
		for (SharedHeap<Component>& pComponent : components)
		{
			//Check if needs registration
			if (mComponentMap.FindIndex(pComponent) == -1)
			{
				const Type** pPainterType = mPainterMap.Find(pComponent->GetType());
				if (pPainterType != nullptr)
				{
					SharedHeap<IComponentPainter> pPainter = (IComponentPainter*)(*pPainterType)->CreateDefaultHeapObject();
					pPainter->_SetComponent(pComponent);
					pPainter->OnInitialize();
					mComponentMap.Insert(pComponent, pPainter);
				}
			}

			//Try get painter
			SharedHeap<IComponentPainter>* pPainter = mComponentMap.Find(pComponent);
			if (pPainter == nullptr)
				continue;

			if (ImGui::CollapsingHeader(*pComponent->GetType()->GetName()))
			{
				(*pPainter)->OnPaint();
			}
		}

		//Add button
		if (ImGui::Button("+"))
		{
			ImGui::OpenPopup("ComponentAddPopup");
		}


		//Handle popups
		if (ImGui::BeginPopup("ComponentAddPopup"))
		{
			for (const Type* pType : mComponentTypes)
			{
				if (ImGui::Selectable(*pType->GetName()))
				{
					mEntity->AddComponent(pType);
				}
			}
			ImGui::EndPopup();
		}
	}
}
