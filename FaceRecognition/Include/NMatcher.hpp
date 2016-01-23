#ifndef N_MATCHER_HPP_INCLUDED
#define N_MATCHER_HPP_INCLUDED

#include <NfsMatcher.hpp>
#include <NlsMatcher.hpp>
#include <NesMatcher.hpp>
#include <NMMatchDetails.hpp>
#include <NMatchingDetails.hpp>
#include <NMatcherParams.hpp>
namespace Neurotec { namespace Biometrics
{
#include <NMatcher.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NMatcher) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NMatcher, NObject)

private:
	static HNMatcher Create()
	{
		HNMatcher handle;
		NCheck(NMCreate(&handle));
		return handle;
	}

	N_CLASS(NMatcher)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NMatchingSpeedNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NMatchingSpeed), true, true);
	}

	static N_CLASS(NType) * NMFusionTypeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NMFusionType), true, true);
	}

	N_CLASS(NMatcher)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NMatcher);
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use Verify(" N_STRINGIZEA(N_CLASS(NBuffer)) " *, " N_STRINGIZEA(N_CLASS(NBuffer)) " *, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " * *) instead")
	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, NMMatchDetails * * ppMatchDetails)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		NInt score;
		NCheck(NMVerifyN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchDetails, &score));
		return score;
	}

	N_DEPRECATED("method is deprecated, use Verify(const void *, NSizeType, const void *, NSizeType, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " * *) instead")
	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, NMMatchDetails * * ppMatchDetails)
	{
		NInt score;
		NCheck(NMVerify(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchDetails, &score));
		return score;
	}
#include <NReDeprecate.h>

	NInt Verify(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate1, ::Neurotec::IO::N_CLASS(NBuffer) * pTemplate2, N_CLASS(NMatchingDetails) * * ppMatchingDetails = NULL)
	{
		if (!pTemplate1) NThrowArgumentNullException(N_T("pTemplate1"));
		if (!pTemplate2) NThrowArgumentNullException(N_T("pTemplate2"));
		HNMatchingDetails hMatchingDetails = NULL;
		NInt score;
		NCheck(NMVerifyExN(GetHandle(), pTemplate1->GetHandle(), pTemplate2->GetHandle(), ppMatchingDetails ? &hMatchingDetails : NULL, &score));
		try
		{
			if (ppMatchingDetails) *ppMatchingDetails = FromHandle<N_CLASS(NMatchingDetails)>(hMatchingDetails);
			return score;
		}
		catch (...)
		{
			Unref(hMatchingDetails);
			throw;
		}
	}

	NInt Verify(const void * pTemplate1, NSizeType template1Size, const void * pTemplate2, NSizeType template2Size, N_CLASS(NMatchingDetails) * * ppMatchingDetails = NULL)
	{
		HNMatchingDetails hMatchingDetails = NULL;
		NInt score;
		NCheck(NMVerifyEx(GetHandle(), pTemplate1, template1Size, pTemplate2, template2Size, ppMatchingDetails ? &hMatchingDetails : NULL, &score));
		try
		{
			if (ppMatchingDetails) *ppMatchingDetails = FromHandle<N_CLASS(NMatchingDetails)>(hMatchingDetails);
			return score;
		}
		catch (...)
		{
			Unref(hMatchingDetails);
			throw;
		}
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use IdentifyStart(" N_STRINGIZEA(N_CLASS(NBuffer)) " *, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " * *) instead")
	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NMMatchDetails * * ppMatchDetails)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NMIdentifyStartN(GetHandle(), pTemplate->GetHandle(), ppMatchDetails));
	}

	N_DEPRECATED("method is deprecated, use IdentifyStart(const void *, NSizeType, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " * *) instead")
	void IdentifyStart(const void * pTemplate, NSizeType templateSize, NMMatchDetails * * ppMatchDetails)
	{
		NCheck(NMIdentifyStart(GetHandle(), pTemplate, templateSize, ppMatchDetails));
	}
