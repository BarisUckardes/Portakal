#pragma once

#include <Runtime/D3D12/D3DIncludes.h>

#include <Runtime/Graphics/Resource/GraphicsResourceType.h>

namespace Portakal
{
	class RUNTIME_API D3DResourceUtils
	{
	public:
		static D3D12_DESCRIPTOR_HEAP_TYPE GetDescriptorHeapType(GraphicsResourceType type)
		{
			switch (type)
			{
			case GraphicsResourceType::Sampler:
				return D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
			case GraphicsResourceType::SampledTexture:
			case GraphicsResourceType::StorageTexture:
			case GraphicsResourceType::CombinedTextureSampler:
			case GraphicsResourceType::ConstantBuffer:
			case GraphicsResourceType::StorageBuffer:
				return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
			default:
				return D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES;
			}
		}

	private:
		D3DResourceUtils() = delete;
		~D3DResourceUtils() = delete;
	};
}
