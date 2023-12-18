#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/Graphics/Shader/ShaderCompilerUtils.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>

namespace Portakal
{
	class RUNTIME_API ShaderCompiler
	{
	public:
		// Compile functions may need GraphicsApi param to determine hlsl to spirv conversions properly.
		static bool CompileToSPIRV(const String& sourceAsString, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
		static bool CompileToSPIRV(const MemoryOwnedView* pView, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
		static bool CompileFromSPIRV(const MemoryView& pView, GraphicsBackend backend, MemoryOwnedView** ppBytes);
		static bool CompileFromSPIRV(const MemoryView& pView, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
	private:
		ShaderCompiler() = delete;
		~ShaderCompiler() = delete;
	};
}
