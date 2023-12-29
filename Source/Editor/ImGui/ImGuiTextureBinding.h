#pragma once

#include <Runtime/Memory/SharedHeap.h>

namespace Roveldo
{

	class Texture;
	class ResourceTable;
	class ResourceTableLayout;
	class ResourceTablePool;

	class EDITOR_API ImGuiTextureBinding
	{
	public:
		ImGuiTextureBinding(const SharedHeap<Texture>& Texture, const SharedHeap<ResourceTableLayout>& pLayout, const SharedHeap<ResourceTablePool>& pPool);
		~ImGuiTextureBinding();

		FORCEINLINE Texture* GetTexture() const { return mTargetTexture.GetHeap(); }
		FORCEINLINE ResourceTable* GetResourceTable() const { return mResourceTable.GetHeap(); }

	private:
		SharedHeap<Texture> mTargetTexture;
		SharedHeap<ResourceTable> mResourceTable;
	};
}
