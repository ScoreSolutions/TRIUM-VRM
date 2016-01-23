#ifndef NLS_MATCHER_HPP_INCLUDED
#define NLS_MATCHER_HPP_INCLUDED

#include <NLMatcher.hpp>
#include <NlsmMatchDetails.hpp>
#include <NlsMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NlsMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NlsMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NlsMatcher, NObject)

private:
	static HNlsMatcher Create()
	{
		HNlsMatcher handle;
		NCheck(NlsmCreate(&handle));
		return handle;
	}

	N_CLASS(NlsMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NlsMatcher)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NlsMatcher);
	}

	NDouble Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NlsmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NDouble score;
		NCheck(NlsmVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	NDouble Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NlsmMatchDetails * * ppMatchDetails = NULL)
	{
		NDouble score;
		NCheck(NlsmVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NlsmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NlsmIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NlsmMatchDetails * * ppMatchDetails = NULL)
	{
		NCheck(NlsmIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}

	NDouble IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NlsmMatchDetails * pMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NDouble score;
		NCheck(NlsmIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	NDouble IdentifyNext(const void * pTemplate, NSizeType templateSize, NlsmMatchDetails * pMatchDetails)
	{
		NDouble score;
		NCheck(NlsmIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NlsmIdentifyEnd(GetHandle()));
	}

	NDouble GetMatchingThreshold()
	{
		return GetParameter<NDouble>(NLSM_PART_NONE, NLSMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NDouble value)
	{
		SetParameter(NLSM_PART_NONE, NLSMP_MATCHING_THRESHOLD, value);
	}

	NlmSpeed GetMatchingSpeed()
	{
		return (NlmSpeed)GetParameter<NInt>(NLSM_PART_NLM, NLMP_MATCHING_SPEED);
	}

	void SetMatchingSpeed(NlmSpeed value)
	{
		SetParameter(NLSM_PART_NLM, NLMP_MATCHING_SPEED, (NInt)value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NLS_MATCHER_HPP_INCLUDED
