#pragma once
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Object/API.h>
#include <Editor/Resource/EditorResource.h>

namespace Portakal
{
	class EDITOR_API EditorResourceAPI : public API<EditorResourceAPI>
	{
		friend class EditorResourceModule;
	public:
		static SharedHeap<EditorResource> GetResource(const String& name);
	private:
		~EditorResourceAPI();
		EditorResourceAPI();
	private:
		HashMap<String, SharedHeap<EditorResource>> mResources;
	};
}
