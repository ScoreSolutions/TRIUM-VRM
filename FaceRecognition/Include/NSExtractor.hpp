#ifndef NS_EXTRACTOR_HPP_INCLUDED
#define NS_EXTRACTOR_HPP_INCLUDED

#include <NSoundBuffer.hpp>
#include <NSRecord.hpp>
#include <NSExtractorParams.hpp>
#include <NSAttributes.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Sound::HNSoundBuffer;
#include <NSExtractor.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NSExtractor) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NSExtractor, NObject)

private:
	static HNSExtractor Create()
	{
		HNSExtractor handle;
		NCheck(NseCreate(&handle));
		return handle;
	}

	N_CLASS(NSExtractor)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NseExtractionStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NseExtractionStatus), true, true);
	}

	N_CLASS(NSExtractor)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NSExtractor);
	}

	N_CLASS(NSRecord) * Extract(NInt phraseId, ::Neurotec::Sound::N_CLASS(NSoundBuffer) * pSound, NseExtractionStatus * pStatus)
	{
		return Extract(phraseId, pSound, NULL, NULL, pStatus);
	}

	N_CLASS(NSRecord) * Extract(NInt phraseId, ::Neurotec::Sound::N_CLASS(NSoundBuffer) * pSound, N_CLASS(NTimeSpan) * pVoiceStart, N_CLASS(NTimeSpan) * pVoiceDuration, NseExtractionStatus * pStatus)
	{
		if (pSound == NULL) NThrowArgumentNullException(N_T("pSound"));
		NTimeSpan_ vs, vd;
		HNSRecord hRecord = NULL;
		NCheck(NseExtractEx(GetHandle(), phraseId, pSound->GetHandle(), &vs, &vd, pStatus, &hRecord));
		try
		{
			if (pVoiceStart) *pVoiceStart = N_CLASS(NTimeSpan)(vs);
			if (pVoiceDuration) *pVoiceDuration = N_CLASS(NTimeSpan)(vd);
			return FromHandle<N_CLASS(NSRecord)>(hRecord);
		}
		catch (...)
		{
			Unref(hRecord);
			throw;
		}
	}

	void ExtractStart(NInt phraseId)
	{
		NCheck(NseExtractStart(GetHandle(), phraseId));
	}

	NseExtractionStatus ExtractNext(::Neurotec::Sound::N_CLASS(NSoundBuffer) * pSound, bool * pVoiceDetected = NULL)
	{
		if (!pSound) NThrowArgumentNullException(N_T("pSound"));
		NBool vd;
		NseExtractionStatus status;
		NCheck(NseExtractNextEx(GetHandle(), pSound->GetHandle(), &vd, &status));
		if (pVoiceDetected) *pVoiceDetected = vd != 0;
		return status;
	}

	N_CLASS(NSRecord) * ExtractEnd(NseExtractionStatus * pStatus, N_CLASS(NTimeSpan) * pVoiceStart = NULL, N_CLASS(NTimeSpan) * pVoiceDuration = NULL, ::Neurotec::Sound::N_CLASS(NSoundBuffer) * * ppVoice = NULL)
	{
		NTimeSpan_ vs, vd;
		HNSoundBuffer hVoice = NULL;
		HNSRecord hRecord = NULL;
		NCheck(NseExtractEndEx(GetHandle(), &vs, &vd, ppVoice ? &hVoice : NULL, pStatus, &hRecord));
		try
		{
			if (pVoiceStart) *pVoiceStart = N_CLASS(NTimeSpan)(vs);
			if (pVoiceDuration) *pVoiceDuration = N_CLASS(NTimeSpan)(vd);
			if (ppVoice)
			{
				*ppVoice = FromHandle< ::Neurotec::Sound::N_CLASS(NSoundBuffer)>(hVoice);
				hVoice = NULL;
			}
			return FromHandle<N_CLASS(NSRecord)>(hRecord);
		}
		catch (...)
		{
			Unref(hVoice);
			Unref(hRecord);
			throw;
		}
	}

	NInt GetMinPhraseDurationRaw()
	{
		return GetParameter<NInt>(NSEP_MIN_PHRASE_DURATION);
	}

	void SetMinPhraseDurationRaw(NInt value)
	{
		SetParameter(NSEP_MIN_PHRASE_DURATION, value);
	}

	NInt GetMaxPhraseDurationRaw()
	{
		return GetParameter<NInt>(NSEP_MAX_PHRASE_DURATION);
	}

	void SetMaxPhraseDurationRaw(NInt value)
	{
		SetParameter(NSEP_MAX_PHRASE_DURATION, value);
	}

	NInt GetMaxPauseDurationRaw()
	{
		return GetParameter<NInt>(NSEP_MAX_PAUSE_DURATION);
	}

	void SetMaxPauseDurationRaw(NInt value)
	{
		SetParameter(NSEP_MAX_PAUSE_DURATION, value);
	}

	bool GetUseSpeakerDetection()
	{
		return GetParameter<bool>(NSEP_USE_SPEAKER_DETECTION);
	}

	void SetUseSpeakerDetection(bool value)
	{
		SetParameter(NSEP_USE_SPEAKER_DETECTION, value);
	}

	bool GetExtractTextDependentFeatures()
	{
		return GetParameter<bool>(NSEP_EXTRACT_TEXT_DEPENDENT_FEATURES);
	}

	void SetExtractTextDependentFeatures(bool value)
	{
		SetParameter(NSEP_EXTRACT_TEXT_DEPENDENT_FEATURES, value);
	}

	bool GetExtractTextIndependentFeatures()
	{
		return GetParameter<bool>(NSEP_EXTRACT_TEXT_INDEPENDENT_FEATURES);
	}

	void SetExtractTextIndependentFeatures(bool value)
	{
		SetParameter(NSEP_EXTRACT_TEXT_INDEPENDENT_FEATURES, value);
	}
};

}}

#endif // !NS_EXTRACTOR_HPP_INCLUDED
