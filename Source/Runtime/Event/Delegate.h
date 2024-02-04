#pragma once
#include <Runtime/Core/Core.h>
#include <functional>

#define GENERATE_DELEGATE(function) std::bind(&function,std::placeholders::_1)
#define GENERATE_DELEGATE_PARAMETERLESS(function) std::bind(&function)
#define GENERATE_MEMBER_DELEGATE0(object,function) std::bind(&function,object)
#define GENERATE_MEMBER_DELEGATE1(object,function,rType,...) Delegate<rType,__VA_ARGS__>(std::bind(&function,object,std::placeholders::_1))
#define GENERATE_MEMBER_DELEGATE2(object,function,rType,...) Delegate<rType,__VA_ARGS__>(std::bind(&function,object,std::placeholders::_1,std::placeholders::_2))
#define GENERATE_MEMBER_DELEGATE3(object,function,rType,...) Delegate<rType,__VA_ARGS__>(std::bind(&function,object,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3))

namespace Portakal
{
	typedef UInt64 FunctionAddress;

	/// <summary>
	/// Represents a simple function pointer wrapper
	/// </summary>
	/// <typeparam name="TReturn"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	template<typename TReturn, typename... TParameters>
	class Delegate final
	{
	public:
		Delegate(const std::function<TReturn(TParameters...)>& function) : mFunction(function), mEmpty(false)
		{

		}
		Delegate() : mEmpty(true)
		{

		}
		~Delegate()
		{

		}

		/// <summary>
		/// Whether this delegate points to an empty function pointer, therefor it should be considered as invalid!
		/// </summary>
		/// <returns></returns>
		FORCEINLINE bool IsEmpty() const noexcept { return mEmpty; }

		/// <summary>
		/// Returns the function ptr
		/// </summary>
		/// <returns></returns>
		FORCEINLINE FunctionAddress GetFunctionAddress() const noexcept
		{
			typedef TReturn(fnType)(TParameters...);
			fnType* pFn = mFunction.target<fnType>();

			return (FunctionAddress)*pFn;
		}

		/// <summary>
		/// Returns the function
		/// </summary>
		/// <returns></returns>
		FORCEINLINE std::function<TReturn(TParameters...)> GetFunction() const noexcept
		{
			return mFunction;
		}

		/// <summary>
		/// Invokes the method
		/// </summary>
		/// <param name="...parameters"></param>
		/// <returns></returns>
		TReturn Invoke(TParameters... parameters)
		{
			return mFunction(parameters...);
		}

	private:
		std::function<TReturn(TParameters...)> mFunction;
		bool mEmpty;
	};

	template<typename TReturn, typename...TParameters>
	static bool operator ==(const Delegate<TReturn, TParameters...>& a, const Delegate<TReturn, TParameters...>& b)
	{
		return a.GetFunctionAddress() == b.GetFunctionAddress();
	}
	template<typename TReturn, typename...TParameters>
	static bool operator !=(const Delegate<TReturn, TParameters...>& a, const Delegate<TReturn, TParameters...>& b)
	{
		return a.GetFunctionAddress() != b.GetFunctionAddress();
	}
}