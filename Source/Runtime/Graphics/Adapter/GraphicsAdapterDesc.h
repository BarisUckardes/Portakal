#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GraphicsInstance;
	struct RUNTIME_API GraphicsAdapterDesc
	{
		String ProductName;
		String VendorName;
		Bool8 bSupportGeometryShader;
		Bool8 bSupportComputeShader;
		Byte ColorAttachmentCount;
		UInt32 ShaderTextureCount;
		UInt32 ShaderSamplerCount;
		UInt32 ShaderBufferCount;
		UInt32 ImageWidth;
		UInt32 ImageHeight;
		UInt32 ImageDepth;
		UInt64 Memory;
		GraphicsInstance* pInstance;
	};
}
