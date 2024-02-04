#include "MaterialResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	MaterialResource::MaterialResource()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}

	void MaterialResource::SetMemoryProfile(const SharedHeap<GraphicsMemoryHeap>& pHeapDevice, const SharedHeap<GraphicsMemoryHeap>& pHeapHost, const SharedHeap<ResourceTablePool>& pPool)
	{
		if (IsShutdown())
			return;

		mHeapDevice = pHeapDevice;
		mHeapHost = pHeapHost;
		mTablePool = pPool;
	}
	void MaterialResource::SetShaderProfile(const Array<SharedHeap<ShaderResource>>& shaders)
	{
		if (IsShutdown())
			return;

		//Clear former event subs
		for (const SharedHeap<ShaderResource>& pShader : mShaders)
			pShader->RemoveOnNewShadersEvent(GENERATE_MEMBER_DELEGATE1(this,MaterialResource::OnShaderStateChanged,void,ShaderResource*));

		//Clear current tables
		ClearTableDescriptors();

		//Set new shaders
		mShaders = shaders;

		//Create new table descriptors
		CreateTableDescriptors();

		//Generate event subs
		for (const SharedHeap<ShaderResource>& pShader : mShaders)
			pShader->RegisterOnNewShadersEvent(GENERATE_MEMBER_DELEGATE1(this, MaterialResource::OnShaderStateChanged, void, ShaderResource*));
	}
	void MaterialResource::ClearTableDescriptors()
	{
		for (const RegistryEntry<UInt32,MaterialTableDescriptor>& pair : mTableDescriptors)
			for (const MaterialParameter& parameter : pair.Value.Parameters)
				if (parameter.pBufferMemory != nullptr)
					delete parameter.pBufferMemory;

		mTableDescriptors.Clear();
	}
	void MaterialResource::CreateTableDescriptors()
	{
		//Iterate shader reflections
		for (const SharedHeap<ShaderResource>& pShader : mShaders)
		{
			const SharedHeap<ShaderReflection>& pReflection = pShader->GetReflection();
			const Array<ShaderTableDescriptor>& tableDescriptors = pReflection->GetTableDescriptors();
			for (const ShaderTableDescriptor& tableDescriptor : tableDescriptors)
			{
				//Get or create table entry
				MaterialTableDescriptor* pMaterialTableDescriptor = mTableDescriptors.GetEntryValue(tableDescriptor.TableIndex);
				if (pMaterialTableDescriptor == nullptr)
				{
					mTableDescriptors.Register(tableDescriptor.TableIndex, {});
					pMaterialTableDescriptor = mTableDescriptors.GetEntryValue(tableDescriptor.TableIndex);
				}

				//Iterate bindings
				for (const ShaderTableBinding& binding : tableDescriptor.Bindings)
				{
					MaterialParameter parameter = {};
					parameter.Name = binding.Name;
					parameter.BindingIndex = binding.BindingIndex;
					switch (binding.Type)
					{
						case Portakal::ShaderTableBindingType::None:
							break;
						case Portakal::ShaderTableBindingType::ConstantBuffer:
						{
							parameter.Type = MaterialParameterType::Buffer;
							break;
						}
						case Portakal::ShaderTableBindingType::Texture:
						{
							parameter.Type = MaterialParameterType::Texture;
							break;
						}
						case Portakal::ShaderTableBindingType::Sampler:
						{
							parameter.Type = MaterialParameterType::Sampler;
							break;
						}
						default:
							break;
					}
					
					//Create buffer memory if constant buffer
					if (parameter.Type == MaterialParameterType::Buffer)
					{
						GraphicsBufferDesc deviceBufferDesc = {};
						deviceBufferDesc.SubItemCount = 1;
						deviceBufferDesc.SubItemSizeInBytes = binding.BlockMember.Size;
						deviceBufferDesc.Usage = GraphicsBufferUsage::ConstantBuffer | GraphicsBufferUsage::TransferDestination;
						deviceBufferDesc.pHeap = mHeapDevice;
						parameter.pBufferDevice = mDevice->CreateBuffer(deviceBufferDesc);

						GraphicsBufferDesc hostBufferDesc = {};
						deviceBufferDesc.SubItemCount = 1;
						deviceBufferDesc.SubItemSizeInBytes = binding.BlockMember.Size;
						deviceBufferDesc.Usage = GraphicsBufferUsage::ConstantBuffer | GraphicsBufferUsage::TransferSource;
						deviceBufferDesc.pHeap = mHeapHost;
						parameter.pBufferHost = mDevice->CreateBuffer(deviceBufferDesc);

						Byte* pBuffer = new Byte[binding.BlockMember.Size];
						parameter.pBufferMemory = new MemoryOwnedView(pBuffer,binding.BlockMember.Size);
						delete[] pBuffer;
					}
				}
			}
		}
	}
	void MaterialResource::OnShaderStateChanged(ShaderResource* pShader)
	{
		//Refresh state

		//Invoke state change event
		mOnStateChangeEvent.Invoke(this);
	}
	void MaterialResource::RegisterStateChangedEvent(const Delegate<void, MaterialResource*>& del)
	{
		mOnStateChangeEvent += del;
	}
	void MaterialResource::RemoveStateChangedEvent(const Delegate<void, MaterialResource*>& del)
	{
		mOnStateChangeEvent -= del;
	}
}
