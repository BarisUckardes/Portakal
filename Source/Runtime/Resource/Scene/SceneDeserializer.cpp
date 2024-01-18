#include "SceneDeserializer.h"
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Runtime/Resource/ResourceAPI.h>
#include <Runtime/World/Component/InvalidComponent.h>

namespace Portakal
{
	ResourceSubObject* SceneDeserializer::Deserialize(const MemoryView& view,const String& metaData)
	{
		SceneResource* pScene = new SceneResource();

		//TODO: Get scene descriptor and populate the scene
		const String yamlContent((char*)view.GetMemory(), view.GetSize());
		SceneDescriptor descriptor = {};
		Yaml::ToObject<SceneDescriptor>(yamlContent, &descriptor);

		//Load resources
		for (const Guid& id : descriptor.Resources)
		{
			SharedHeap<Resource> pResource = ResourceAPI::GetResource(id);
			if(pResource.IsAlive())
				pResource->LoadSync();
		}

		//Create aspects
		for (const String& aspectName : descriptor.Aspects)
		{
			const Type* pType = ReflectionAPI::GetType(aspectName);
			if (pType == nullptr)
				continue;

			//Create
			pScene->GetScene()->CreateAspect(pType);
		}

		//Create entities
		Array<SharedHeap<Entity>> createdEntities;
		for (const SceneEntityDescriptor& entity : descriptor.Entities)
		{
			SharedHeap<Entity> pEntity = pScene->GetScene()->CreateEntity();
			pEntity->SetName(entity.Name);
			pEntity->OverrideID(entity.ID);
			createdEntities.Add(pEntity);
		}

		//Create components
		for (UInt32 entityIndex = 0;entityIndex < createdEntities.GetSize();entityIndex++)
		{
			const SharedHeap<Entity>& pEntity = createdEntities[entityIndex];
			const SceneEntityDescriptor& entityDescriptor = descriptor.Entities[entityIndex];
			for (const SceneComponentDescriptor& component : entityDescriptor.Components)
			{
				//Find type
				const Type* pType = ReflectionAPI::GetType(component.TypeName);
				if (pType == nullptr) // we should need to add to map instead of array
				{
					//Create ýnvalid component
					SharedHeap<InvalidComponent> pComponent = pEntity->AddComponent<InvalidComponent>(component.TypeName);
					pComponent->SetName(component.Name);
					pComponent->OverrideID(component.ID);
					continue;
				}

				SharedHeap<Component> pComponent = pEntity->AddComponent(pType);
				pComponent->SetName(component.Name);
				pComponent->OverrideID(component.ID);

				//Set variables
				for (const SceneComponentFieldDescriptor& field : component.Fields)
				{
					const Field* pField = pType->GetField(field.FieldName);
					const Type* pFieldType = pField->GetType();

					if (field.Mode == FieldMode::Normal)
					{
						if (pFieldType == typeof(Int32))
						{
							const Int32 value = String::ToInt32(field.FieldValue);
							pField->SetValue<Int32>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(UInt32))
						{
							const UInt32 value = String::ToUInt32(field.FieldValue);
							pField->SetValue<UInt32>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(Int64))
						{
							const Int64 value = String::ToInt64(field.FieldValue);
							pField->SetValue<Int64>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(UInt64))
						{
							const UInt64 value = String::ToUInt64(field.FieldValue);
							pField->SetValue<UInt64>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(Float32))
						{
							const Float32 value = String::ToFloat32(field.FieldValue);
							pField->SetValue<Float32>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(Float64))
						{
							const Float64 value = String::ToFloat64(field.FieldValue);
							pField->SetValue<Float64>(pComponent.GetHeap(), value);
						}
						else if (pFieldType == typeof(String))
						{
							pField->SetValue<String>(pComponent.GetHeap(), field.FieldValue);
						}
					}
					else if (field.Mode == FieldMode::Array)
					{

					}
					else if (field.Mode == FieldMode::Object)
					{

					}
				}
			}
		}

		//Set component fields
		return pScene;
	}
	ResourceSubObject* SceneDeserializer::DeserializeOptimized(const MemoryView& view,const String& metaData)
	{
		return nullptr;
	}
}
