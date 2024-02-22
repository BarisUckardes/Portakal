#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class TextureResource;
	class DescriptorSet;
	class DescriptorSetLayout;
	class DescriptorSetPool;
	class EDITOR_API ImGuiTextureBinding : public Object
	{
		friend class ImGuiRenderer;
	public:
		~ImGuiTextureBinding() = default;

		FORCEINLINE SharedHeap<TextureResource> GetTexture() const noexcept
		{
			return mTexture.GetHeap();
		}
		FORCEINLINE DescriptorSet* GetTable() const noexcept
		{
			return mTable.GetHeap();
		}
	private:
		ImGuiTextureBinding(const SharedHeap<TextureResource>& pTexture, const SharedHeap<DescriptorSetLayout>& pLayout);

		virtual void OnShutdown() override;
	private:
		SharedHeap<TextureResource> mTexture;
		SharedHeap<DescriptorSet> mTable;
	};
}
