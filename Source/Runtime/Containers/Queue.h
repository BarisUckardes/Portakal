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
	class RUNTIME_API QueueDoubleNode
	{
	public:
		QueueDoubleNode() : mBackNode(nullptr), mFrontNode(nullptr), mSize(0)
		{

		}
		QueueDoubleNode(T* data) : mBackNode(nullptr), mFrontNode(nullptr), mSize(0)
		{
			Push(data);
		}
		QueueDoubleNode(const Queue& other) = delete;
		QueueDoubleNode& operator=(const QueueDoubleNode& other) = delete;

		~QueueDoubleNode()
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

	/**
 * @class Queue
 *
 * @brief It is a FIFO based container.
 */
	template<typename T>
	class RUNTIME_API QueueSingleNode
	{
	public:
		QueueSingleNode() : mRootNode(nullptr), mSize(0)
		{

		}
		QueueSingleNode(T* data) : mRootNode(nullptr), mSize(0)
		{
			Push(data);
		}
		QueueSingleNode(const QueueSingleNode& other) = delete;
		QueueSingleNode& operator=(const QueueSingleNode& other) = delete;

		~QueueSingleNode()
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
			// Check if queue is empty.
			if (mRootNode == nullptr)
			{
				mRootNode = new Node();
				mRootNode->mData = data;
				mRootNode->mNext = nullptr;
			}
			else
			{
				// Create a new node and add it to the beginning.
				Node* newNode = new Node();
				newNode->mData = data;
				newNode->mNext = mRootNode;
				mRootNode = newNode;
			}

			mSize++;
		}

		/**
		 * @brief Removes an element from the beginning of the queue.
		 *
		 */
		void Pop()
		{
			// Check if queue is empty.
			if (mRootNode == nullptr)
			{
				DEV_LOG("Queue", "There is nothing to pop!");
				return;
			}

			// Check if queue has only one element.
			if (mRootNode->mNext == nullptr)
			{
				delete mRootNode;
				mRootNode = nullptr;

				mSize--;
				return;
			}

			// Check if queue has more than one element.
			if (mRootNode->mNext != nullptr)
			{
				// Find the next node;
				Node* currentNode = mRootNode->mNext;
				// Delete the RootNode, so the next node will be the new root node.
				delete mRootNode;
				// Set the new root node.
				mRootNode = currentNode;

				mSize--;
			}
		}

		void Clear()
		{
			while (!IsEmpty())
			{
				Pop();
			}
		}

		UInt32 Size() const { return mSize; }
		bool IsEmpty() const { return mSize == 0; }

	public:
		struct Node
		{
			T* mData;
			Node* mNext;
		};
	private:
		Node* mRootNode;
		UInt32 mSize;
	};
}
