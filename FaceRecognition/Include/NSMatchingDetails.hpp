#ifndef NS_MATCHING_DETAILS_HPP_INCLUDED
#define NS_MATCHING_DETAILS_HPP_INCLUDED

#include <NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NSMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetails);

class N_CLASS(NSMatchingDetails) : public N_CLASS(NXMatchingDetails)
{
	N_DECLARE_OBJECT_CLASS(NSMatchingDetails, NXMatchingDetails)

private:
	N_CLASS(NSMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NXMatchingDetails)(handle, claimHandle)
	{
	}
};

}}

#include <NMatchingDetails.hpp>

#endif // !NS_MATCHING_DETAILS_HPP_INCLUDED
