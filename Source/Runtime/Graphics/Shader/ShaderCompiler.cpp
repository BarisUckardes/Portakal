#include "ShaderCompiler.h"
#include <Runtime/Containers/Array.h>
#include <Shaderc/Include/shaderc.hpp>
#include <Spirv-Cross/Include/spirv_hlsl.hpp>
#include <Spirv-Cross/Include/spirv_glsl.hpp>
#include <Windows.h>
#include <Dxc/Include/dxcapi.h>
#include <wrl.h>

using namespace Microsoft::WRL;

namespace Portakal
{
	bool ShaderCompiler::CompileToSPIRV(const String& sourceAsString, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut)
	{
		DEV_ASSERT(language != ShaderLanguage::Unknown, "ShaderCompiler", "Invalid shader language");

		shaderc::Compiler vkCompiler;
		shaderc::CompileOptions compileOptions;

		compileOptions.SetSourceLanguage(ShaderCompilerUtils::GetLanguage(language));

		shaderc::SpvCompilationResult module = vkCompiler.CompileGlslToSpv(sourceAsString.GetSource(), ShaderCompilerUtils::GetShaderKind(stage), "", compileOptions);

		if (module.GetCompilationStatus() != shaderc_compilation_status_success)
		{
			DEV_LOG("SPIRVCompiler", "Compiling failed!");
			*ppViewOut = nullptr;
			return false;
		}

		*ppViewOut = new MemoryOwnedView((byte*)module.cbegin(), (byte*)module.cend());

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}

	bool ShaderCompiler::CompileToSPIRV(const MemoryOwnedView* pView, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut)
	{
		DEV_ASSERT(language != ShaderLanguage::Unknown, "ShaderCompiler", "Invalid shader language");

		shaderc::Compiler compiler;
		shaderc::CompileOptions compileOptions;

		compileOptions.SetSourceLanguage(ShaderCompilerUtils::GetLanguage(language));

		shaderc::SpvCompilationResult module = compiler.CompileGlslToSpv((const char*)pView->GetMemory(), ShaderCompilerUtils::GetShaderKind(stage), "", compileOptions);

		if (module.GetCompilationStatus() != shaderc_compilation_status_success)
		{
			DEV_LOG("ShaderCompiler", "Compiling failed!");
			*ppViewOut = nullptr;
			return false;
		}

		*ppViewOut = new MemoryOwnedView((byte*)module.cbegin(), (byte*)module.cend());

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}

	bool ShaderCompiler::CompileFromSPIRV(const MemoryView& pView, GraphicsBackend backend, MemoryOwnedView** ppBytes)
	{
		*ppBytes = nullptr;

		spirv_cross::Compiler* pCompiler = nullptr;
		switch (backend)
		{
		case GraphicsBackend::Vulkan:
		{
			*ppBytes = new MemoryOwnedView((byte*)pView.GetMemory(), pView.GetSize());
			return true;
		}
		case GraphicsBackend::DirectX12:
		{
			pCompiler = new spirv_cross::CompilerHLSL((const uint32_t*)pView.GetMemory(), pView.GetSize());

			spirv_cross::CompilerHLSL::Options options = {};
			((spirv_cross::CompilerHLSL*)pCompiler)->set_hlsl_options(options);
			break;
		}
		}

		if (*ppBytes == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}

	bool ShaderCompiler::CompileFromSPIRV(const MemoryView& pView, const ShaderLanguage language, MemoryOwnedView** ppViewOut)
	{
		*ppViewOut = nullptr;

		spirv_cross::Compiler* pCompiler = nullptr;

		switch (language)
		{
		case ShaderLanguage::HLSL:
		{
			pCompiler = new spirv_cross::CompilerHLSL((const uint32_t*)pView.GetMemory(), pView.GetSize());

			spirv_cross::CompilerHLSL::Options options = {};
			((spirv_cross::CompilerHLSL*)pCompiler)->set_hlsl_options(options);

			break;
		}
		case ShaderLanguage::GLSL:
		{
			pCompiler = new spirv_cross::CompilerGLSL((const uint32_t*)pView.GetMemory(), pView.GetSize());

			spirv_cross::CompilerGLSL::Options options = {};
			((spirv_cross::CompilerGLSL*)pCompiler)->set_common_options(options);

			break;
		}
		default:
		{
			DEV_LOG("ShaderCompiler", "Invalid shader language comes eventhough it passes the DEV_ASSERT.");
			return false;
		}
		}

		String compiledSource = pCompiler->compile().c_str();

		*ppViewOut = new MemoryOwnedView((byte*)compiledSource.GetSource(), compiledSource.GetSize());

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}
}
