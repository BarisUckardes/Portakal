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
		bool bSupportGeometryShader;
		bool bSupportComputeShader;
		uint8 ColorAttachmentCount;
		uint32 ShaderTextureCount;
		uint32 ShaderSamplerCount;
		uint32 ShaderBufferCount;
		Vector3UI ImageDimensions;
		uint64 VRam;
	};
}
