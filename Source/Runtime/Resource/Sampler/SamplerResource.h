#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Command/CommandPool.h>
#include "SamplerResource.reflected.h"

namespace Portakal
{

	/// <summary>
	/// A resource sub object that is specialized in sampler works
	/// </summary>
	PATTRIBUTE(ResourceAttribute, "sampler");
	PCLASS();
	class RUNTIME_API SamplerResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
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

