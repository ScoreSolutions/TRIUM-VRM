#ifndef NF_MATCHING_DETAILS_HPP_INCLUDED
#define NF_MATCHING_DETAILS_HPP_INCLUDED

#include <NXMatchingDetails.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NFMatchingDetails.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatchingDetails);

class N_CLASS(NFMatchingDetails) : public N_CLASS(NXMatchingDetails)
{
	N_DECLARE_OBJECT_CLASS(NFMatchingDetails, NXMatchingDetails)

private:
	N_CLASS(NFMatchingDetails)(HNObject handle, bool claimHandle)
		: N_CLASS(NXMatchingDetails)(handle, claimHandle)
	{
	}

public:
	NInt GetCenterX() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetCenterX(GetHandle(), &value));
		return value;
	}

	NInt GetCenterY() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetCenterY(GetHandle(), &value));
		return value;
	}

	NByte GetRotation() const
	{
		NByte value;
		NCheck(NFMatchingDetailsGetRotation(GetHandle(), &value));
		return value;
	}

	NInt GetTranslationX() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetTranslationX(GetHandle(), &value));
		return value;
	}

	NInt GetTranslationY() const
	{
		NInt value;
		NCheck(NFMatchingDetailsGetTranslationY(GetHandle(), &value));
		return value;
	}

	NInt GetMatedMinutiae(N_CLASS(NIndexPair) * arValue, NInt valueLength = N_INT_MAX) const
	{
		return NCheck(NFMatchingDetailsGetMatedMinutiae(GetHandle(), arValue, valueLength));
	}

	N_CLASS(NIndexPair) * GetMatedMinutiae(NInt * pCount) const
	{
		if (!pCount) NThrowArgumentNullException(N_T("pCount"));
		NInt count = GetMatedMinutiae(NULL, 0);
		auto_array<N_CLASS(NIndexPair)> values(count);
		*pCount = GetMatedMinutiae(values.get(), count);
		return values.release();
	}
};

}}

#include <NMatchingDetails.hpp>

#endif // !NF_MATCHING_DETAILS_HPP_INCLUDED
