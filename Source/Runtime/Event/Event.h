#pragma once
#include <Runtime/Event/Delegate.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	/// <summary>
	/// Simple wrapper for delegate event utility
	/// </summary>
	/// <typeparam name="TReturn"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	template<typename TReturn, typename... TParameters>
	class Event final
	{
	public:
		/// <summary>
		/// Invoke the event
		/// </summary>
		/// <param name="...parameters"></param>
		void Invoke(TParameters... parameters)
		{
			for (UInt32 delegateIndex = 0; delegateIndex < mDelegates.GetSize(); delegateIndex++)
				mDelegates[delegateIndex].Invoke(parameters...);
		}

		/// <summary>
		/// Returns the event invocation list
		/// </summary>
		/// <returns></returns>
		FORCEINLINE const Array<Delegate<TReturn, TParameters...>>& GetInvocationList() const noexcept
		{
			return mDelegates;
		}

		/// <summary>
		/// Clears all the registered events
		/// </summary>
		void ClearInvocationList()
		{
			mDelegates.Clear();
		}

		void operator +=(const Delegate<TReturn, TParameters...>& target)
		{
			mDelegates.Add(target);
		}
		void operator -=(const Delegate<TReturn, TParameters...>& target)
		{
			mDelegates.Remove(target);
		}
	private:
		Array<Delegate<TReturn, TParameters...>> mDelegates;
	};
}