#include <NReDeprecate.h>

	void IdentifyStart(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, N_CLASS(NMatchingDetails) * * ppMatchingDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		HNMatchingDetails hMatchingDetails = NULL;
		NCheck(NMIdentifyStartExN(GetHandle(), pTemplate->GetHandle(), ppMatchingDetails ? &hMatchingDetails : NULL));
		try
		{
			if (ppMatchingDetails) *ppMatchingDetails = FromHandle<N_CLASS(NMatchingDetails)>(hMatchingDetails);
		}
		catch (...)
		{
			Unref(hMatchingDetails);
			throw;
		}
	}

	void IdentifyStart(const void * pTemplate, NSizeType templateSize, N_CLASS(NMatchingDetails) * * ppMatchingDetails = NULL)
	{
		HNMatchingDetails hMatchingDetails = NULL;
		NCheck(NMIdentifyStartEx(GetHandle(), pTemplate, templateSize, ppMatchingDetails ? &hMatchingDetails : NULL));
		try
		{
			if (ppMatchingDetails) *ppMatchingDetails = FromHandle<N_CLASS(NMatchingDetails)>(hMatchingDetails);
		}
		catch (...)
		{
			Unref(hMatchingDetails);
			throw;
		}
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use IdentifyNext(" N_STRINGIZEA(N_CLASS(NBuffer)) " *, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " *) instead")
	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, NMMatchDetails * pMatchDetails)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NMIdentifyNextN(GetHandle(), pTemplate->GetHandle(), pMatchDetails, &score));
		return score;
	}

	N_DEPRECATED("method is deprecated, use IdentifyNext(const void *, NSizeType, " N_STRINGIZEA(N_CLASS(NMatchingDetails)) " *) instead")
	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, NMMatchDetails * pMatchDetails)
	{
		NInt score;
		NCheck(NMIdentifyNext(GetHandle(), pTemplate, templateSize, pMatchDetails, &score));
		return score;
	}
