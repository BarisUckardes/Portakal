#include "SamplerResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	SamplerResource::SamplerResource()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();

		if (mDevice.IsShutdown())
			return;
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
