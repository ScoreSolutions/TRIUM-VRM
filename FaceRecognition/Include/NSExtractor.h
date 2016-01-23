#ifndef NS_EXTRACTOR_H_INCLUDED
#define NS_EXTRACTOR_H_INCLUDED

#include <NSoundBuffer.h>
#include <NSRecord.h>
#include <NSExtractorParams.h>
#include <NSAttributes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NseExtractionStatus_
{
	nseesNone = 0,
	nseesTemplateCreated = 1,
	nseesTooFewFeatures = 90,
} NseExtractionStatus;

N_DECLARE_TYPE(NseExtractionStatus)

N_DECLARE_OBJECT_TYPE(NSExtractor, NObject)

NResult N_API NseCreate(HNSExtractor * phExtractor);

#define NseExtract(hExtractor, phraseId, hSoundBuffer, pStatus, phRecord) NseExtractEx(hExtractor, phraseId, hSoundBuffer, NULL, NULL, pStatus, phRecord)
NResult N_API NseExtractEx(HNSExtractor hExtractor, NInt phraseId, HNSoundBuffer hSoundBuffer, NTimeSpan_ * pVoiceStart, NTimeSpan_ * pVoiceDuration, NseExtractionStatus * pStatus, HNSRecord * phRecord);

NResult N_API NseExtractStart(HNSExtractor hExtractor, NInt phraseId);
#define NseExtractNext(hExtractor, hSoundBuffer, pStatus) NseExtractNextEx(hExtractor, hSoundBuffer, NULL, pStatus)
NResult N_API NseExtractNextEx(HNSExtractor hExtractor, HNSoundBuffer hSoundBuffer, NBool * pVoiceDetected, NseExtractionStatus * pStatus);
#define NseExtractEnd(hExtractor, pStatus, phRecord) NseExtractEndEx(hExtractor, NULL, NULL, NULL, pStatus, phRecord)
NResult N_API NseExtractEndEx(HNSExtractor hExtractor, NTimeSpan_ * pVoiceStart, NTimeSpan_ * pVoiceDuration, HNSoundBuffer * phVoice, NseExtractionStatus * pStatus, HNSRecord * phRecord);

#ifdef N_MSVC
	#pragma deprecated("NseExtract", "NseExtractNext", "NseExtractEnd")
#endif

#ifdef N_CPP
}
#endif

#endif // !NS_EXTRACTOR_H_INCLUDED
