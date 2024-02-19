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
#include "MaterialResource.reflected.h"

namespace Portakal
{
	/// <summary>
	/// A resource sub object that is specialized in general material works
	/// </summary>
	PATTRIBUTE(ResourceAttribute, "material");
	PCLASS();
	class RUNTIME_API MaterialResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
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

		void SetMemoryProfile(const SharedHeap<GraphicsMemory>& pHeapDevice,const SharedHeap<GraphicsMemory>& pHeapHost,const SharedHeap<ResourceTablePool>& pPool);
		void SetShaderProfile(const Array<SharedHeap<ShaderResource>>& shaders);
		void SetTextureParameter(const ShaderStage stage, const String& parameterName, const SharedHeap<TextureResource>& pTexture, const Byte arrayIndex, const Byte mipIndex);
		void SetSamplerParameter(const ShaderStage stage, const String& parameterName, const SharedHeap<SamplerResource>& pSampler);
		void UpdateTables();
		void RegisterStateChangedEvent(const Delegate<void, MaterialResource*>& del);
		void RemoveStateChangedEvent(const Delegate<void, MaterialResource*>& del);
	private:
		void InvalidateBufferMemory();
		void InvalidateTablePool();
		void ClearTableDescriptors();
		void CreateTableDescriptors();
		void OnShaderStateChanged(ShaderResource* pShader);
	private:
		Registry<UInt32, MaterialTableDescriptor> mTableDescriptors;
		Array<SharedHeap<ResourceTable>> mResourceTables;
		Array<SharedHeap<ResourceTableLayout>> mResourceTableLayouts;
		Array<SharedHeap<ShaderResource>> mShaders;
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<ResourceTablePool> mTablePool;
		SharedHeap<GraphicsMemory> mHeapDevice;
		SharedHeap<GraphicsMemory> mHeapHost;
		Event<void, MaterialResource*> mOnStateChangeEvent;
	};
}

