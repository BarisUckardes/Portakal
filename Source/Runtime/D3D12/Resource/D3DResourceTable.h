#pragma once

#include <Runtime/Graphics/Resource/ResourceTable.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;
	class RUNTIME_API D3DResourceTable : public ResourceTable
	{
	public:
		D3DResourceTable(const ResourceTableDesc& desc, D3DDevice* pDevice);
		~D3DResourceTable() override = default;

	private:
		ComPtr<ID3D12DescriptorHeap> mDescriptorHeap;
		ID3D12Device** mD3DDevice;
	};
}
