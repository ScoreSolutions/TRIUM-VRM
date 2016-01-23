#include <NWaitObject.hpp>

#ifndef N_SEMAPHORE_HPP_INCLUDED
#define N_SEMAPHORE_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <NSemaphore.h>
}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NSemaphore) : public N_CLASS(NWaitObject)
{
	N_DECLARE_OBJECT_CLASS(NSemaphore, NWaitObject)

private:
	static HNSemaphore Create(NInt initialCount)
	{
		HNSemaphore handle;
		NCheck(NSemaphoreCreate(initialCount, &handle));
		return handle;
	}

	static HNSemaphore Create(NHandle handle, bool ownsHandle)
	{
		HNSemaphore hSemaphore;
		NCheck(NSemaphoreCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hSemaphore));
		return hSemaphore;
	}

	N_CLASS(NSemaphore)(HNObject handle, bool claimHandle)
		: N_CLASS(NWaitObject)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NSemaphore)(NInt initialCount)
		: N_CLASS(NWaitObject)(Create(initialCount), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSemaphore);
	}

	explicit N_CLASS(NSemaphore)(NHandle handle, bool ownsHandle = true)
		: N_CLASS(NWaitObject)(Create(handle, ownsHandle), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSemaphore);
	}

	void Release()
	{
		NCheck(NSemaphoreRelease(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NSemaphoreGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_SEMAPHORE_HPP_INCLUDED
