#ifndef NL_EXTRACTOR_H_INCLUDED
#define NL_EXTRACTOR_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NGeometry.h>
#include <NLTemplate.h>
#include <NExtractors.h>
#include <NLExtractorParams.h>
#include <NBiometricTypes.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef struct NleRotation_
{
	NShort Yaw;
	NShort Pitch;
	NShort Roll;
} NleRotation;

typedef struct NleFace_
{
	struct NRect_ Rectangle;
	NleRotation Rotation;
	NDouble Confidence;
} NleFace;

typedef struct NleEyes_
{
	struct NPoint_ First;
	NDouble FirstConfidence;
	struct NPoint_ Second;
	NDouble SecondConfidence;
} NleEyes;

#define NLE_FEATURE_POINT_COUNT 68

struct NleDetectionDetails_
{
	NBool FaceAvailable;
	NInt Padding1;
	NleFace Face;
	N_DEPRECATED("field is deprecated, use RightEyeCenter.Confidence > 0 and LeftEyeCenter.Confidence > 0 instead")
	NBool EyesAvailable;
	NInt Padding2;
	N_DEPRECATED("field is deprecated, use RightEyeCenter and LeftEyeCenter instead")
	NleEyes Eyes;
	NGender Gender;
	NLExpression Expression;
	NLProperties Properties;
	NByte GenderConfidence;
	NByte ExpressionConfidence;
	NByte GlassesConfidence;
	NByte DarkGlassesConfidence;
	NByte BlinkConfidence;
	NByte MouthOpenConfidence;
	NByte ReservedConfidence[6];
	struct NLFeaturePoint_ RightEyeCenter;
	struct NLFeaturePoint_ LeftEyeCenter;
	struct NLFeaturePoint_ NoseTip;
	struct NLFeaturePoint_ MouthCenter;
	struct NLFeaturePoint_ Reserved[4];
	struct NLFeaturePoint_ Points[NLE_FEATURE_POINT_COUNT];
};
#ifndef N_BIOMETRIC_TYPES_HPP_INCLUDED
typedef struct NleDetectionDetails_ NleDetectionDetails;
#endif

typedef enum NleExtractionStatus_
{
	nleesNone = 0,
	nleesTemplateCreated = 1,
	nleesFaceNotDetected = 2,
	nleesEyesNotDetected = 3,
	nleesFaceTooCloseToImageBorder = 4,
	nleesQualityCheckGrayscaleDensityFailed = 100,
	nleesQualityCheckExposureFailed = 101,
	nleesQualityCheckSharpnessFailed = 102,
	nleesLivenessCheckFailed = 200,
	nleesGeneralizationFailed = 300,
} NleExtractionStatus;

N_DECLARE_TYPE(NleExtractionStatus)

NResult N_API NleDetectionDetailsClear(struct NleDetectionDetails_ * pDetectionDetails);

N_DECLARE_OBJECT_TYPE(NLExtractor, NObject)

NResult N_API NleCompressEx(HNLTemplate hSrcTemplate, NleTemplateSize dstTemplateSize, HNLTemplate * phDstTemplate);

NResult N_API NleCreate(HNLExtractor * phExtractor);

NResult N_API NleDetectFace(HNLExtractor hExtractor, HNGrayscaleImage hImage, NBool * pDetected, NleFace * pFace);
NResult N_API NleDetectFaces(HNLExtractor hExtractor, HNGrayscaleImage hImage, NInt * pFaceCount, NleFace * * parFaces);

NResult N_API NleDetectFacialFeatures(HNLExtractor hExtractor,
	HNGrayscaleImage hImage, const NleFace * pFace, struct NleDetectionDetails_ * pDetectionDetails);

NResult N_API NleExtract(HNLExtractor hExtractor,
	HNGrayscaleImage hImage, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate * phTemplate);

N_DEPRECATED("function is deprecated, use NleExtractStartEx instead")
NResult N_API NleExtractStart(HNLExtractor hExtractor, NInt durationInFrames);
NResult N_API NleExtractStartEx(HNLExtractor hExtractor);

N_DEPRECATED("function is deprecated, use NleExtractNextEx2 and NleExtractEndEx instead")
NResult N_API NleExtractNextEx(HNLExtractor hExtractor, HNGrayscaleImage hImage, struct NleDetectionDetails_ * pDetectionDetails,
	NInt * pBaseFrameIndex, HNLTemplate * phTemplate, NleExtractionStatus * pStatus);
NResult N_API NleExtractNextEx2(HNLExtractor hExtractor, HNGrayscaleImage hImage, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus);

#define NleExtractEnd(hExtractor, pBaseFrameIndex, pStatus, phTemplate) NleExtractEndEx(hExtractor, pBaseFrameIndex, NULL, pStatus, phTemplate)
NResult N_API NleExtractEndEx(HNLExtractor hExtractor, NInt * pBaseFrameIndex, struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate *phTemplate);

NResult N_API NleExtractUsingDetails(HNLExtractor hExtractor, HNGrayscaleImage hImage,
	struct NleDetectionDetails_ * pDetectionDetails, NleExtractionStatus * pStatus, HNLTemplate * phTemplate);

NResult N_API NleGeneralizeEx(HNLExtractor hExtractor, NInt templateCount, const HNLTemplate * arhTemplates,
	NleExtractionStatus * pStatus, NInt * pBaseTemplateIndex, HNLTemplate * phTemplate);

#ifdef N_MSVC
	#pragma deprecated("NleExtractEnd")
#endif

#ifdef N_CPP
}
#endif

#endif // !NL_EXTRACTOR_H_INCLUDED
