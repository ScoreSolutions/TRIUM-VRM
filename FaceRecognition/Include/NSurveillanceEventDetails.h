#ifndef N_SURVEILLANCE_EVENT_DETAILS_H_INCLUDED
#define N_SURVEILLANCE_EVENT_DETAILS_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NRgbImage.h>
#include <NTemplate.h>
#include <NLExtractor.h>
#include <NsedMatch.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSurveillanceEventDetails, NObject)

// Image capture
NResult N_API NsedGetTraceIndex(HNSurveillanceEventDetails hDetails, NInt * pValue);
NResult N_API NsedGetSourceIndex(HNSurveillanceEventDetails hDetails, NInt * pValue);
NResult N_API NsedGetFrameIndex(HNSurveillanceEventDetails hDetails, NULong * pValue);
NResult N_API NsedGetTimeStamp(HNSurveillanceEventDetails hDetails, NDateTime_ * pValue);
NResult N_API NsedGetOriginalImage(HNSurveillanceEventDetails hDetails, HNImage * phValue);
NResult N_API NsedGetOriginalImageEx(HNSurveillanceEventDetails hDetails, HNImage * phValue);
NResult N_API NsedGetGrayscaleImage(HNSurveillanceEventDetails hDetails, HNGrayscaleImage * phValue);
NResult N_API NsedGetGrayscaleImageEx(HNSurveillanceEventDetails hDetails, HNGrayscaleImage * phValue);
// Faces detection
NResult N_API NsedGetFaces(HNSurveillanceEventDetails hDetails, NleFace * arFaces);
// Extraction
NResult N_API NsedGetDetectionDetails(HNSurveillanceEventDetails hDetails, NleDetectionDetails * pValue);
NResult N_API NsedGetExtractionStatus(HNSurveillanceEventDetails hDetails, NleExtractionStatus * pValue);
NResult N_API NsedGetTemplate(HNSurveillanceEventDetails hDetails, HNLTemplate * phValue);
NResult N_API NsedGetTemplateEx(HNSurveillanceEventDetails hDetails, HNLTemplate * phValue);
// Identification
NResult N_API NsedGetBestMatchCount(HNSurveillanceEventDetails hDetails, NInt * pValue);
NResult N_API NsedGetBestMatchEx(HNSurveillanceEventDetails hDetails, NInt index, struct NsedMatchEx_ * pValue);
NResult N_API NsedGetBestMatch(HNSurveillanceEventDetails hDetails, NInt index, NsedMatch * pValue);
NResult N_API NsedGetBestMatchesEx2(HNSurveillanceEventDetails hDetails, struct NsedMatchEx_ * arValues, NInt valuesLength);
NResult N_API NsedGetBestMatchesEx(HNSurveillanceEventDetails hDetails, NsedMatch * arValues, NInt valuesLength);
// Subject events
NResult N_API NsedGetSubjectTemplate(HNSurveillanceEventDetails hDetails, HNLTemplate * phTemplate);

#define NsedGetBestMatches(hDetails, arBestMatches) NsedGetBestMatchesEx(hDetails, arBestMatches, N_INT_MAX)

#ifdef N_MSVC
	#pragma deprecated("NsedGetBestMatches")
#endif

#ifdef N_CPP
}
#endif

#endif // !N_SURVEILLANCE_EVENT_DETAILS_H_INCLUDED
