#ifndef NES_MATCHER_HPP_INCLUDED
#define NES_MATCHER_HPP_INCLUDED

#include <NEMatcher.hpp>
#include <NesmMatchDetails.hpp>
#include <NesMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NesMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NesMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NesMatcher, NObject)

private:
	static HNesMatcher Create()
	{
		HNesMatcher handle;
		NCheck(NesmCreate(&handle));
		return handle;
	}

	N_CLASS(NesMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NesMatcher)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NesMatcher);
	}

	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NesmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NInt score;
		NCheck(NesmVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NesmMatchDetails * * ppMatchDetails = NULL)
	{
		NInt score;
		NCheck(NesmVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NesmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NesmIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NesmMatchDetails * * ppMatchDetails = NULL)
	{
		NCheck(NesmIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}

	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NesmMatchDetails * pMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NesmIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, NesmMatchDetails * pMatchDetails)
	{
		NInt score;
		NCheck(NesmIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NesmIdentifyEnd(GetHandle()));
	}

	NInt GetMatchingThreshold()
	{
		return GetParameter<NInt>(NESM_PART_NONE, NESMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NInt value)
	{
		SetParameter(NESM_PART_NONE, NESMP_MATCHING_THRESHOLD, value);
	}

	NemSpeed GetMatchingSpeed()
	{
		return (NemSpeed)GetParameter<NInt>(NESM_PART_NEM, NEMP_MATCHING_SPEED);
	}

	void SetMatchingSpeed(NemSpeed value)
	{
		SetParameter(NESM_PART_NEM, NEMP_MATCHING_SPEED, value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NES_MATCHER_HPP_INCLUDED
