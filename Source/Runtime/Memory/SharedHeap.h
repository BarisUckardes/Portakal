#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	template<typename T>
	class SharedHeap
	{
	public:
		SharedHeap(const SharedHeap& other) : mData(nullptr),mReferenceCount(nullptr)
		{
			/*
			* Check if other data is nullptr
			*/
			if (other.mData == nullptr)
			{
				mData = nullptr;
				mReferenceCount = nullptr;
				return;
			}

			/*
			* Inherit fields
			*/
			mData = other.mData;
			mReferenceCount = other.mReferenceCount;

			/*
			* Increment the reference counter
			*/
		}
		SharedHeap(T* pObject) : mData(nullptr), mReferenceCount(nullptr)
		{
			/*
			* Get data field
			*/
			mData = pObject;

			/*
			* Check and do not create 
			*/
			if (pObject != nullptr)
				mReferenceCount = new uint32(1);
			else
				mReferenceCount = nullptr;
		}
		SharedHeap() : mData(nullptr), mReferenceCount(nullptr)
		{

		}
		~SharedHeap()
		{

		}

		FORCEINLINE bool IsShutdown() const noexcept
		{
			return (mData == nullptr || mData->IsShutdown());
		}
		FORCEINLINE T* GetHeap() const noexcept { return mData; }
		FORCEINLINE T** GetHeapAddress() const noexcept { return &mData; }

		void Deference()
		{
			/*
			* Check if valid
			*/
			if (mReferenceCount == nullptr)
				return;

			/*
			* Decrement
			*/
			*mReferenceCount = *mReferenceCount - 1;
			
			/*
			* Delete if reference count is 0
			*/
			if (*mReferenceCount == 0)
				DeleteReference();

			/*
			* Set to defaults
			*/
			mData = nullptr;
			mReferenceCount = nullptr;
		}

		void Shutdown()
		{
			/*
			* Shutdown the underlying object if only the reference is valid
			*/
			if (!IsShutdown())
				mData->Shutdown();
		}

		template<typename TOther>
		SharedHeap<TOther> QueryAs() noexcept
		{
			/*
			* Force compiler
			*/
			TOther* pChecksum = dynamic_cas<TOTher*>(mData);
			if (pChecksum == nullptr)
				return nullptr;

			/*
			* Increment
			*/
			IncrementReferenceCount();

			/*
			* Inherit data
			*/
			SharedHeap<TOther> pOther = nullptr;
			SharedHeap<T>* pTemp = (SharedHeap<T>*) & pOther;

			pTemp->mData = mData;
			pTemp->mReferenceCount = mReferenceCount;

			return other;
		}

		T* operator->() const noexcept
		{
			return mData;
		}

		void operator =(const SharedHeap& other)
		{
			/*
			* Check if other is nullptr
			*/
			if (other.mData == nullptr)
			{
				mData = nullptr;
				mReferenceCount = nullptr;
				return;
			}

			/*
			* Inherit data
			*/
			mData = other.mData;
			mReferenceCount = other.mReferenceCount;

			/*
			* Increment
			*/
			IncrementReferenceCount();
		}

		template<typename TOther>
		void operator=(TOther* pData) = delete;

		void operator=(T* pData)
		{
			/*
			* First deference 
			*/
			Deference();

			/*
			* Check if other is nullptr
			*/
			if (pData == nullptr)
			{
				mData = nullptr;
				mReferenceCount = nullptr;
				return;
			}

			/*
			* Inherit
			*/
			mData = pData;
			mReferenceCount = new uint32(1);
		}
		bool operator ==(const SharedHeap& other)
		{
			return mData == other.mData;

		}
		bool operator !=(const SharedHeap& other)
		{
			return mData != other.mData;
		}
		bool operator==(const T* pData)
		{
			return mData == (Object*)pData;
		}
		bool operator!=(const T* pData)
		{
			return mData != (Object*)pData;
		}
	private:
		void IncrementReferenceCount()
		{
			if (mReferenceCount != nullptr)
				*mReferenceCount = *mReferenceCount + 1;
		}
		void DeleteReference()
		{
			/*
			* Validate data
			*/
			if (mData == nullptr)
				return;

			/*
			* Shutdown
			*/
			Shutdown();

			/*
			* Delete heap
			*/
			delete mData;
			delete mReferenceCount;
		}
	private:
		T* mData;
		uint32* mReferenceCount;
	};
}
