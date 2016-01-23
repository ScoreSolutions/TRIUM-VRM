#ifndef N_WAIT_OBJECT_HPP_INCLUDED
#define N_WAIT_OBJECT_HPP_INCLUDED

#include <NCore.hpp>
namespace Neurotec { namespace Threading
{
#include <NWaitObject.h>
}}

namespace Neurotec { namespace Threading
{
#undef N_INFINITE

const NInt N_INFINITE = -1;

class N_CLASS(NWaitObject) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NWaitObject, NObject)

protected:
	N_CLASS(NWaitObject)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	bool WaitFor(NInt timeOutMilliseconds = N_INFINITE)
	{
		NBool result;
		NCheck(NWaitObjectWaitForTimed(GetHandle(), timeOutMilliseconds, &result));
		return result != 0;
	}
};

}}

#endif // !N_WAIT_OBJECT_HPP_INCLUDED
