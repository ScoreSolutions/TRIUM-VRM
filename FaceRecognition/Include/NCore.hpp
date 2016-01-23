#include <NObject.hpp>

#ifndef N_CORE_HPP_INCLUDED
#define N_CORE_HPP_INCLUDED

#include <NTypes.hpp>
#include <NError.hpp>
#include <NMemory.hpp>
#include <NObject.hpp>
#include <NModule.hpp>
#include <NLibraryInfo.hpp>
#include <NTimeSpan.hpp>
#include <NDateTime.hpp>
#include <NStringBuilder.hpp>
namespace Neurotec
{
#include <NCore.h>
}

namespace Neurotec
{

#include <NNoDeprecate.h>
class N_CLASS(NCore)
{
private:
	static NResult N_API ErrorSuppressedCallbackImpl(NResult error, HNError hError, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			::std::auto_ptr<N_CLASS(NException)> exception(N_CLASS(NException)::Get(error, hError));
			reinterpret_cast<ErrorSuppressedCallback>(p->pCallback)(exception.get(), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	N_CLASS(NCore)();
	N_CLASS(NCore) & operator=(const N_CLASS(NCore) &);

public:
	typedef void (* ErrorSuppressedCallback)(N_CLASS(NException) * pError, void * pParam);

	N_DEPRECATED("method is deprecated, use N_NATIVE_MODULE_OF(NCore) instead")
	static void GetInfo(NLibraryInfo * pValue)
	{
		NCheck(NCoreGetInfo(pValue));
	}

	static void OnStart()
	{
		NCheck(NCoreOnStart());
	}

	static void OnThreadStart()
	{
		NCheck(NCoreOnThreadStart());
	}

	static void OnThreadExit()
	{
		NCheck(NCoreOnThreadExit());
	}

	static void OnExit(bool isProcessTermination)
	{
		NCheck(NCoreOnExitEx(isProcessTermination ? NTrue : NFalse));
	}

	static void AddErrorSuppressedCallback(ErrorSuppressedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(ErrorSuppressedCallbackImpl, pCallback, pParam);
		NCheck(NCoreAddErrorSuppressed(callback.GetHandle()));
	}

	static void RemoveErrorSuppressedCallback(ErrorSuppressedCallback pCallback, void * pParam)
	{
		N_CLASS(NCallback) callback = N_CLASS(NTypes)::CreateCallback(ErrorSuppressedCallbackImpl, pCallback, pParam);
		NCheck(NCoreRemoveErrorSuppressed(callback.GetHandle()));
	}

	N_DECLARE_MODULE_CLASS(NCore)
};
#include <NReDeprecate.h>

} // namespace Neurotec

#include <NCollections.hpp>
#include <NProcessorInfo.hpp>

#endif // !N_CORE_HPP_INCLUDED
