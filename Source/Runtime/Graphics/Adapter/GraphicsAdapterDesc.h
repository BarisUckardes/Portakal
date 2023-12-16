#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GraphicsInstance;
	struct RUNTIME_API GraphicsAdapterDesc
	{
		SharedHeap<GraphicsInstance> pInstance;
		String ProductName;
		String VendorName;
		bool bSupportGeometryShader;
		bool bSupportComputeShader;
		uint8 ColorAttachmentCount;
		uint32 ShaderTextureCount;
		uint32 ShaderSamplerCount;
		uint32 ShaderBufferCount;
		uint64 VRam;
	};
}
