#pragma once
#include <Editor/Resource/EditorResourceType.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Resource/ResourceSubObject.h>

namespace Portakal
{
	class EDITOR_API EditorResource : public Object
	{
	public:
		EditorResource(const String& path) : mPath(path)
		{

		}
		~EditorResource() = default;
		
		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}

		virtual EditorResourceType GetResourceType() const noexcept = 0;
		virtual SharedHeap<ResourceSubObject> GetResource()  noexcept = 0;
	private:
		const String mPath;
	};
}
