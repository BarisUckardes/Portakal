#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    template<typename T>
    class LinkedList
    {
    public:
        struct Node
        {
            Node() : Next(nullptr),Data()
            {

            }
            T Data;
            Node* Next;
        };

    public:
        LinkedList() : mRoot(nullptr)
        {

        }
        ~LinkedList()
        {
            Clear();
        }

        FORCEINLINE Node* GetRoot() const noexcept
        {
            return mRoot;
        }

        void Add(const T& value)
        {
            // Root empty case
            if (mRoot == nullptr)
            {
                mRoot = new Node();
                mRoot->Data = value;
                return;
            }

           
            // Default case
            Node* pNode = mRoot;
            while (pNode != nullptr)
            {
                if (pNode->Next == nullptr)
                    break;

                pNode = pNode->Next;
            }

            Node* pNewNode = new Node();
            pNewNode->Data = value;
            pNode->Next = pNewNode;
        }
        void Insert(const T& value, const uint32 index)
        {
            uint32 counter = 0;
            Node* pFormerNode = nullptr;
            Node* pNode = mRoot;

            // Special case for item count 0
            if (pNode == nullptr)
            {
                Node* pNewNode = new Node();
                pNewNode->Data = value;
                pNewNode->Next = nullptr;
                mRoot = pNewNode;
                return;
            }

            // Iterate and find insert location
            while (pNode != nullptr)
            {
                // Check for index match
                if (index == counter)
                {
                    // Create new node
                    Node* pNewNode = new Node();
                    pNewNode->Data = value;
                    pNewNode->Next = pNode;

                    if (pFormerNode == nullptr)
                    {
                        mRoot = pNewNode;
                    }
                    else
                    {
                        pFormerNode->Next = pNewNode;
                    }

                    break;
                }

                pFormerNode = pNode;
                pNode = pNode->Next;
                counter++;
            }
        }
        void RemoveAt(const uint32 index)
        {
            uint32 counter = 0;
            Node* pNode = mRoot;
            Node* pOldNode = nullptr;
            while (pNode != nullptr)
            {
                if (counter == index)
                {
                    pOldNode->Next = pNode->Next;
                    delete pNode;
                    break;
                }
                pOldNode = pNode;
                pNode = pNode->Next;
                counter++;
            }
        }
        void Remove(const T& value)
        {
            Node* pNode = mRoot;
            Node* pOldNode = nullptr;
            while (pNode != nullptr)
            {
                if (pNode->Data == value)
                {
                    pOldNode->Next = pNode->Next;
                    delete pNode;
                    break;
                }
                pOldNode = pNode;
                pNode = pNode->Next;
            }
        }

        void Clear()
        {
            Node* pNode = mRoot;
            while (pNode != nullptr)
            {
                Node* pTemp = pNode->Next;
                delete pNode;
                pNode = pTemp;
            }
        }
    private:
        Node* mRoot;
    };

}
