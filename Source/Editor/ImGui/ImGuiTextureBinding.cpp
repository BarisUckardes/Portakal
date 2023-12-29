#include "ImGuiTextureBinding.h"

#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Texture/Texture.h>
#include <Runtime/Graphics/Resource/ResourceTable.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>
#include <Runtime/Graphics/Resource/ResourceTablePool.h>

namespace Portakal
{
	ImGuiTextureBinding::ImGuiTextureBinding(const SharedHeap<Texture>& pTexture, const SharedHeap<ResourceTableLayout>& pLayout, const SharedHeap<ResourceTablePool>& pPool)
	{
		if (pTexture.IsShutdown() || !pTexture.IsValid())
		{
			DEV_LOG("ImGuiTextureBinding", "The Texture is not valid!");
			return;
		}

		if (pLayout.IsShutdown() || !pLayout.IsValid())
		{
			DEV_LOG("ImGuiTextureBinding", "The ResourceTableLayout is not valid!");
			return;
		}

		if (pPool.IsShutdown() || !pPool.IsValid())
		{
			DEV_LOG("ImGuiTextureBinding", "The ResourceTablePool is not valid!");
			return;
		}

		GraphicsDevice* pDevice = pTexture->GetOwnerDevice();

		if (pDevice == nullptr)
		{
			DEV_LOG("ImGuiTextureBinding", "The GraphicsDevice is not valid!");
			return;
		}

		ResourceTableUpdateDesc updateDesc = {};
		updateDesc.Entries.Add(
			{
				.pResource = pTexture.GetHeap(),
				.Type = GraphicsResourceType::SampledTexture,
				.Count = 1,
				.ArrayElement = 0,
				.BufferOffsetInBytes = 0,
				.Binding = 0
			}
		);

		pDevice->UpdateResourceTable(mResourceTable.GetHeap(), updateDesc);
	}

	ImGuiTextureBinding::~ImGuiTextureBinding()
	{
		mResourceTable.Shutdown();
	}
}
