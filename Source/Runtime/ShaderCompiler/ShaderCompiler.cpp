#include "ShaderCompiler.h"
#include <Runtime/Containers/Array.h>
#include <Shaderc/Include/shaderc.hpp>
#include <Runtime/ShaderCompiler/ShaderIOSemantic.h>
#include <Runtime/ShaderCompiler/ShaderVariableFormat.h>
#include <Runtime/ShaderCompiler/ShaderTableBindingType.h>
#include <Spirv-Cross/Include/spirv_hlsl.hpp>
#include <Spirv-Cross/Include/spirv_glsl.hpp>
#include <Runtime/ShaderCompiler/ShaderBlockMember.h>
#include <Windows.h>
#include <spirv_reflect.h>

namespace Portakal
{
	Bool8 ShaderCompiler::CompileToSPIRV(const String& sourceAsString, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut, String& errorMessageOut)
	{
		DEV_ASSERT(language != ShaderLanguage::Unknown, "ShaderCompiler", "Invalid shader language");

		shaderc::Compiler vkCompiler;
		shaderc::CompileOptions compileOptions;

		//Set options
		compileOptions.SetSourceLanguage(ShaderCompilerUtils::GetLanguage(language));
		compileOptions.SetSuppressWarnings();

		//Pre process
		const shaderc::PreprocessedSourceCompilationResult preprocessResult = vkCompiler.PreprocessGlsl(*sourceAsString, ShaderCompilerUtils::GetShaderKind(stage), *entryMethodName, compileOptions);
		const String rm = preprocessResult.GetErrorMessage().c_str();
		if (preprocessResult.GetCompilationStatus() != shaderc_compilation_status_success || preprocessResult.GetNumErrors() > 0)
		{
			errorMessageOut = preprocessResult.GetErrorMessage().c_str();
			*ppViewOut = nullptr;
			return false;
		}

		const shaderc::SpvCompilationResult result = vkCompiler.CompileGlslToSpv(sourceAsString.GetSource(), ShaderCompilerUtils::GetShaderKind(stage), "", compileOptions);

		if (result.GetCompilationStatus() != shaderc_compilation_status_success)
		{
			errorMessageOut = result.GetErrorMessage().c_str();
			DEV_LOG("SPIRVCompiler", "Compiling failed!");
			*ppViewOut = nullptr;
			return false;
		}

		const UInt64 bufferSize = (Byte*)result.cend() - (Byte*)result.cbegin();
		Byte* pBuffer = new Byte[bufferSize];
		Memory::Copy(pBuffer, result.cbegin(), bufferSize);

		*ppViewOut = new MemoryOwnedView(pBuffer,bufferSize);

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}

	Bool8 ShaderCompiler::CompileToSPIRV(const MemoryView& view, const String& entryMethodName, const ShaderStage stage, const ShaderLanguage language, MemoryOwnedView** ppViewOut, String& errorMessageOut)
	{
		DEV_ASSERT(language != ShaderLanguage::Unknown, "ShaderCompiler", "Invalid shader language");

		shaderc::Compiler compiler;
		shaderc::CompileOptions compileOptions;

		//Set options
		compileOptions.SetSourceLanguage(ShaderCompilerUtils::GetLanguage(language));
		compileOptions.SetSuppressWarnings();

		//Pre process
		const shaderc::PreprocessedSourceCompilationResult preprocessResult = compiler.PreprocessGlsl((const char*)view.GetMemory(), ShaderCompilerUtils::GetShaderKind(stage), *entryMethodName, compileOptions);
		if (preprocessResult.GetCompilationStatus() != shaderc_compilation_status_success)
		{
			errorMessageOut = preprocessResult.GetErrorMessage().c_str();
			*ppViewOut = nullptr;
			return false;
		}
		shaderc::SpvCompilationResult result = compiler.CompileGlslToSpv((const Char*)view.GetMemory(), ShaderCompilerUtils::GetShaderKind(stage), "", compileOptions);

		if (result.GetCompilationStatus() != shaderc_compilation_status_success)
		{
			DEV_LOG("ShaderCompiler", "Compiling failed!");
			errorMessageOut = result.GetErrorMessage().c_str();
			*ppViewOut = nullptr;
			return false;
		}

		*ppViewOut = new MemoryOwnedView((Byte*)result.cbegin(), (Byte*)result.cend());

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}

