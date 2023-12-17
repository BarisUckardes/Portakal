#include "Swapchain.h"

namespace Portakal
{
    Swapchain::Swapchain(const SwapchainDesc& desc) : mColorFormat(desc.ColorFormat),mDepthStencilFormat(desc.DepthStencilFormat),mBufferCount(desc.BufferCount),mWindow(desc.pWindow),mSize(desc.pWindow->GetSize())
    {
        //Create fence
        mFence = desc.pDevice->CreateFence();
    }
}
