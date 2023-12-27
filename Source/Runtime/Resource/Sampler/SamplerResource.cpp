#include "SamplerResource.h"

namespace Portakal
{
	SamplerResource::SamplerResource(const SharedHeap<GraphicsDevice>& pDevice)
	{
		mDevice = pDevice;
	}
	SamplerResource::SamplerResource()
	{

	}
	void SamplerResource::Create(const SamplerDesc& desc)
	{
		if (IsShutdown())
			return;

		if (mDevice.IsShutdown())
			return;

		Clear();

		mSampler = mDevice->CreateSampler(desc);
	}
	void SamplerResource::Clear()
	{
		mSampler.Shutdown();
	}
	void SamplerResource::OnShutdown()
	{
		Clear();
	}
}
