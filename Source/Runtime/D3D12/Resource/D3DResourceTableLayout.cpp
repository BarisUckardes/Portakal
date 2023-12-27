#include "D3DResourceTableLayout.h"

#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	D3DResourceTableLayout::D3DResourceTableLayout(const ResourceTableLayoutDesc& desc, D3DDevice* pDevice) : ResourceTableLayout(desc)
	{


		D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
		rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
		rootSignatureDesc.NumParameters = desc.Entries.GetSize();


	}
}