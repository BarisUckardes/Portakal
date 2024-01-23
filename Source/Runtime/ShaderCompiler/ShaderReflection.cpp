#include "ShaderReflection.h"

namespace Portakal
{
    ShaderReflection::ShaderReflection(const Array<ShaderIODescriptor>& inputs, const Array<ShaderIODescriptor>& outputs, const Array<ShaderTableDescriptor>& tableDescriptors) : mInputs(inputs),mOutputs(outputs),mTableDescriptors(tableDescriptors)
    {

    }
}
