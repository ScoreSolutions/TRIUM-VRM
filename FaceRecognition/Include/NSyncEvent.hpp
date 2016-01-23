#include <NWaitObject.hpp>

#ifndef N_SYNC_EVENT_HPP_INCLUDED
#define N_SYNC_EVENT_HPP_INCLUDED

namespace Neurotec { namespace Threading
{
#include <NSyncEvent.h>
}}

namespace Neurotec { namespace Threading
{

class N_CLASS(NSyncEvent) : public N_CLASS(NWaitObject)
{
	N_DECLARE_OBJECT_CLASS(NSyncEvent, NWaitObject)

private:
	static HNSyncEvent Create(bool manualReset, bool initialState)
	{
		HNSyncEvent handle;
		NCheck(NSyncEventCreate(manualReset ? NTrue : NFalse, initialState ? NTrue : NFalse, &handle));
		return handle;
	}

	static HNSyncEvent Create(NHandle handle, bool ownsHandle)
	{
		HNSyncEvent hSyncEvent;
		NCheck(NSyncEventCreateFromOSHandle(handle, ownsHandle ? NTrue : NFalse, &hSyncEvent));
		return hSyncEvent;
	}

	N_CLASS(NSyncEvent)(HNObject handle, bool claimHandle)
		: N_CLASS(NWaitObject)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NSyncEvent)(bool manualReset, bool initialState)
		: N_CLASS(NWaitObject)(Create(manualReset, initialState), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSyncEvent);
	}

	explicit N_CLASS(NSyncEvent)(NHandle handle, bool ownsHandle = true)
		: N_CLASS(NWaitObject)(Create(handle, ownsHandle), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSyncEvent);
	}

	void Set()
	{
		NCheck(NSyncEventSet(GetHandle()));
	}

	NHandle GetOSHandle() const
	{
		NHandle hValue;
		NCheck(NSyncEventGetOSHandle(GetHandle(), &hValue));
		return hValue;
	}
};

}}

#endif // !N_SYNC_EVENT_HPP_INCLUDED
