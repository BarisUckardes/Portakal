#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API TextureFormat : Byte
    {
        None,
        /**
         * @brief RGBA component order. Each component is an 8-bit normalized UInt32eger.
         */
        R8_G8_B8_A8_UNorm,
        /**
         * @brief BGRA component order. Each component is an 8-bit normalized UInt32eger.
         */
        B8_G8_R8_A8_UNorm,
        /**
         * @brief Single-channel, 8-bit normalized UInt32eger.
         */
        R8_UNorm,
        /**
         * @brief Single-channel, 16-bit normalized UInt32eger. Can be used as a depth format.
         */
        R16_UNorm,
        /**
         *  @brief RGBA component order. Each component is a 32-bit signed Float32ing-point value.
         */
        R32_G32_B32_A32_Float32,
        /**
         * @brief Single-channel, 32-bit signed Float32ing-point value. Can be used as a depth format.
         */
        R32_Float32,
        /**
         * @brief BC3 block compressed format.
         */
        BC3_UNorm,
        /**
         * @brief A depth-stencil format where the depth is stored in a 24-bit normalized UInt32eger,
         * and the stencil is stored in an 8-bit UInt32eger.
         */
        D24_UNorm_S8_UInt,
        D32_SFloat32,
        /**
         * @brief A depth-stencil format where the depth is stored in a 32-bit signed Float32ing-point value,
         * and the stencil is stored in an 8-bit UInt32eger.
         */
        D32_Float32_S8_UInt,
        /**
         * @brief RGBA component order. Each component is a 32-bit UInt32eger.
         */
        R32_G32_B32_A32_UInt,
        R32_G32_B32_Float32,
        R32_G32_B32_UInt,
        R32_G32_B32_SInt,
        R16G16B16_UInt,
        R16G16B16_SInt,
        R16G16B16_Float32,
        R64_UInt,
        R64_SInt,
        R64_Float32,
        R64_G64_UInt,
        R64_G64_SInt,
        R64_G64_Float32,
        R64_G64_B64_UInt,
        R64_G64_B64_SInt,
        R64_G64_B64_Float32,
        R64_G64_B64_A64_UInt,
        R64_G64_B64_A64_SInt,
        R64_G64_B64_A64_Float32,
        /**
         * @brief RG component order. Each component is an 8-bit normalized integer.
         */
        R8_G8_SNorm,
        /**
         * @brief BC1 block compressed format with no alpha.
         */
        BC1_Rgb_UNorm,
        /**
         * @brief BC1 block compressed format with a single-bit alpha channel.
         */
        BC1_Rgba_UNorm,
        /**
         * @brief BC2 block compressed format.
         */
        BC2_UNorm,
        /**
         * @brief A 32-bit packed format. The 10-bit R component occupies bits 0..9, the 10-bit
         * G component occupies bits 10..19, the 10-bit A component occupies 20..29, and the
         * 2-bit A component occupies bits 30..31. Each value is an unsigned, normalized integer.
         */
        R10_G10_B10_A2_UNorm,
        /**
         * @brief A 32-bit packed format. The 10-bit R component occupies bits 0..9, the 10-bit
         * G component occupies bits 10..19, the 10-bit A component occupies 20..29, and the
         * 2-bit A component occupies bits 30..31. Each value is an UInt32eger.
         */
        R10_G10_B10_A2_UInt,
        /**
         * @brief A 32-bit packed format. The 11-bit R component occupies bits 0..10, the 11-bit
         * G component occupies bits 11..21, and the 10-bit B component occupies bits 22..31.
         * Each value is an unsigned Float32ing point value.
         */
        R11_G11_B10_Float32,
        /**
         * @brief Single-channel, 8-bit signed normalized integer.
         */
        R8_SNorm,
        /**
         * @brief Single-channel, 8-bit UInt32eger.
         */
        R8_UInt,
        /**
         * @brief Single-channel, 8-bit signed integer.
         */
        R8_SInt,
        /**
         * @brief Single-channel, 16-bit signed normalized integer.
         */
        R16_SNorm,
        /**
         * @brief Single-channel, 16-bit UInt32eger.
         */
        R16_UInt,
        /**
         * @brief Single-channel, 16-bit signed integer.
         */
        R16_SInt,
        /**
         * @brief Single-channel, 16-bit signed Float32ing-point value.
         */
        R16_Float32,
        /**
         * @brief Single-channel, 32-bit UInt32eger
         */
        R32_UInt,
        /**
         * @brief Single-channel, 32-bit signed integer.
         */
        R32_SInt,
        /**
         * @brief RG component order. Each component is an 8-bit normalized UInt32eger.
         */
        R8_G8_UNorm,
        /**
         * @brief RG component order. Each component is an 8-bit UInt32eger.
         */
        R8_G8_UInt,
        /**
         * @brief RG component order. Each component is an 8-bit signed integer.
         */
        R8_G8_SInt,
        /**
         * @brief RG component order. Each component is a 16-bit normalized UInt32eger.
         */
        R16_G16_UNorm,
        /**
         * @brief RG component order. Each component is a 16-bit normalized integer.
         */
        R16_G16_SNorm,
        /**
         * @brief RG component order. Each component is a 16-bit UInt32eger.
         */
        R16_G16_UInt,
        /**
         * @brief RG component order. Each component is a 16-bit signed integer.
         */
        R16_G16_SInt,
        /**
         * @brief RG component order. Each component is a 16-bit signed Float32ing-point value.
         */
        R16_G16_Float32,
        /**
         * @brief RG component order. Each component is a 32-bit UInt32eger.
         */
        R32_G32_UInt,
        /**
         * @brief RG component order. Each component is a 32-bit signed integer.
         */
        R32_G32_SInt,
        /**
         * @brief RG component order. Each component is a 32-bit signed Float32ing-point value.
         */
        R32_G32_Float32,
        /**
         * @brief RGBA component order. Each component is an 8-bit normalized integer.
         */
        R8_G8_B8_A8_SNorm,
        /**
         * @brief RGBA component order. Each component is an 8-bit UInt32eger.
         */
        R8_G8_B8_A8_UInt,
        /**
         * @brief RGBA component order. Each component is an 8-bit signed integer.
         */
        R8_G8_B8_A8_SInt,
        /**
         * @brief RGBA component order. Each component is a 16-bit normalized UInt32eger.
         */
        R16_G16_B16_A16_UNorm,
        /**
         * @brief RGBA component order. Each component is a 16-bit normalized integer.
         */
        R16_G16_B16_A16_SNorm,
        /**
         * @brief RGBA component order. Each component is a 16-bit UInt32eger.
         */
        R16_G16_B16_A16_UInt,
        /**
         * @brief RGBA component order. Each component is a 16-bit signed integer.
         */
        R16_G16_B16_A16_SInt,
        /**
         * @brief RGBA component order. Each component is a 16-bit Float32ing-point value.
         */
        R16_G16_B16_A16_Float32,
        /**
         * @brief RGBA component order. Each component is a 32-bit signed integer.
         */
        R32_G32_B32_A32_SInt,
        /**
         * @brief A 64-bit, 4x4 block-compressed format storing unsigned normalized RGB data.
         */
        ETC2_R8_G8_B8_UNorm,
        /**
         * @brief A 64-bit, 4x4 block-compressed format storing unsigned normalized RGB
         * data, as well as 1 bit of alpha data.
         */
        ETC2_R8_G8_B8_A1_UNorm,
        /**
         * @brief A 128-bit, 4x4 block-compressed format storing 64 bits of unsigned normalized
         * RGB data, as well as 64 bits of alpha data.
         */
        ETC2_R8_G8_B8_A8_UNorm,
        /**
         * @brief BC4 block compressed format, unsigned normalized values.
         */
        BC4_UNorm,
        /**
         * @brief BC4 block compressed format, signed normalized values.
         */
        BC4_SNorm,
        /**
         * @brief BC5 block compressed format, unsigned normalized values.
         */
        BC5_UNorm,
        /**
         * @brief BC5 block compressed format, signed normalized values.
         */
        BC5_SNorm,
        /**
         * @brief BC7 block compressed format.
         */
        BC7_UNorm,
        /**
         * @brief RGBA component order. Each component is an 8-bit normalized
         * UInt32eger. This is an sRGB format.
         */
        R8_G8_B8_A8_UNorm_SRgb,
        /**
         * @brief BGRA component order. Each component is an 8-bit normalized
         * UInt32eger. This is an sRGB format.
         */
        B8_G8_R8_A8_UNorm_SRgb,
        /**
         * @brief BC1 block compressed format with no alpha. This is an sRGB format.
         */
        BC1_Rgb_UNorm_SRgb,
        /**
         * @brief BC1 block compressed format with a single-bit alpha channel.
         * This is an sRGB format.
         */
        BC1_Rgba_UNorm_SRgb,
        /**
         * @brief BC2 block compressed format. This is an sRGB format.
         */
        BC2_UNorm_SRgb,
        /**
         * @brief BC3 block compressed format. This is an sRGB format.
         */
        BC3_UNorm_SRgb,
        /**
         * @brief BC7 block compressed format. This is an sRGB format.
         */
        BC7_UNorm_SRgb
    };

}