#ifndef N_THREAD_HPP_INCLUDED
#define N_THREAD_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Threading
{
#include <NThread.h>
}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NThread) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NThread, NObject)

public:
	typedef void (* StartProc)(void * pParam);
	typedef void (* ParameterizedStartProc)(N_CLASS(NObject) * pObj, void * pParam);

private:
	static NResult N_API ThreadStartProcImpl(void * pParam)
	{
		NResult result = N_OK;
		try
		{
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<StartProc>(p->pCallback)(p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static NResult N_API ParameterizedThreadStartProcImpl(HNObject hObj, void * pParam)
	{
		NResult result = N_OK;
		try
		{
			::std::auto_ptr<N_CLASS(NObject)> obj(FromHandle<N_CLASS(NObject)>(hObj, false, false));
			N_CLASS(NTypes)::CallbackParam * p = reinterpret_cast<N_CLASS(NTypes)::CallbackParam *>(pParam);
			reinterpret_cast<ParameterizedStartProc>(p->pCallback)(obj.get(), p->pParam);
		}
		N_EXCEPTION_CATCH_AND_SET_LAST(result);
		return result;
	}

	static HNThread Create(StartProc pThreadStart, void * pThreadStartParam)
	{
		N_CLASS(NCallback) threadStart = N_CLASS(NTypes)::CreateCallback(ThreadStartProcImpl, pThreadStart, pThreadStartParam);
		HNThread handle;
		NCheck(NThreadCreateN(threadStart.GetHandle(), &handle));
		return handle;
	}

	static HNThread Create(ParameterizedStartProc pThreadStart, void * pThreadStartParam, N_CLASS(NObject) * pParameter)
	{
		N_CLASS(NCallback) threadStart = N_CLASS(NTypes)::CreateCallback(ParameterizedThreadStartProcImpl, pThreadStart, pThreadStartParam);
		HNThread handle;
		NCheck(NThreadCreateParameterizedN(threadStart.GetHandle(), ToHandle(pParameter), &handle));
		return handle;
	}

	static HNThread Create(NHandle handle, bool ownsHandle)
	{
		HNThread hThread;
		NCheck(NThreadCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hThread));
		return hThread;
	}

	N_CLASS(NThread)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static void Sleep(NInt milliseconds)
	{
		NCheck(NThreadSleep(milliseconds));
	}

	static NSizeType GetCurrentId()
	{
		NSizeType value;
		NCheck(NThreadGetCurrentId(&value));
		return value;
	}

	static N_CLASS(NThread) * GetCurrent()
	{
		return GetObject<N_CLASS(NThread)>(NThreadGetCurrent, true, true);
	}

	N_CLASS(NThread)(StartProc pThreadStart, void * pThreadStartParam)
		: N_CLASS(NObject)(Create(pThreadStart, pThreadStartParam), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NThread);
	}

	N_CLASS(NThread)(ParameterizedStartProc pThreadStart, void * pThreadStartParam, N_CLASS(NObject) * pParameter)
		: N_CLASS(NObject)(Create(pThreadStart, pThreadStartParam, pParameter), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NThread);
	}

	explicit N_CLASS(NThread)(NHandle handle, bool ownsHandle = true)
		: N_CLASS(NObject)(Create(handle, ownsHandle), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NThread);
	}

	void Join()
	{
		NCheck(NThreadJoin(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NThreadGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}

	NSizeType GetId() const
	{
		NSizeType value;
		NCheck(NThreadGetId(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_THREAD_HPP_INCLUDED
