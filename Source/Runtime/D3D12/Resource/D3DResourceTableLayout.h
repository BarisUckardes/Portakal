#pragma once

#include <Runtime/Graphics/Resource/ResourceTableLayout.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;

	class RUNTIME_API D3DResourceTableLayout : public ResourceTableLayout
	{
	public:
		D3DResourceTableLayout(const ResourceTableLayoutDesc& desc, D3DDevice* pDevice);
		~D3DResourceTableLayout() override = default;

		ComPtr<ID3D12RootSignature> GetRootSignature() const { return mRootSignature; }
	private:
		ComPtr<ID3D12RootSignature> mRootSignature;
	};
}
