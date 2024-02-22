#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Math/Vector3.h>

namespace Portakal
{
	class GraphicsInstance;
	struct RUNTIME_API GraphicsAdapterDesc
	{
		String ProductName;
		String VendorName;
		Bool8 bSupportGeometryShader;
		Bool8 bSupportComputeShader;
		UInt8 ColorAttachmentCount;
		UInt32 ShaderTextureCount;
		UInt32 ShaderSamplerCount;
		UInt32 ShaderBufferCount;
		Vector3UI ImageDimensions;
		UInt64 Memory;
		GraphicsInstance* pInstance;
	};
}
