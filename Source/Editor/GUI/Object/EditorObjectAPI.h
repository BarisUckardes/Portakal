#pragma once
#include <Editor/GUI/Object/IObjectPainter.h>
#include <Editor/GUI/Window/Builtin/ObjectWindow.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	class EDITOR_API EditorObjectAPI : public API<EditorObjectAPI>
	{
		friend class EditorObjectModule;
		friend class ObjectWindow;
	public:
		static void SignalObject(const SharedHeap<Object>& pObject);
		static Type* GetPainterType(const SharedHeap<Object>& pObject);
	private:
		static void _RegisterWindow(ObjectWindow* pWindow);
		static void _RemoveWindow(ObjectWindow* pWindow);
	private:
		EditorObjectAPI() = default;
		~EditorObjectAPI() = default;

	private:
		Array<ObjectWindow*> mWindows;
	};
}
