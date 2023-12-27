#include "D3DResourceTable.h"

#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	D3DResourceTable::D3DResourceTable(const ResourceTableDesc& desc, D3DDevice* pDevice) : ResourceTable(desc)
	{
		mD3DDevice = pDevice->GetD3DDevice().GetAddressOf();

		D3D12_DESCRIPTOR_HEAP_DESC d3dDesc = {};
		d3dDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
		d3dDesc.NumDescriptors = desc.pTargetLayout->GetEntries().GetSize();
	}
}
