#include <NWaitObject.hpp>

#ifndef N_MUTEX_HPP_INCLUDED
#define N_MUTEX_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <NMutex.h>
}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NMutex) : public N_CLASS(NWaitObject)
{
	N_DECLARE_OBJECT_CLASS(NMutex, NWaitObject)

private:
	static HNMutex Create(bool initiallyOwned)
	{
		HNMutex handle;
		NCheck(NMutexCreate(initiallyOwned ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNMutex Create(NHandle handle, bool ownsHandle)
	{
		HNMutex hMutex;
		NCheck(NMutexCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hMutex));
		return hMutex;
	}

	N_CLASS(NMutex)(HNObject handle, bool claimHandle)
		: N_CLASS(NWaitObject)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NMutex)(bool initiallyOwned)
		: N_CLASS(NWaitObject)(Create(initiallyOwned), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMutex);
	}

	explicit N_CLASS(NMutex)(NHandle handle, bool ownsHandle = true)
		: N_CLASS(NWaitObject)(Create(handle, ownsHandle), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMutex);
	}

	void Release()
	{
		NCheck(NMutexRelease(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NMutexGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_MUTEX_HPP_INCLUDED
