#include "ImGuiTextureBinding.h"
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <Runtime/Resource/Texture/TextureResource.h>

namespace Portakal
{
	ImGuiTextureBinding::ImGuiTextureBinding(const SharedHeap<TextureResource>& pTexture, const SharedHeap<ResourceTableLayout>& pLayout, const SharedHeap<ResourceTablePool>& pPool) : mTexture(pTexture)
	{
		//Check given texture
		if (pTexture.IsShutdown())
		{
			DEV_LOG("ImGuiTextureBinding", "Given texture is invalid!");
			return;
		}

		//Check table layout
		if (pLayout.IsShutdown())
		{
			DEV_LOG("ImGuiTextureBinding", "Given resource table layout is invalid!");
			return;
		}

		//Check pool
		if (pPool.IsShutdown())
		{
			DEV_LOG("ImGuiTextureBinding", "Given resource table pool is invalid!");
			return;
		}

		//Create resource table
		ResourceTableDesc tableDesc = {};
		tableDesc.pOwnerPool = pPool.GetHeap();
		tableDesc.pTargetLayout = pLayout.GetHeap();
		mTable = pTexture->GetDevice()->CreateResourceTable(tableDesc);

		//Update resource table
		ResourceTableUpdateDesc updateDesc = {};
		updateDesc.Entries.Add(
			{
					.pResource = pTexture->GetView(0,0).GetHeap(),
					.Type = GraphicsResourceType::SampledTexture,
					.Count = 1,
					.ArrayElement = 0,
					.BufferOffsetInBytes = 0,
					.Binding = 0
			});

		pTexture->GetDevice()->UpdateResourceTable(mTable.GetHeap(), updateDesc);
	}
	void ImGuiTextureBinding::OnShutdown()
	{
		mTable.Shutdown();
	}
}
