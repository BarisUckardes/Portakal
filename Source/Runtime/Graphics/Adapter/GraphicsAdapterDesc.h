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
		Uint8 ColorAttachmentCount;
		Uint32 ShaderTextureCount;
		Uint32 ShaderSamplerCount;
		Uint32 ShaderBufferCount;
		Vector3UI ImageDimensions;
		Uint64 VRam;
		GraphicsInstance* pInstance;
	};
}
