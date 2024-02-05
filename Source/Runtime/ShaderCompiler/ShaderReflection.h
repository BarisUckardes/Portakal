#pragma once
#include <Runtime/ShaderCompiler/ShaderIODescriptor.h>
#include <Runtime/ShaderCompiler/ShaderTableDescriptor.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Object/Object.h>
#include <Runtime/Memory/MemoryView.h>


namespace Portakal
{
	/// <summary>
	/// Reflection data for a single shader
	/// </summary>
	class RUNTIME_API ShaderReflection : public Object
	{
		friend class ShaderCompiler;
	public:
		~ShaderReflection() = default;

		FORCEINLINE const Array<ShaderIODescriptor>& GetInputs() const noexcept
		{
			return mInputs;
		}
		FORCEINLINE const Array<ShaderIODescriptor>& GetOutputs() const noexcept
		{
			return mOutputs;
		}
		FORCEINLINE const Array<ShaderTableDescriptor>& GetTableDescriptors() const noexcept
		{
			return mTableDescriptors;
		}
	private:
		ShaderReflection(const Array<ShaderIODescriptor>& inputs, const Array<ShaderIODescriptor>& outputs,const Array<ShaderTableDescriptor>& tableDescriptors);
	private:
		Array<ShaderIODescriptor> mInputs;
		Array<ShaderIODescriptor> mOutputs;
		Array<ShaderTableDescriptor> mTableDescriptors;
	};
}
