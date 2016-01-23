#ifndef NE_MATCHER_HPP_INCLUDED
#define NE_MATCHER_HPP_INCLUDED

#include <NemMatchDetails.hpp>
#include <NEMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NEMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NEMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NEMatcher, NObject)

private:
	static HNEMatcher Create()
	{
		HNEMatcher handle;
		NCheck(NemCreate(&handle));
		return handle;
	}

	N_CLASS(NEMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NemSpeedNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NemSpeed), true, true);
	}

	N_CLASS(NEMatcher)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NEMatcher);
	}

	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NemMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NInt score;
		NCheck(NemVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NemMatchDetails * * ppMatchDetails = NULL)
	{
		NInt score;
		NCheck(NemVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NemMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NemIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NemMatchDetails * * ppMatchDetails = NULL)
	{
		NCheck(NemIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}

	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NemMatchDetails * pMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NemIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, NemMatchDetails * pMatchDetails = NULL)
	{
		NInt score;
		NCheck(NemIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NemIdentifyEnd(GetHandle()));
	}

	NInt GetMatchingThreshold()
	{
		return GetParameter<NInt>(NEMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NInt value)
	{
		SetParameter(NEMP_MATCHING_THRESHOLD, value);
	}

	NemSpeed GetMatchingSpeed()
	{
		return (NemSpeed)GetParameter<NInt>(NEMP_MATCHING_SPEED);
	}

	void SetMatchingSpeed(NemSpeed value)
	{
		SetParameter(NEMP_MATCHING_SPEED, (NInt)value);
	}

	NByte GetMaximalRotation()
	{
		return GetParameter<NByte>(NEMP_MAXIMAL_ROTATION);
	}

	void SetMaximalRotation(NByte value)
	{
		SetParameter(NEMP_MAXIMAL_ROTATION, value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NE_MATCHER_HPP_INCLUDED
