#include "GUIViewport.h"

namespace Portakal
{
	GUIViewport::GUIViewport() : mID(0),
		mFlags(GUIViewportFlags::None),
		mPosition({ 0,0 }),
		mSize({0,0}),
		mWorkPosition({ 0,0 }),
		mWorkSize({ 0,0 }),
		mDPIScale(0.0f),
		mParentViewportID(0)
	{
	}
}
