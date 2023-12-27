#include "RenderGraph.h"

namespace Portakal
{
    void RenderGraph::RegisterTexture(const String& name, const SharedHeap<TextureResource>& pTexture)
    {
        //Check if already exists
        if (mTextures.Find(name) != nullptr)
            return;

        //Register
        mTextures.Insert(name, pTexture);
    }
    void RenderGraph::RemoveTexture(const String& name)
    {
        mTextures.Remove(name);
    }
    void RenderGraph::RegisterOperation(RenderOperation* pOperation)
    {
        if (mOperations.Has(pOperation))
            return;

        mOperations.Add(pOperation);
    }
    void RenderGraph::RemoveRenderOperation(RenderOperation* pOperation)
    {
        mOperations.Remove(pOperation);
        if (mBeginOperation == pOperation)
        {
            mBeginOperation = nullptr;
            return;
        }
        if (mEndOperation == pOperation)
        {
            mEndOperation = nullptr;
            return;
        }
    }
    void RenderGraph::SetBeginOperation(RenderOperation* pOperation)
    {
        if (!mOperations.Has(pOperation))
        {
            DEV_LOG("RenderGraph", "Given operation is not a member of this render graph!");
            return;
        }

        mBeginOperation = pOperation;
    }
    void RenderGraph::SetEndOperation(RenderOperation* pOperation)
    {
        if (!mOperations.Has(pOperation))
        {
            DEV_LOG("RenderGraph", "Given operation is not a member of this render graph!");
            return;
        }

        mEndOperation = pOperation;
    }
    void RenderGraph::Build()
    {
        //Build the graph
    }
    void RenderGraph::Execute()
    {
        //Move through render path and execute operations
        for (const Array<RenderOperation*>& operations : mRenderPath)
        {
            //Execute right away if it's just one
            for (RenderOperation* pOperation : operations)
                pOperation->Execute();

            //Execute in parallel
        }
    }
    void RenderGraph::OnShutdown()
    {

    }
}
