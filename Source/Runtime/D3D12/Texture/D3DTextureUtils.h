#pragma once

#include <Runtime/D3D12/D3DIncludes.h>

#include <Runtime/Graphics/Texture/TextureFormat.h>

namespace Portakal
{
    class RUNTIME_API D3DTextureUtils
    {
    public:
        static DXGI_FORMAT GetD3DTextureFormat(TextureFormat format)
        {
            switch (format)
            {
            case TextureFormat::None:
                return DXGI_FORMAT_UNKNOWN;
            case TextureFormat::R8_G8_B8_A8_UNorm:
                return DXGI_FORMAT_R8G8B8A8_UNORM;
            case TextureFormat::B8_G8_R8_A8_UNorm:
                return DXGI_FORMAT_B8G8R8A8_UNORM;
            case TextureFormat::R8_UNorm:
                return DXGI_FORMAT_R8_UNORM;
            case TextureFormat::R16_UNorm:
                return DXGI_FORMAT_R16_UNORM;
            case TextureFormat::R32_G32_B32_A32_Float:
                return DXGI_FORMAT_R32G32B32A32_FLOAT;
            case TextureFormat::R32_Float:
                return DXGI_FORMAT_R32_FLOAT;
            case TextureFormat::BC3_UNorm:
                return DXGI_FORMAT_BC3_UNORM;
            case TextureFormat::D24_UNorm_S8_UInt:
                return DXGI_FORMAT_D24_UNORM_S8_UINT;
            case TextureFormat::D32_Float_S8_UInt:
                return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
            case TextureFormat::R32_G32_B32_A32_UInt:
                return DXGI_FORMAT_R32G32B32A32_UINT;
            case TextureFormat::R8_G8_SNorm:
                return DXGI_FORMAT_R8G8_SNORM;
            case TextureFormat::BC1_Rgb_UNorm:
                return DXGI_FORMAT_BC1_UNORM;
            case TextureFormat::BC1_Rgba_UNorm:
                return DXGI_FORMAT_BC1_UNORM;
            case TextureFormat::BC2_UNorm:
                return DXGI_FORMAT_BC2_UNORM;
            case TextureFormat::R10_G10_B10_A2_UNorm:
                return DXGI_FORMAT_R10G10B10A2_UNORM;
            case TextureFormat::R10_G10_B10_A2_UInt:
                return DXGI_FORMAT_R10G10B10A2_UINT;
            case TextureFormat::R11_G11_B10_Float:
                return DXGI_FORMAT_R11G11B10_FLOAT;
            case TextureFormat::R8_SNorm:
                return DXGI_FORMAT_R8_SNORM;
            case TextureFormat::R8_UInt:
                return DXGI_FORMAT_R8_UINT;
            case TextureFormat::R8_SInt:
                return DXGI_FORMAT_R8_SINT;
            case TextureFormat::R16_SNorm:
                return DXGI_FORMAT_R16_SNORM;
            case TextureFormat::R16_UInt:
                return DXGI_FORMAT_R16_UINT;
            case TextureFormat::R16_SInt:
                return DXGI_FORMAT_R16_SINT;
            case TextureFormat::R16_Float:
                return DXGI_FORMAT_R16_FLOAT;
            case TextureFormat::R32_UInt:
                return DXGI_FORMAT_R32_UINT;
            case TextureFormat::R32_SInt:
                return DXGI_FORMAT_R32_SINT;
            case TextureFormat::R8_G8_UNorm:
                return DXGI_FORMAT_R8G8_UNORM;
            case TextureFormat::R8_G8_UInt:
                return DXGI_FORMAT_R8G8_UINT;
            case TextureFormat::R8_G8_SInt:
                return DXGI_FORMAT_R8G8_SINT;
            case TextureFormat::R16_G16_UNorm:
                return DXGI_FORMAT_R16G16_UNORM;
            case TextureFormat::R16_G16_SNorm:
                return DXGI_FORMAT_R16G16_SNORM;
            case TextureFormat::R16_G16_UInt:
                return DXGI_FORMAT_R16G16_UINT;
            case TextureFormat::R16_G16_SInt:
                return DXGI_FORMAT_R16G16_SINT;
            case TextureFormat::R16_G16_Float:
                return DXGI_FORMAT_R16G16_FLOAT;
            case TextureFormat::R32_G32_UInt:
                return DXGI_FORMAT_R32G32_UINT;
            case TextureFormat::R32_G32_SInt:
                return DXGI_FORMAT_R32G32_SINT;
            case TextureFormat::R32_G32_Float:
                return DXGI_FORMAT_R32G32_FLOAT;
            case TextureFormat::R8_G8_B8_A8_SNorm:
                return DXGI_FORMAT_R8G8B8A8_SNORM;
            case TextureFormat::R8_G8_B8_A8_UInt:
                return DXGI_FORMAT_R8G8B8A8_UINT;
            case TextureFormat::R8_G8_B8_A8_SInt:
                return DXGI_FORMAT_R8G8B8A8_SINT;
            case TextureFormat::R16_G16_B16_A16_UNorm:
                return DXGI_FORMAT_R16G16B16A16_UNORM;
            case TextureFormat::R16_G16_B16_A16_SNorm:
                return DXGI_FORMAT_R16G16B16A16_SNORM;
            case TextureFormat::R16_G16_B16_A16_UInt:
                return DXGI_FORMAT_R16G16B16A16_UINT;
            case TextureFormat::R16_G16_B16_A16_SInt:
                return DXGI_FORMAT_R16G16B16A16_SINT;
            case TextureFormat::R16_G16_B16_A16_Float:
                return DXGI_FORMAT_R16G16B16A16_FLOAT;
            case TextureFormat::R32_G32_B32_A32_SInt:
                return DXGI_FORMAT_R32G32B32A32_SINT;
            case TextureFormat::ETC2_R8_G8_B8_UNorm:
                return DXGI_FORMAT_UNKNOWN;
            case TextureFormat::ETC2_R8_G8_B8_A1_UNorm:
                return DXGI_FORMAT_UNKNOWN;
            case TextureFormat::ETC2_R8_G8_B8_A8_UNorm:
                return DXGI_FORMAT_UNKNOWN;
            case TextureFormat::BC4_UNorm:
                return DXGI_FORMAT_BC4_UNORM;
            case TextureFormat::BC4_SNorm:
                return DXGI_FORMAT_BC4_SNORM;
            case TextureFormat::BC5_UNorm:
                return DXGI_FORMAT_BC5_UNORM;
            case TextureFormat::BC5_SNorm:
                return DXGI_FORMAT_BC5_SNORM;
            case TextureFormat::BC7_UNorm:
                return DXGI_FORMAT_BC7_UNORM;
            case TextureFormat::R8_G8_B8_A8_UNorm_SRgb:
                return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
            case TextureFormat::B8_G8_R8_A8_UNorm_SRgb:
                return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
            case TextureFormat::BC1_Rgb_UNorm_SRgb:
                return DXGI_FORMAT_BC1_UNORM_SRGB;
            case TextureFormat::BC1_Rgba_UNorm_SRgb:
                return DXGI_FORMAT_BC1_UNORM_SRGB;
            case TextureFormat::BC2_UNorm_SRgb:
                return DXGI_FORMAT_BC2_UNORM_SRGB;
            case TextureFormat::BC3_UNorm_SRgb:
                return DXGI_FORMAT_BC3_UNORM_SRGB;
            case TextureFormat::BC7_UNorm_SRgb:
                return DXGI_FORMAT_BC7_UNORM_SRGB;
            default:
                return DXGI_FORMAT_UNKNOWN;
            }
        }
	private:
		D3DTextureUtils() = delete;
		~D3DTextureUtils() = delete;
	};
}
