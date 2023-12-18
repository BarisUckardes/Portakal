#include "Texture.h"

namespace Portakal
{
	Texture::Texture(const TextureDesc& desc,const bool bSwapchain) :
		mType(desc.Type),mUsages(desc.Usage),mFormat(desc.Format),mSize(desc.Size),mMipLevels(desc.MipLevels),mArrayLevels(desc.ArrayLevels),mSampleCount(desc.SampleCount),mHeap(desc.pHeap),mSwapchain(bSwapchain)
	{

	}
}
