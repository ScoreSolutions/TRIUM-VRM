#ifndef NL_MATCHER_HPP_INCLUDED
#define NL_MATCHER_HPP_INCLUDED

#include <NLMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NLMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NLMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NLMatcher, NObject)

private:
	static HNLMatcher Create()
	{
		HNLMatcher handle;
		NCheck(NlmCreate(&handle));
		return handle;
	}

	N_CLASS(NLMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NlmSpeedNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NlmSpeed), true, true);
	}

	N_CLASS(NLMatcher)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLMatcher);
	}

	NDouble Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NDouble score;
		NCheck(NlmVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), &score));
		return score;
	}

	NDouble Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size)
	{
		NDouble score;
		NCheck(NlmVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NlmIdentifyStartN(GetHandle(), pTemplate->GetHandle()));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize)
	{
		NCheck(NlmIdentifyStart(GetHandle(), pTemplate, templateSize));
	}

	NDouble IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NDouble score;
		NCheck(NlmIdentifyNextN(GetHandle(), pTemplate->GetHandle(), &score));
		return score;
	}

	NDouble IdentifyNext(const void * pTemplate, NSizeType templateSize)
	{
		NDouble score;
		NCheck(NlmIdentifyNext(GetHandle(), pTemplate, templateSize, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NlmIdentifyEnd(GetHandle()));
	}

	NDouble GetMatchingThreshold()
	{
		return GetParameter<NDouble>(NLMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NDouble value)
	{
		SetParameter(NLMP_MATCHING_THRESHOLD, value);
	}

	NlmSpeed GetMatchingSpeed()
	{
		return (NlmSpeed)GetParameter<NInt>(NLMP_MATCHING_SPEED);
	}

	void SetMatchingSpeed(NlmSpeed value)
	{
		SetParameter(NLMP_MATCHING_SPEED, (NInt)value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NL_MATCHER_HPP_INCLUDED
