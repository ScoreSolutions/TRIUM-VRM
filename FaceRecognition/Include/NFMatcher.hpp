#ifndef NF_MATCHER_HPP_INCLUDED
#define NF_MATCHER_HPP_INCLUDED

#include <NfmMatchDetails.hpp>
#include <NFMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NFMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NFMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NFMatcher, NObject)

private:
	static HNFMatcher Create(bool isPalm)
	{
		HNFMatcher handle;
		NCheck(NfmCreateEx(isPalm, &handle));
		return handle;
	}

	N_CLASS(NFMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NfmSpeedNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NfmSpeed), true, true);
	}

	explicit N_CLASS(NFMatcher)(bool isPalm = false)
		: N_CLASS(NObject)(Create(isPalm), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFMatcher);
	}

	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NfmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NInt score;
		NCheck(NfmVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NfmMatchDetails * * ppMatchDetails = NULL)
	{
		NInt score;
		NCheck(NfmVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NfmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NfmIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NfmMatchDetails * * ppMatchDetails = NULL)
	{
		NCheck(NfmIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}

	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NfmMatchDetails * pMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NfmIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, NfmMatchDetails * pMatchDetails = NULL)
	{
		NInt score;
		NCheck(NfmIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NfmIdentifyEnd(GetHandle()));
	}

	NBool IsPalm()
	{
		NBool value;
		NCheck(NfmIsPalm(GetHandle(), &value));
		return value;
	}

	NInt GetMatchingThreshold()
	{
		return GetParameter<NInt>(NFMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NInt value)
	{
		SetParameter(NFMP_MATCHING_THRESHOLD, value);
	}

	NByte GetMaximalRotation()
	{
		return GetParameter<NByte>(NFMP_MAXIMAL_ROTATION);
	}

	void SetMaximalRotation(NByte value)
	{
		SetParameter(NFMP_MAXIMAL_ROTATION, value);
	}

	NfmSpeed GetMatchingSpeed()
	{
		return (NfmSpeed)GetParameter<NInt>(NFMP_MATCHING_SPEED);
	}

	void SetMatchingSpeed(NfmSpeed value)
	{
		SetParameter(NFMP_MATCHING_SPEED, value);
	}

	NUInt GetMode()
	{
		return GetParameter<NUInt>(NFMP_MODE);
	}

	void SetMode(NUInt value)
	{
		SetParameter(NFMP_MODE, value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NF_MATCHER_HPP_INCLUDED
