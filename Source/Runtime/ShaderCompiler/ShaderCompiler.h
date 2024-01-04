#pragma once

#include <Runtime/Containers/String.h>
#include <Runtime/Memory/MemoryOwnedView.h>
#include <Runtime/Memory/MemoryView.h>
#include <Runtime/ShaderCompiler/ShaderCompilerUtils.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>

namespace Portakal
{
	class RUNTIME_API ShaderCompiler
	{
	public:
		// Compile functions may need GraphicsApi param to determine hlsl to spirv conversions properly.
		static Bool8 CompileToSPIRV(const String& sourceAsString, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
		static Bool8 CompileToSPIRV(const MemoryOwnedView* pView, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
		static Bool8 CompileFromSPIRV(const MemoryView& pView, GraphicsBackend chosenApi, MemoryOwnedView** ppBytes);
		static Bool8 CompileFromSPIRV(const MemoryView& pView, const ShaderLanguage language, MemoryOwnedView** ppViewOut);
	private:
		ShaderCompiler() = delete;
		~ShaderCompiler() = delete;
	};
}
