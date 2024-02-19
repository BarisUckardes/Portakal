#pragma once

namespace Portakal
{
	struct RUNTIME_API ViewportDesc
	{
		UInt32 Width;
		UInt32 Height;
		UInt32 X;
		UInt32 Y;
		Float32 DepthMin;
		Float32 DepthMax;
	};
}
