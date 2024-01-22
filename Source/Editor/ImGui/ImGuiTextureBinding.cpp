#include "ImGuiTextureBinding.h"
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	ImGuiTextureBinding::ImGuiTextureBinding(const SharedHeap<TextureResource>& pTexture, const SharedHeap<ResourceTableLayout>& pLayout) : mTexture(pTexture)
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

		
		//Create resource table
		ResourceTableDesc tableDesc = {};
		tableDesc.pOwnerPool = GraphicsAPI::GetDefaultTablePool().GetHeap();
		tableDesc.pTargetLayout = pLayout.GetHeap();
		mTable = pTexture->GetDevice()->CreateResourceTable(tableDesc);

		//Update resource table
		ResourceTableUpdateDesc updateDesc = {};
		updateDesc.Entries.Add(
			{
					.pResource = pTexture->GetView(0, 0).QueryAs<GraphicsDeviceObject>(),
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