	Bool8 ShaderCompiler::CompileFromSPIRV(const MemoryView& pView, GraphicsBackend chosenApi, MemoryOwnedView** ppBytes)
	{
		*ppBytes = nullptr;

		spirv_cross::Compiler* pCompiler = nullptr;
		switch (chosenApi)
		{
		case GraphicsBackend::Vulkan:
		{
			Byte* pBuffer = new Byte[pView.GetSize()];
			Memory::Copy(pBuffer, pView.GetMemory(), pView.GetSize());
			*ppBytes = new MemoryOwnedView(pBuffer, pView.GetSize());
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

	/*Bool8 ShaderCompiler::CompileFromSPIRV(const MemoryView& pView, const ShaderLanguage language, MemoryOwnedView** ppViewOut)
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

		*ppViewOut = new MemoryOwnedView((Byte*)compiledSource.GetSource(), compiledSource.GetSize());

		if (*ppViewOut == nullptr)
		{
			DEV_LOG("ShaderCompiler", "Failed to allocate memory for SPIRV.");
			return false;
		}

		return true;
	}*/
	ShaderBlockMember GetMemberData(const SpvReflectBlockVariable* pVariable)
	{
		ShaderBlockMember member = {};
		member.Name = pVariable->name;
		member.Size = pVariable->size;
		member.PaddedSize = pVariable->padded_size;
		member.Offset = pVariable->offset;
		member.AbsoluteOffset = pVariable->absolute_offset;
		
		for (UInt32 i = 0; i < pVariable->member_count; i++)
		{
			ShaderBlockMember subMember = GetMemberData(&pVariable->members[i]);
			member.Members.Add(subMember);
		}

		return member;
	}
	SharedHeap<ShaderReflection> ShaderCompiler::GenerateReflectionFromSPIRV(const MemoryView& memory)
	{
		//Generate reflection data
		SpvReflectShaderModule module;
		const SpvReflectResult generateResult = spvReflectCreateShaderModule(memory.GetSize(), memory.GetMemory(), &module);
		if (generateResult != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		//Enumerate shader input variables
		Array<ShaderIODescriptor> inputs;
		UInt32 inputVariableCount = 0;
		const SpvReflectResult inputEnumarateResult = spvReflectEnumerateInputVariables(&module,&inputVariableCount,NULL);
		if (inputEnumarateResult != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		SpvReflectInterfaceVariable** ppInputVariables = new SpvReflectInterfaceVariable*[inputVariableCount];
		const SpvReflectResult inputEnumarateResult2 = spvReflectEnumerateInputVariables(&module, &inputVariableCount, ppInputVariables);
		if (inputEnumarateResult2 != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		for (UInt32 i = 0;i<inputVariableCount;i++)
		{
			const SpvReflectInterfaceVariable* pInput = ppInputVariables[i];
			ShaderIODescriptor io = {};
			io.Name = pInput->name;
			io.Format = ShaderCompilerUtils::GetReflectFormat(pInput->format);
			inputs.Add(io);
		}

		//Enumerate shader output variables
		UInt32 outputVariableCount = 0;
		const SpvReflectResult outputEnumerateResult = spvReflectEnumerateOutputVariables(&module, &outputVariableCount, nullptr);
		if (outputEnumerateResult != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		SpvReflectInterfaceVariable** ppOutputVariables = new SpvReflectInterfaceVariable*[outputVariableCount];
		const SpvReflectResult outputEnumerateResult2 = spvReflectEnumerateOutputVariables(&module, &outputVariableCount, ppOutputVariables);
		if (outputEnumerateResult2 != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		Array<ShaderIODescriptor> outputs;
		for (UInt32 i = 0; i < outputVariableCount; i++)
		{
			const SpvReflectInterfaceVariable* pOutput = ppOutputVariables[i];
			ShaderIODescriptor io = {};
			io.Name = pOutput->name;
			io.Format = ShaderCompilerUtils::GetReflectFormat(pOutput->format);
			outputs.Add(io);
		}

		//Enumerate descriptors
		UInt32 descriptorSetCount = 0;
		const SpvReflectResult descriptorSetResult = spvReflectEnumerateDescriptorSets(&module, &descriptorSetCount, nullptr);
		if (descriptorSetResult != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		SpvReflectDescriptorSet** ppDescriptorSets = new SpvReflectDescriptorSet*[descriptorSetCount];
		const SpvReflectResult descriptorSetResult2 = spvReflectEnumerateDescriptorSets(&module, &descriptorSetCount, ppDescriptorSets);
		if (descriptorSetResult2 != SPV_REFLECT_RESULT_SUCCESS)
			return nullptr;

		Array<ShaderTableDescriptor> tableDescriptors;
		for (UInt32 setIndex = 0; setIndex < descriptorSetCount; setIndex++)
		{
			const SpvReflectDescriptorSet* pDescriptorSet = ppDescriptorSets[setIndex];

			ShaderTableDescriptor tableDescriptor = {};
			tableDescriptor.TableIndex = pDescriptorSet->set;

			for (UInt32 bindingIndex = 0; bindingIndex < pDescriptorSet->binding_count; bindingIndex++)
			{
				const SpvReflectDescriptorBinding* pBinding = pDescriptorSet->bindings[bindingIndex];
				
				ShaderTableBinding binding = {};
				binding.BindingIndex = pBinding->binding;
				binding.Name = pBinding->name;
				binding.Type = ShaderCompilerUtils::GetBindingType(pBinding->descriptor_type);

				//Collect members
				binding.BlockMember = GetMemberData(&pBinding->block);
				tableDescriptor.Bindings.Add(binding);
			}

			tableDescriptors.Add(tableDescriptor);
		}

		//Free reflect module
		spvReflectDestroyShaderModule(&module);

		//Create reflection object
		ShaderReflection* pReflection = new ShaderReflection(inputs,outputs,tableDescriptors);

		return pReflection;
	}
}
