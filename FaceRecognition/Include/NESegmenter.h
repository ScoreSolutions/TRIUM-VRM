#ifndef NE_SEGMENTER_H_INCLUDED
#define NE_SEGMENTER_H_INCLUDED

#include <NCore.h>
#include <NImage.h>
#include <NGeometry.h>
#include <NBiometrics.h>
#include <NEExtractor.h>
#include <NESegmenterParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NESegmenterAttributes, NObject)

NResult N_API NESegmenterAttributesGetGrayLevelSpread(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetIrisSize(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetPupilIrisRatio(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetUsableIrisArea(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetIrisScleraContrast(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetIrisPupilContrast(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetIrisScleraBoundaryShape(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetIrisPupilBoundaryShape(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetMargin(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetSharpness(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetSignalToNoiseRatio(HNESegmenterAttributes hAttributes, NByte * pValue);
NResult N_API NESegmenterAttributesGetInterlace(HNESegmenterAttributes hAttributes, NByte * pValue);

N_DECLARE_OBJECT_TYPE(NESegmenter, NObject)

NResult N_API NESegmenterCreate(HNESegmenter *phSegmenter);
NResult N_API NESegmenterProcess(HNESegmenter hSegmenter, HNGrayscaleImage hImage, NeeImageKind resultImageKind,
	HNESegmenterAttributes * phAttributes, NByte * pQuality, NeeExtractionStatus * pStatus, HNGrayscaleImage * phResultImage);

#ifdef N_CPP
}
#endif

#endif // !NE_SEGMENTER_H_INCLUDED
