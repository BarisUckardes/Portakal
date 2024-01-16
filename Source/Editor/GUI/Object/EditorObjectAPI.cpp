#include "EditorObjectAPI.h"
#include <Runtime/Reflection/ReflectionAPI.h>

namespace Portakal
{
	void EditorObjectAPI::SignalObject(const SharedHeap<Object>& pObject)
	{
		//Get and validate API
		EditorObjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//Check if there's available windows
		if (pAPI->mWindows.GetSize() == 0)
			return;

		//Try find object painter
		Type* pPainterType = GetPainterType(pObject);
		if (pPainterType == nullptr)
			return;

		//Signal object windows if found painter type
		for (ObjectWindow* pWindow : pAPI->mWindows)
			pWindow->_Signal(pPainterType,pObject);
	}
	Type* EditorObjectAPI::GetPainterType(const SharedHeap<Object>& pObject)
	{
		//Validate
		if (pObject->IsShutdown())
			return nullptr;

		//Get type
		Type* pObjectType = pObject->GetType();

		//Try get painters
		Array<Type*> painterTypes = ReflectionAPI::GetSubTypes(typeof(IObjectPainter));
		for (Type* pType : painterTypes)
		{
			//Get attribute
			CustomObjectPainter* pAttribute = pType->GetAttribute<CustomObjectPainter>();
			if (pAttribute == nullptr)
				continue;

			if (pAttribute->GetTargetType() == pObjectType)
				return pType;
		}

		return nullptr;
	}
	void EditorObjectAPI::_RegisterWindow(ObjectWindow* pWindow)
	{
		//Get and validate API
		EditorObjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mWindows.Add(pWindow);
		DEV_LOG("EditorObjectAPI", "Registered window");
	}
	void EditorObjectAPI::_RemoveWindow(ObjectWindow* pWindow)
	{
		//Get and validate API
		EditorObjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mWindows.Remove(pWindow);
		DEV_LOG("EditorObjectAPI", "Removed window");
	}
}
