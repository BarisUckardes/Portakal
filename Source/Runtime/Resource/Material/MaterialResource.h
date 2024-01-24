#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Command/CommandPool.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Resource/Shader/ShaderResource.h>
#include <Runtime/Resource/Sampler/SamplerResource.h>
#include <Runtime/Resource/Material/MaterialParameterType.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include <Runtime/Containers/Registry.h>

namespace Portakal
{
	class RUNTIME_API MaterialResource : public ResourceSubObject
	{
	private:
		struct MaterialParameter
		{
			MaterialParameterType Type = MaterialParameterType::None;
			String Name;
			UInt32 BindingIndex;
			MemoryOwnedView* pBufferMemory = nullptr;
			SharedHeap<TextureResource> pTexture;
			SharedHeap<SamplerResource> pSampler;
			SharedHeap<GraphicsBuffer> pBufferDevice;
			SharedHeap<GraphicsBuffer> pBufferHost;
		};
		struct MaterialTableDescriptor
		{
			Array<MaterialParameter> Parameters;
		};
	public:
		MaterialResource();
		~MaterialResource() = default;

		FORCEINLINE Array<SharedHeap<ShaderResource>> GetShaders() const noexcept
		{
			return mShaders;
		}
		FORCEINLINE Array<SharedHeap<ResourceTable>> GetTables() const noexcept
		{
			return mResourceTables;
		}
		FORCEINLINE Array<SharedHeap<ResourceTableLayout>> GetTableLayouts() const noexcept
		{
			return mResourceTableLayouts;
		}

		void SetMemoryProfile(const SharedHeap<GraphicsMemoryHeap>& pHeapDevice,const SharedHeap<GraphicsMemoryHeap>& pHeapHost,const SharedHeap<ResourceTablePool>& pPool);
		void SetShaderProfile(const Array<SharedHeap<ShaderResource>>& shaders);
		void SetTextureParameter(const ShaderStage stage, const String& parameterName, const SharedHeap<TextureResource>& pTexture, const Byte arrayIndex, const Byte mipIndex);
		void SetSamplerParameter(const ShaderStage stage, const String& parameterName, const SharedHeap<SamplerResource>& pSampler);
		void UpdateTables();
	private:
		void InvalidateBufferMemory();
		void InvalidateTablePool();
		void ClearTableDescriptors();
		void CreateTableDescriptors();
	private:
		Registry<UInt32, MaterialTableDescriptor> mTableDescriptors;
		Array<SharedHeap<ResourceTable>> mResourceTables;
		Array<SharedHeap<ResourceTableLayout>> mResourceTableLayouts;
		Array<SharedHeap<ShaderResource>> mShaders;
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<ResourceTablePool> mTablePool;
		SharedHeap<GraphicsMemoryHeap> mHeapDevice;
		SharedHeap<GraphicsMemoryHeap> mHeapHost;
	};
}
