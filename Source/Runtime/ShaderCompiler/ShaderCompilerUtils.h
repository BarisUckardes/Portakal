#pragma once
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/ShaderCompiler/ShaderTableBindingType.h>
#include <Shaderc/Include/shaderc.h>
#include <spirv_reflect.h>

namespace Portakal
{
	/// <summary>
	/// Utilities for ShaderCompiler
	/// </summary>
	class RUNTIME_API ShaderCompilerUtils
	{
	public:
		FORCEINLINE static shaderc_shader_kind GetShaderKind(const ShaderStage stage)
		{
			switch (stage)
			{
			case ShaderStage::Vertex:
				return shaderc_vertex_shader;
			case ShaderStage::Fragment:
				return shaderc_fragment_shader;
			case ShaderStage::Compute:
				return shaderc_compute_shader;
			default:
				return shaderc_glsl_infer_from_source;
			}
		}

		FORCEINLINE static shaderc_source_language GetLanguage(const ShaderLanguage langauge)
		{
			switch (langauge)
			{
			case ShaderLanguage::GLSL:
				return shaderc_source_language_glsl;
			case ShaderLanguage::HLSL:
				return shaderc_source_language_hlsl;
			case ShaderLanguage::MSL:
				return shaderc_source_language_hlsl;
			default:
				return shaderc_source_language_glsl;
			}
		}

		FORCEINLINE static TextureFormat GetReflectFormat(const SpvReflectFormat format)
		{
			switch (format)
			{
			case SPV_REFLECT_FORMAT_UNDEFINED:
				return TextureFormat::None;
			case SPV_REFLECT_FORMAT_R16_UINT:
				return TextureFormat::R16_UInt;
			case SPV_REFLECT_FORMAT_R16_SINT:
				return TextureFormat::R16_SInt;
			case SPV_REFLECT_FORMAT_R16_SFLOAT:
				return TextureFormat::R16_Float;
			case SPV_REFLECT_FORMAT_R16G16_UINT:
				return TextureFormat::R16_G16_UInt;
			case SPV_REFLECT_FORMAT_R16G16_SINT:
				return TextureFormat::R16_G16_SInt;
			case SPV_REFLECT_FORMAT_R16G16_SFLOAT:
				return TextureFormat::R16_G16_Float;
			case SPV_REFLECT_FORMAT_R16G16B16_UINT:
				return TextureFormat::R16_G16_B16_A16_UInt;
			case SPV_REFLECT_FORMAT_R16G16B16_SINT:
				return TextureFormat::R16_G16_B16_A16_SInt;
			case SPV_REFLECT_FORMAT_R16G16B16_SFLOAT:
				return TextureFormat::R16_G16_B16_A16_Float;
			case SPV_REFLECT_FORMAT_R16G16B16A16_UINT:
				return TextureFormat::R16_G16_B16_A16_UInt;
			case SPV_REFLECT_FORMAT_R16G16B16A16_SINT:
				return TextureFormat::R16_G16_B16_A16_SInt;
			case SPV_REFLECT_FORMAT_R16G16B16A16_SFLOAT:
				return TextureFormat::R16_G16_B16_A16_Float;
			case SPV_REFLECT_FORMAT_R32_UINT:
				return TextureFormat::R32_UInt;
			case SPV_REFLECT_FORMAT_R32_SINT:
				return TextureFormat::R32_SInt;
			case SPV_REFLECT_FORMAT_R32_SFLOAT:
				return TextureFormat::R32_Float;
			case SPV_REFLECT_FORMAT_R32G32_UINT:
				return TextureFormat::R32_G32_UInt;
			case SPV_REFLECT_FORMAT_R32G32_SINT:
				return TextureFormat::R32_G32_SInt;
			case SPV_REFLECT_FORMAT_R32G32_SFLOAT:
				return TextureFormat::R32_G32_Float;
			case SPV_REFLECT_FORMAT_R32G32B32_UINT:
				return TextureFormat::R32_G32_B32_UInt;
			case SPV_REFLECT_FORMAT_R32G32B32_SINT:
				return TextureFormat::R32_G32_B32_SInt;
			case SPV_REFLECT_FORMAT_R32G32B32_SFLOAT:
				return TextureFormat::R32_G32_B32_Float;
			case SPV_REFLECT_FORMAT_R32G32B32A32_UINT:
				return TextureFormat::R32_G32_B32_A32_UInt;
			case SPV_REFLECT_FORMAT_R32G32B32A32_SINT:
				return TextureFormat::R32_G32_B32_A32_SInt;
			case SPV_REFLECT_FORMAT_R32G32B32A32_SFLOAT:
				return TextureFormat::R32_G32_B32_A32_Float;
			case SPV_REFLECT_FORMAT_R64_UINT:
				return TextureFormat::R64_UInt ;
			case SPV_REFLECT_FORMAT_R64_SINT:
				return TextureFormat::R64_SInt;
			case SPV_REFLECT_FORMAT_R64_SFLOAT:
				return TextureFormat::R64_Float;
			case SPV_REFLECT_FORMAT_R64G64_UINT:
				return TextureFormat::R64_G64_UInt;
			case SPV_REFLECT_FORMAT_R64G64_SINT:
				return TextureFormat::R64_G64_SInt;
			case SPV_REFLECT_FORMAT_R64G64_SFLOAT:
				return TextureFormat::R64_G64_Float;
			case SPV_REFLECT_FORMAT_R64G64B64_UINT:
				return TextureFormat::R64_G64_B64_UInt;
			case SPV_REFLECT_FORMAT_R64G64B64_SINT:
				return TextureFormat::R64_G64_B64_SInt;
			case SPV_REFLECT_FORMAT_R64G64B64_SFLOAT:
				return TextureFormat::R64_G64_B64_Float;
			case SPV_REFLECT_FORMAT_R64G64B64A64_UINT:
				return TextureFormat::R64_G64_B64_A64_UInt;
			case SPV_REFLECT_FORMAT_R64G64B64A64_SINT:
				return TextureFormat::R64_G64_B64_A64_SInt;
			case SPV_REFLECT_FORMAT_R64G64B64A64_SFLOAT:
				return TextureFormat::R64_G64_B64_A64_Float;
			default:
				break;
			}
		}

		FORCEINLINE static ShaderTableBindingType GetBindingType(const SpvReflectDescriptorType type)
		{
			switch (type)
			{
			case SPV_REFLECT_DESCRIPTOR_TYPE_SAMPLER:
				return ShaderTableBindingType::Sampler;;
			case SPV_REFLECT_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
			case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_IMAGE:
				return ShaderTableBindingType::Texture;
			case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
			case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER:
			case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
			case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
				return ShaderTableBindingType::ConstantBuffer;
			default:
				return ShaderTableBindingType::None;
			}
		}
	public:
		ShaderCompilerUtils() = delete;
		~ShaderCompilerUtils() = delete;
	};
}
