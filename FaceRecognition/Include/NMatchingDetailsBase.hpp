#ifndef N_MATCHING_DETAILS_BASE_HPP_INCLUDED
#define N_MATCHING_DETAILS_BASE_HPP_INCLUDED

#include <NCore.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NMatchingDetailsBase.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetailsBase) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NMatchingDetailsBase, NObject)

protected:
	N_CLASS(NMatchingDetailsBase)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	NBiometricType GetBiometricType() const
	{
		NBiometricType value;
		NCheck(NMatchingDetailsBaseGetBiometricType(GetHandle(), &value));
		return value;
	}

	NInt GetScore() const
	{
		NInt value;
		NCheck(NMatchingDetailsBaseGetScore(GetHandle(), &value));
		return value;
	}
};

}}

#endif // !N_MATCHING_DETAILS_BASE_HPP_INCLUDED
