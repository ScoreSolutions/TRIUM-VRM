#ifndef NE_MATCHING_DETAILS_HPP_INCLUDED
#define NE_MATCHING_DETAILS_HPP_INCLUDED

#include <NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NEMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetails);

class N_CLASS(NEMatchingDetails) : public N_CLASS(NXMatchingDetails)
{
	N_DECLARE_OBJECT_CLASS(NEMatchingDetails, NXMatchingDetails)

private:
	N_CLASS(NEMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NXMatchingDetails)(handle, claimHandle)
	{
	}
};

}}

#include <NMatchingDetails.hpp>

#endif // !NE_MATCHING_DETAILS_HPP_INCLUDED
