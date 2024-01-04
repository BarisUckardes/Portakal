#pragma once
#include <Runtime/Math/Vector2.h>

namespace Portakal
{
	/**
	 * @class ViewportDesc
	 * 
	 * @brief It helps the gpu to do the transformation from normalized 
	 * device coordinates to window coordinates. As basic explanation, it tells 
	 * the gpu how to draw a 3d environment on a 2d screen.
	 * We can think this descriptor as a logic in our brain that tries to express 
	 * a 3d world on a piece of paper.
	 *
	 */
	struct RUNTIME_API ViewportDesc
	{
		Vector2US SizeInPixels;
		Vector2US OffsetInPixels;
		Vector2F DepthRange;
	};
}
