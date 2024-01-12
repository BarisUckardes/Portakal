#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class TextureResource;
	class ResourceTable;
	class ResourceTableLayout;
	class ResourceTablePool;
	class EDITOR_API ImGuiTextureBinding : public Object
	{
		friend class ImGuiRenderer;
	public:
		~ImGuiTextureBinding() = default;

		FORCEINLINE SharedHeap<TextureResource> GetTexture() const noexcept
		{
			return mTexture.GetHeap();
		}
		FORCEINLINE ResourceTable* GetTable() const noexcept
		{
			return mTable.GetHeap();
		}
	private:
		ImGuiTextureBinding(const SharedHeap<TextureResource>& pTexture, const SharedHeap<ResourceTableLayout>& pLayout, const SharedHeap<ResourceTablePool>& pPool);

		virtual void OnShutdown() override;
	private:
		SharedHeap<TextureResource> mTexture;
		SharedHeap<ResourceTable> mTable;
	};
}
