#ifndef NFS_MATCHER_HPP_INCLUDED
#define NFS_MATCHER_HPP_INCLUDED

#include <NFMatcher.hpp>
#include <NfsmMatchDetails.hpp>
#include <NfsMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NfsMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

#include <NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(N_CLASS(NMatcher)) " instead")
	N_CLASS(NfsMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NfsMatcher, NObject)

private:
	static HNfsMatcher Create(bool isPalm)
	{
		HNfsMatcher handle;
		NCheck(NfsmCreateEx(isPalm, &handle));
		return handle;
	}

	N_CLASS(NfsMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	explicit N_CLASS(NfsMatcher)(bool isPalm = false)
		: N_CLASS(NObject)(Create(isPalm), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NfsMatcher);
	}

	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NfsmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NInt score;
		NCheck(NfsmVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NfsmMatchDetails * * ppMatchDetails = NULL)
	{
		NInt score;
		NCheck(NfsmVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NfsmMatchDetails * * ppMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NfsmIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NfsmMatchDetails * * ppMatchDetails = NULL)
	{
		NCheck(NfsmIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}

	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NfsmMatchDetails * pMatchDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NfsmIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, NfsmMatchDetails * pMatchDetails)
	{
		NInt score;
		NCheck(NfsmIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NfsmIdentifyEnd(GetHandle()));
	}

	NBool IsPalm()
	{
		NBool value;
		NCheck(NfsmIsPalm(GetHandle(), &value));
		return value;
	}

	NInt GetMatchingThreshold()
	{
		return GetParameter<NInt>(NFSM_PART_NONE, NFSMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NInt value)
	{
		SetParameter(NFSM_PART_NONE, NFSMP_MATCHING_THRESHOLD, value);
	}

	NInt GetMinMatchedFingerCount()
	{
		return GetParameter<NInt>(NFSM_PART_NONE, NFSMP_MIN_MATCHED_FINGER_COUNT);
	}

	void SetMinMatchedFingerCount(NInt value)
	{
		SetParameter(NFSM_PART_NONE, NFSMP_MIN_MATCHED_FINGER_COUNT, value);
	}

	NInt GetMinMatchedFingerCountThreshold()
	{
		return GetParameter<NInt>(NFSM_PART_NONE, NFSMP_MIN_MATCHED_FINGER_COUNT_THRESHOLD);
	}

	void SetMinMatchedFingerCountThreshold(NInt value)
	{
		SetParameter(NFSM_PART_NONE, NFSMP_MIN_MATCHED_FINGER_COUNT_THRESHOLD, value);
	}

	NByte GetNfmMaximalRotation()
	{
		return GetParameter<NByte>(NFSM_PART_NFM, NFMP_MAXIMAL_ROTATION);
	}

	void SetNfmMaximalRotation(NByte value)
	{
		SetParameter(NFSM_PART_NFM, NFMP_MAXIMAL_ROTATION, value);
	}

	NfmSpeed GetNfmMatchingSpeed()
	{
		return (NfmSpeed)GetParameter<NInt>(NFSM_PART_NFM, NFMP_MATCHING_SPEED);
	}

	void SetNfmMatchingSpeed(NfmSpeed value)
	{
		SetParameter(NFSM_PART_NFM, NFMP_MATCHING_SPEED, value);
	}

	NUInt GetMode()
	{
		return GetParameter<NUInt>(NFSM_PART_NFM, NFMP_MODE);
	}

	void SetMode(NUInt value)
	{
		SetParameter(NFSM_PART_NFM, NFMP_MODE, value);
	}
};
#include <NReDeprecate.h>

}}

#endif // !NFS_MATCHER_HPP_INCLUDED
