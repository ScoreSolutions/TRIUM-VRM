#ifndef NF_EXTRACTOR_H_INCLUDED
#define NF_EXTRACTOR_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NFRecord.h>
#include <NExtractors.h>
#include <NFExtractorParams.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NfeExtractionStatus_
{
	nfeesTemplateCreated = 1,
	nfeesTooFewMinutiae = 90,
	nfeesQualityCheckFailed = 100,
	nfeesMatchingFailed = 200
} NfeExtractionStatus;

N_DECLARE_TYPE(NfeExtractionStatus)

N_DECLARE_OBJECT_TYPE(NFExtractor, NObject);

NResult N_API NfeMakeLightTemplate(HNFRecord hRecord, NBool makeSmallTemplate, NBool preserveRidgeCounts, HNFRecord * phLightRecord);
NResult N_API NfeMakeSmallTemplate(HNFRecord hRecord, HNFRecord * phSmallRecord);
NResult N_API NfeIsTemplateSmall(HNFRecord hRecord, NBool * pValue);

NResult N_API NfeCreate(HNFExtractor * phExtractor);
NResult N_API NfeCreateEx(NBool isPalm, HNFExtractor * phExtractor);

NResult N_API NfeExtract(HNFExtractor hExtractor, HNGrayscaleImage hImage,
	NFPosition position, NFImpressionType impressionType, NfeExtractionStatus * pExtractionStatus, HNFRecord * phRecord);
NResult N_API NfeUpdateTemplate(HNFExtractor hExtractor, HNGrayscaleImage hImage, HNFRecord hRecord);
NResult N_API NfeGeneralizeEx(HNFExtractor hExtractor, NInt recordCount, const HNFRecord * arhRecords,
	NfeExtractionStatus * pStatus, NInt * pBaseTemplateIndex, HNFRecord * phRecord);

NResult N_API NfeIsPalm(HNFExtractor hExtractor, NBool * pValue);

#ifdef N_CPP
}
#endif

#endif // !NF_EXTRACTOR_H_INCLUDED
