#ifndef NX_MATCHING_DETAILS_HPP_INCLUDED
#define NX_MATCHING_DETAILS_HPP_INCLUDED

#include <NMatchingDetailsBase.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NXMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NXMatchingDetails) : public N_CLASS(NMatchingDetailsBase)
{
	N_DECLARE_OBJECT_CLASS(NXMatchingDetails, NMatchingDetailsBase)

protected:
	N_CLASS(NXMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NMatchingDetailsBase)(handle, claimHandle)
	{
	}

public:
	NInt GetMatchedIndex() const
	{
		NInt value;
		NCheck(NXMatchingDetailsGetMatchedIndex(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !NX_MATCHING_DETAILS_HPP_INCLUDED
