#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
	/**
	 * @class SharedHeap
	 * @brief Dynamic shared pointer system that stores 
	 * the templated pType as Object base class.
	 * @relates Object
	 */
	template<typename T>
	class RUNTIME_API SharedHeap
	{
	public:
		SharedHeap(const SharedHeap& pOther) : mData(nullptr),mReferenceCount(nullptr)
		{
			/*
			* Check if pOther data is nullptr
			*/
			if (pOther.mData == nullptr)
			{
				mData = nullptr;
				mReferenceCount = nullptr;
				return;
			}

			/*
			* Inherit fields
			*/
			mData = pOther.mData;
			mReferenceCount = pOther.mReferenceCount;

			/*
			* Increment the reference counter
			*/
		}
		SharedHeap(T* pObject) : mData(nullptr), mReferenceCount(nullptr)
		{
			/*
			* Get data field
			*/
			mData = (Object*)pObject;

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
			Shutdown();
		}

		FORCEINLINE bool IsShutdown() const noexcept
		{
			return (mData == nullptr || mData->IsShutdown());
		}
		FORCEINLINE T* GetHeap() const noexcept { return (T*)mData; }
		FORCEINLINE T** GetHeapAddress() const noexcept { return (T**)&mData; }

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
			TOther* pChecksum = dynamic_cas<TOther*>(mData);
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

			return pOther;
		}

		T* operator->() const noexcept
		{
			return (T*)mData;
		}

		void operator =(const SharedHeap& pOther)
		{
			/*
			* Check if pOther is nullptr
			*/
			if (pOther.mData == nullptr)
			{
				mData = nullptr;
				mReferenceCount = nullptr;
				return;
			}

			/*
			* Inherit data
			*/
			mData = pOther.mData;
			mReferenceCount = pOther.mReferenceCount;

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
			* Check if pOther is nullptr
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

		bool operator ==(const SharedHeap& pOther) { return mData == pOther.mData; }
		bool operator !=(const SharedHeap& pOther) { return mData != pOther.mData; }
		bool operator==(const T* pData) { return mData == (T*)pData; }
		bool operator!=(const T* pData) { return mData != (T*)pData; }

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
		Object* mData;
		uint32* mReferenceCount;
	};
}
