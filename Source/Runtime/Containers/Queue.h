#pragma once

#include <Runtime/Core/Core.h>

namespace Portakal
{
	/**
	 * @class Queue
	 *
	 * @brief It is a FIFO based container.
	 */
	template<typename T>
	class RUNTIME_API Queue
	{
	public:
		Queue() : mBackNode(nullptr), mFrontNode(nullptr), mSize(0)
		{

		}
		Queue(T* data) : mBackNode(nullptr), mFrontNode(nullptr), mSize(0)
		{
			Push(data);
		}
		Queue(const Queue& other) = delete;
		Queue& operator=(const Queue& other) = delete;

		~Queue()
		{
			while (!IsEmpty())
			{
				Pop();
			}
		}

		/**
		 * @brief Adds an element to the end of the queue.
		 */
		void Push(T* data)
		{
			// Create a new node and set its data.
			Node* newNode = new Node();
			newNode->mData = data;
			newNode->mNext = nullptr;

			// If queue is empty, set front and back nodes to new node.
			if (mBackNode == nullptr)
			{
				mBackNode = newNode;
				mFrontNode = newNode;
			}
			else
			{
				mBackNode->mNext = newNode;
				mBackNode = newNode;
			}

			mSize++;
		}

		/**
		 * @brief Removes an element from the beginning of the queue.
		 *
		 */
		void Pop()
		{
			// If queue is empty, return.
			if (mFrontNode == nullptr)
			{
				return;
			}

			// Create a temp node and delete the front node.
			Node* temp = mFrontNode;
			mFrontNode = mFrontNode->mNext;
			delete temp;

			mSize--;
		}

		T* FrontData() const { return mFrontNode->mData; }
		Node* FrontNode() const { return mFrontNode; }
		Node* BackNode() const { return mBackNode; }
		T* BackData() const { return mBackNode->mData; }

		UInt32 Size() const { return mSize; }
		bool IsEmpty() const { return mSize == 0; }

	public:
		struct Node
		{
			T* mData;
			Node* mNext;
		};
	private:
		Node* mBackNode;
		Node* mFrontNode;
		UInt32 mSize;
	};
}
