#include "IComponentPainter.h"

namespace Portakal
{
	void IComponentPainter::_SetComponent(const SharedHeap<Component>& pComponent)
	{
		mTargetComponent = pComponent;
	}
}