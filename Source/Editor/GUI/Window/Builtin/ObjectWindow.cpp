#include "ObjectWindow.h"
#include <Editor/GUI/Object/EditorObjectAPI.h>
#include <imgui.h>

namespace Portakal
{
    void ObjectWindow::Lock()
    {
        mLocked = true;
    }
    void ObjectWindow::Unlock()
    {
        mLocked = false;
    }
    void ObjectWindow::_Signal(Type* pPainterType, const SharedHeap<Object>& pObject)
    {
        if (mLocked)
            return;

        //Delete former painter
        if (mPainter != nullptr)
        {
            mPainter->Shutdown();
            delete mPainter;
        }

        //Create new painter
        mPainter = (IObjectPainter*)pPainterType->CreateDefaultHeapObject();
        mPainter->_SetTargetObject(pObject);
        mPainter->OnInitialize();
    }
    void ObjectWindow::OnShutdown()
    {
        EditorObjectAPI::_RemoveWindow(this);
    }
    void ObjectWindow::OnShow()
    {

    }
    void ObjectWindow::OnHide()
    {
    }
    void ObjectWindow::OnPaint()
    {
        if (mPainter == nullptr)
            ImGui::Text("No painter implementation available!");

        if (mPainter != nullptr)
        {
            mPainter->OnPaint();
        }
        else
            ImGui::Text("No object to inspect");
    }
    void ObjectWindow::OnInitialize()
    {
        EditorObjectAPI::_RegisterWindow(this);
    }
}
