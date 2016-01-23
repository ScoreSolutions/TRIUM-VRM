#ifndef NE_EXTRACTOR_H_INCLUDED
#define NE_EXTRACTOR_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NGeometry.h>
#include <NERecord.h>
#include <NExtractors.h>
#include <NEExtractorParams.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NEE_BOUNDARY_POINT_COUNT 32

typedef struct NeeSegmentationDetails_
{
	NBool InnerBoundaryAvailable;
	struct NPoint_ InnerBoundaryPoints[NEE_BOUNDARY_POINT_COUNT];
	NBool OuterBoundaryAvailable;
	struct NPoint_ OuterBoundaryPoints[NEE_BOUNDARY_POINT_COUNT];
} NeeSegmentationDetails;

typedef enum NeeExtractionStatus_
{
	neeesSucceeded = 1,
	neeesTemplateCreated = neeesSucceeded,
	neeesSegmentationFailed = 2,
	neeesQualityCheckFailed = 100,
} NeeExtractionStatus;

N_DECLARE_TYPE(NeeExtractionStatus)

typedef enum NeeImageKind_
{
	neeikUncropped = 1,
	neeikVga = 2,
	neeikCropped = 3,
	neeikCroppedAndMasked = 7,
} NeeImageKind;

N_DECLARE_TYPE(NeeImageKind)

N_DECLARE_OBJECT_TYPE(NEExtractor, NObject);

NResult N_API NeeCompress(HNERecord hSrcRecord, NeeTemplateSize dstTemplateSize, HNERecord * phDstRecord);

NResult N_API NeeCreate(HNEExtractor * phExtractor);

NResult N_API NeeExtract(HNEExtractor hExtractor, HNGrayscaleImage hImage, NEPosition position,
	NeeSegmentationDetails * pDetails, NeeExtractionStatus * pExtractionStatus, HNERecord * phRecord);

NResult N_API NeeExtractEx(HNEExtractor hExtractor, HNGrayscaleImage hImage, NeeImageKind imageKind, NEPosition position,
	NeeSegmentationDetails * pDetails, NeeExtractionStatus * pExtractionStatus, HNERecord * phRecord);

#ifdef N_CPP
}
#endif

#endif // !NE_EXTRACTOR_H_INCLUDED
