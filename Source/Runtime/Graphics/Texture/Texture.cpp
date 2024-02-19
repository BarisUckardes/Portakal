#include "Texture.h"
#include <Runtime/Graphics/Texture/TextureUtils.h>

namespace Portakal
{
	Texture::Texture(const TextureDesc& desc,const Bool8 bSwapchain) :
		mType(desc.Type),mUsages(desc.Usage),mFormat(desc.Format),
		mSize(desc.Size),mMipLevels(desc.MipLevels),mArrayLevels(desc.ArrayLevels),
		mSampleCount(desc.SampleCount),mSwapchain(bSwapchain),mHeap(desc.pHeap)
	{
		//Allocate(desc.Size.X * desc.Size.Y * desc.Size.Z * TextureUtils::GetFormatSize(desc.Format));
	}
	void Texture::OnShutdown()
	{
	}
}
