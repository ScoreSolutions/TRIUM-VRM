#ifndef NL_MATCHING_DETAILS_HPP_INCLUDED
#define NL_MATCHING_DETAILS_HPP_INCLUDED

#include <NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetails);

class N_CLASS(NLMatchingDetails) : public N_CLASS(NXMatchingDetails)
{
	N_DECLARE_OBJECT_CLASS(NLMatchingDetails, NXMatchingDetails)

private:
	N_CLASS(NLMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NXMatchingDetails)(handle, claimHandle)
	{
	}
};

}}

#include <NMatchingDetails.hpp>

#endif // !NL_MATCHING_DETAILS_HPP_INCLUDED