#include <NReDeprecate.h>

	NInt IdentifyNext(::Neurotec::IO::N_CLASS(NBuffer) * pTemplate, N_CLASS(NMatchingDetails) * pMatchingDetails = NULL)
	{
		if (!pTemplate) NThrowArgumentNullException(N_T("pTemplate"));
		NInt score;
		NCheck(NMIdentifyNextExN(GetHandle(), pTemplate->GetHandle(), ToHandle(pMatchingDetails), &score));
		return score;
	}

	NInt IdentifyNext(const void * pTemplate, NSizeType templateSize, N_CLASS(NMatchingDetails) * pMatchingDetails = NULL)
	{
		NInt score;
		NCheck(NMIdentifyNextEx(GetHandle(), pTemplate, templateSize, ToHandle(pMatchingDetails), &score));
		return score;
	}

	void IdentifyEnd()
	{
		NCheck(NMIdentifyEnd(GetHandle()));
	}

	NInt GetMatchingThreshold()
	{
		return GetParameter<NInt>(NMP_MATCHING_THRESHOLD);
	}

	void SetMatchingThreshold(NInt value)
	{
		SetParameter(NMP_MATCHING_THRESHOLD, value);
	}

	NMFusionType GetFusionType()
	{
		return (NMFusionType)GetParameter<NInt>(NMP_FUSION_TYPE);
	}

	void SetFusionType(NMFusionType value)
	{
		SetParameter(NMP_FUSION_TYPE, (NInt)value);
	}

	N_DEPRECATED("method is deprecated, use GetFacesMatchingThresholdNew instead")
	NDouble GetFacesMatchingThreshold()
	{
		return GetParameter<NDouble>(NMP_FACES_MATCHING_THRESHOLD);
	}

	NInt GetFacesMatchingThresholdNew()
	{
		return GetParameter<NInt>(NMP_FACES_MATCHING_THRESHOLD_NEW);
	}

	N_DEPRECATED("method is deprecated, use SetFacesMatchingThresholdNew instead")
	void SetFacesMatchingThreshold(NDouble value)
	{
		SetParameter(NMP_FACES_MATCHING_THRESHOLD, value);
	}

	void SetFacesMatchingThresholdNew(NInt value)
	{
		SetParameter(NMP_FACES_MATCHING_THRESHOLD_NEW, value);
	}

	NInt GetIrisesMatchingThreshold()
	{
		return GetParameter<NInt>(NMP_IRISES_MATCHING_THRESHOLD);
	}

	void SetIrisesMatchingThreshold(NInt value)
	{
		SetParameter(NMP_IRISES_MATCHING_THRESHOLD, value);
	}

	N_DEPRECATED("method is deprecated, use GetFingersMaximalRotation instead")
	NByte GetFingersNfmMaximalRotation()
	{
		return GetFingersMaximalRotation();
	}

	NByte GetFingersMaximalRotation()
	{
		return GetParameter<NByte>(NMP_FINGERS_MAXIMAL_ROTATION);
	}

	N_DEPRECATED("method is deprecated, use SetFingersMaximalRotation instead")
	void SetFingersNfmMaximalRotation(NByte value)
	{
		SetFingersMaximalRotation(value);
	}

	void SetFingersMaximalRotation(NByte value)
	{
		SetParameter(NMP_FINGERS_MAXIMAL_ROTATION, value);
	}

	N_DEPRECATED("method is deprecated, use GetFingersMatchingSpeed instead")
	NfmSpeed GetFingersNfmMatchingSpeed()
	{
		return (NfmSpeed)GetFingersMatchingSpeed();
	}

	NMatchingSpeed GetFingersMatchingSpeed()
	{
		return (NMatchingSpeed)GetParameter<NInt>(NMP_FINGERS_MATCHING_SPEED);
	}

	N_DEPRECATED("method is deprecated, use SetFingersMatchingSpeed instead")
	void SetFingersNfmMatchingSpeed(NfmSpeed value)
	{
		SetFingersMatchingSpeed((NMatchingSpeed)value);
	}

	void SetFingersMatchingSpeed(NMatchingSpeed value)
	{
		SetParameter(NMP_FINGERS_MATCHING_SPEED, (NInt)value);
	}

	N_DEPRECATED("method is deprecated, use GetFingersMode instead")
	NUInt GetFingersNfmMode()
	{
		return GetFingersMode();
	}

	NUInt GetFingersMode()
	{
		return GetParameter<NUInt>(NMP_FINGERS_MODE);
	}

	N_DEPRECATED("method is deprecated, use SetFingersMode instead")
	void SetFingersNfmMode(NUInt value)
	{
		SetFingersMode(value);
	}

	void SetFingersMode(NUInt value)
	{
		SetParameter(NMP_FINGERS_MODE, value);
	}

	N_DEPRECATED("method is deprecated, use GetFingersMinMatchedCount instead")
	NInt GetFingersMinMatchedFingerCount()
	{
		return GetFingersMinMatchedCount();
	}

	NInt GetFingersMinMatchedCount()
	{
		return GetParameter<NInt>(NMP_FINGERS_MIN_MATCHED_COUNT);
	}

	N_DEPRECATED("method is deprecated, use SetFingersMinMatchedCount instead")
	void SetFingersMinMatchedFingerCount(NInt value)
	{
		SetFingersMinMatchedCount(value);
	}

	void SetFingersMinMatchedCount(NInt value)
	{
		SetParameter(NMP_FINGERS_MIN_MATCHED_COUNT, value);
	}

	N_DEPRECATED("method is deprecated, use GetFingersMinMatchedCountThreshold instead")
	NInt GetFingersMinMatchedFingerCountThreshold()
	{
		return GetFingersMinMatchedCountThreshold();
	}

	NInt GetFingersMinMatchedCountThreshold()
	{
		return GetParameter<NInt>(NMP_FINGERS_MIN_MATCHED_COUNT_THRESHOLD);
	}

	N_DEPRECATED("method is deprecated, use SetFingersMinMatchedCountThreshold instead")
	void SetFingersMinMatchedFingerCountThreshold(NInt value)
	{
		SetFingersMinMatchedCountThreshold(value);
	}

	void SetFingersMinMatchedCountThreshold(NInt value)
	{
		SetParameter(NMP_FINGERS_MIN_MATCHED_COUNT_THRESHOLD, value);
	}

	N_DEPRECATED("method is deprecated, use GetFacesMatchingSpeed instead")
	NlmSpeed GetFacesNlmMatchingSpeed()
	{
		return (NlmSpeed)GetFacesMatchingSpeed();
	}

	NMatchingSpeed GetFacesMatchingSpeed()
	{
		return (NMatchingSpeed)GetParameter<NInt>(NMP_FACES_MATCHING_SPEED);
	}

	N_DEPRECATED("method is deprecated, use SetFacesMatchingSpeed instead")
	void SetFacesNlmMatchingSpeed(NlmSpeed value)
	{
		SetFacesMatchingSpeed((NMatchingSpeed)value);
	}

	void SetFacesMatchingSpeed(NMatchingSpeed value)
	{
		SetParameter(NMP_FACES_MATCHING_SPEED, (NInt)value);
	}

	N_DEPRECATED("method is deprecated, use GetIrisesMatchingSpeed instead")
	NemSpeed GetIrisesNemMatchingSpeed()
	{
		return (NemSpeed)GetIrisesMatchingSpeed();
	}

	NMatchingSpeed GetIrisesMatchingSpeed()
	{
		return (NMatchingSpeed)GetParameter<NInt>(NMP_IRISES_MATCHING_SPEED);
	}

	N_DEPRECATED("method is deprecated, use SetIrisesMatchingSpeed instead")
	void SetIrisesNemMatchingSpeed(NemSpeed value)
	{
		SetIrisesMatchingSpeed((NMatchingSpeed)value);
	}

	void SetIrisesMatchingSpeed(NMatchingSpeed value)
	{
		SetParameter(NMP_IRISES_MATCHING_SPEED, (NInt)value);
	}

	N_DEPRECATED("method is deprecated, use GetIrisesMaximalRotation instead")
	NByte GetIrisesNemMaximalRotation()
	{
		return GetIrisesMaximalRotation();
	}

	NByte GetIrisesMaximalRotation()
	{
		return GetParameter<NByte>(NMP_IRISES_MAXIMAL_ROTATION);
	}

	N_DEPRECATED("method is deprecated, use SetIrisesMaximalRotation instead")
	void SetIrisesNemMaximalRotation(NByte value)
	{
		SetIrisesMaximalRotation(value);
	}

	void SetIrisesMaximalRotation(NByte value)
	{
		SetParameter(NMP_IRISES_MAXIMAL_ROTATION, value);
	}

	NInt GetIrisesMinMatchedCount()
	{
		return GetParameter<NInt>(NMP_IRISES_MIN_MATCHED_COUNT);
	}

	void SetIrisesMinMatchedCount(NInt value)
	{
		SetParameter(NMP_IRISES_MIN_MATCHED_COUNT, value);
	}

	NInt GetIrisesMinMatchedCountThreshold()
	{
		return GetParameter<NInt>(NMP_IRISES_MIN_MATCHED_COUNT_THRESHOLD);
	}

	void SetIrisesMinMatchedCountThreshold(NInt value)
	{
		SetParameter(NMP_IRISES_MIN_MATCHED_COUNT_THRESHOLD, value);
	}

	N_DEPRECATED("method is deprecated, use GetPalmsMaximalRotation instead")
	NByte GetPalmsNfmMaximalRotation()
	{
		return GetPalmsMaximalRotation();
	}

	NByte GetPalmsMaximalRotation()
	{
		return GetParameter<NByte>(NMP_PALMS_MAXIMAL_ROTATION);
	}

	N_DEPRECATED("method is deprecated, use SetPalmsMaximalRotation instead")
	void SetPalmsNfmMaximalRotation(NByte value)
	{
		SetPalmsMaximalRotation(value);
	}

	void SetPalmsMaximalRotation(NByte value)
	{
		SetParameter(NMP_PALMS_MAXIMAL_ROTATION, value);
	}

	N_DEPRECATED("method is deprecated, use GetPalmsMatchingSpeed instead")
	NfmSpeed GetPalmsNfmMatchingSpeed()
	{
		return (NfmSpeed)GetPalmsMatchingSpeed();
	}

	NMatchingSpeed GetPalmsMatchingSpeed()
	{
		return (NMatchingSpeed)GetParameter<NInt>(NMP_PALMS_MATCHING_SPEED);
	}

	N_DEPRECATED("method is deprecated, use SetPalmsMatchingSpeed instead")
	void SetPalmsNfmMatchingSpeed(NfmSpeed value)
	{
		SetPalmsMatchingSpeed((NMatchingSpeed)value);
	}

	void SetPalmsMatchingSpeed(NMatchingSpeed value)
	{
		SetParameter(NMP_PALMS_MATCHING_SPEED, (NInt)value);
	}

	NInt GetPalmsMinMatchedCount()
	{
		return GetParameter<NInt>(NMP_PALMS_MIN_MATCHED_COUNT);
	}

	void SetPalmsMinMatchedCount(NInt value)
	{
		SetParameter(NMP_PALMS_MIN_MATCHED_COUNT, value);
	}

	NInt GetPalmsMinMatchedCountThreshold()
	{
		return GetParameter<NInt>(NMP_PALMS_MIN_MATCHED_COUNT_THRESHOLD);
	}

	void SetPalmsMinMatchedCountThreshold(NInt value)
	{
		SetParameter(NMP_PALMS_MIN_MATCHED_COUNT_THRESHOLD, value);
	}

	bool GetVoicesUniquePhrasesOnly()
	{
		return GetParameter<bool>(NMP_VOICES_UNIQUE_PHRASES_ONLY);
	}

	void SetVoicesUniquePhrasesOnly(bool value)
	{
		return SetParameter(NMP_VOICES_UNIQUE_PHRASES_ONLY, value);
	}
};

}}

#endif // !N_MATCHER_HPP_INCLUDED
