#include "IObjectPainter.h"

namespace Portakal
{
	void IObjectPainter::_SetTargetObject(const SharedHeap<Object>& pObject)
	{
		mTargetObject = pObject;
	}
}
