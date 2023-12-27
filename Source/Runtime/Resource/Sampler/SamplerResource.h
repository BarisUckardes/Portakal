#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Command/CommandPool.h>

namespace Portakal
{
	class RUNTIME_API SamplerResource : public ResourceSubObject
	{
	public:
		SamplerResource(const SharedHeap<GraphicsDevice>& pDevice);
		SamplerResource();
		~SamplerResource() = default;

		FORCEINLINE SharedHeap<Sampler> GetSampler() const noexcept
		{
			return mSampler;
		}

		void Create(const SamplerDesc& desc);
	private:
		void Clear();
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<Sampler> mSampler;
	};
}
