#ifndef NL_EXTRACTOR_HPP_INCLUDED
#define NL_EXTRACTOR_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NGeometry.hpp>
#include <NLTemplate.hpp>
#include <NLExtractorParams.hpp>
#include <NBiometricTypes.hpp>
namespace Neurotec { namespace Biometrics
{
using Neurotec::Images::HNGrayscaleImage;
using ::Neurotec::Geometry::NPoint_;
using ::Neurotec::Geometry::NRect_;
#include <NLExtractor.h>
}}
#include <vector>

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NleDetectionDetails) : public NleDetectionDetails_
{
public:
	explicit N_CLASS(NleDetectionDetails)(bool clear = true)
	{
		if (clear) Clear();
	}

	void Clear()
	{
		NCheck(NleDetectionDetailsClear(this));
	}
};
N_TYPEDEF_TYPE(NleDetectionDetails)

class N_CLASS(NLExtractor) : public N_CLASS(NObject)
{
private:
	static HNLExtractor Create()
	{
		HNLExtractor handle;
		NCheck(NleCreate(&handle));
		return handle;
	}

	N_CLASS(NLExtractor)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NleTemplateSizeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NleTemplateSize), true, true);
	}

	static N_CLASS(NType) * NleExtractionStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NleExtractionStatus), true, true);
	}

	static N_CLASS(NLTemplate) * Compress(N_CLASS(NLTemplate) * pTemplate, NleTemplateSize dstTemplateSize)
	{
		HNLTemplate hTemplate;
		if (pTemplate == NULL) NThrowArgumentNullException(N_T("pTemplate"));
		NCheck(NleCompressEx(pTemplate->GetHandle(), dstTemplateSize, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	N_CLASS(NLExtractor)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NLExtractor);
	}

	// Returns faceCount
	NInt DetectFaces(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleFace ** pArFaces)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		NInt faceCount;
		NCheck(NleDetectFaces(GetHandle(), pImage->GetHandle(), &faceCount, pArFaces));
		return faceCount;
	}

	bool DetectFace(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleFace * pFace)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		NBool detected;
		NCheck(NleDetectFace(GetHandle(), pImage->GetHandle(), &detected, pFace));
		return detected == NTrue;
	}

	NleDetectionDetails DetectFacialFeatures(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleFace * pFace)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		NleDetectionDetails details(false);
		NCheck(NleDetectFacialFeatures(GetHandle(), pImage->GetHandle(), pFace, &details));
		return details;
	}

	N_CLASS(NLTemplate) * Extract(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleDetectionDetails * pDetectionDetails, NleExtractionStatus * pExtractionStatus)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		HNLTemplate hTemplate;
		NCheck(NleExtract(GetHandle(), pImage->GetHandle(), pDetectionDetails, pExtractionStatus, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

#include <NNoDeprecate.h>
	N_DEPRECATED("method is deprecated, use ExtractStart() instead")
	void ExtractStart(NInt durationInFrames)
	{
		NCheck(NleExtractStart(GetHandle(), durationInFrames));
	}

	N_DEPRECATED("method is deprecated, use ExtractNext(" N_STRINGIZEA(N_CLASS(NGrayscaleImage)) " *, NleDetectionDetails *) and ExtractEnd instead")
	NleExtractionStatus ExtractNext(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleDetectionDetails * pDetectionDetails, NInt * pBaseFrameIndex, N_CLASS(NLTemplate) * * ppTemplate)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		if (ppTemplate == NULL) NThrowArgumentNullException(N_T("ppTemplate"));
		HNLTemplate hTemplate;
		NleExtractionStatus extractionStatus;
		NCheck(NleExtractNextEx(GetHandle(), pImage->GetHandle(), pDetectionDetails, pBaseFrameIndex, &hTemplate, &extractionStatus));
		try
		{
			*ppTemplate = FromHandle<N_CLASS(NLTemplate)>(hTemplate);
			return extractionStatus;
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}
#include <NReDeprecate.h>

	void ExtractStart()
	{
		NCheck(NleExtractStartEx(GetHandle()));
	}

	NleExtractionStatus ExtractNext(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleDetectionDetails * pDetectionDetails)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		NleExtractionStatus extractionStatus;
		NCheck(NleExtractNextEx2(GetHandle(), pImage->GetHandle(), pDetectionDetails, &extractionStatus));
		return extractionStatus;
	}

	N_DEPRECATED("method is deprecated, use ExtractEnd(NInt *, NleDetectionDetails *, NleExtractionStatus *) instead")
	N_CLASS(NLTemplate) * ExtractEnd(NInt * pBaseFrameIndex, NleExtractionStatus * pExtractionStatus)
	{
		return ExtractEnd(pBaseFrameIndex, NULL, pExtractionStatus);
	}

	N_CLASS(NLTemplate) * ExtractEnd(NInt * pBaseFrameIndex, NleDetectionDetails * pDetectionDetails, NleExtractionStatus * pExtractionStatus)
	{
		HNLTemplate hTemplate;
		NCheck(NleExtractEndEx(GetHandle(), pBaseFrameIndex, pDetectionDetails, pExtractionStatus, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	N_CLASS(NLTemplate) * ExtractUsingDetails(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NleDetectionDetails * pDetectionDetails, NleExtractionStatus * pExtractionStatus)
	{
		if (pImage == NULL) NThrowArgumentNullException(N_T("pImage"));
		HNLTemplate hTemplate;
		NCheck(NleExtractUsingDetails(GetHandle(), pImage->GetHandle(), pDetectionDetails, pExtractionStatus, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	N_CLASS(NLTemplate) * Generalize(NInt templateCount, N_CLASS(NLTemplate) * const * arpTemplates, NleExtractionStatus * pStatus, NInt * pBaseTemplateIndex)
	{
		N_CLASS(NObjectArray)<N_CLASS(NLTemplate)> templates(arpTemplates, templateCount);
		HNLTemplate hTemplate;
		NCheck(NleGeneralizeEx(GetHandle(), templates.GetCount(), templates.GetPtr(), pStatus, pBaseTemplateIndex, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NLTemplate)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	NInt GetMinIod()
	{
		return GetParameter<NInt>(NLEP_MIN_IOD);
	}

	void SetMinIod(NInt value)
	{
		SetParameter(NLEP_MIN_IOD, value);
	}

	NInt GetMaxIod()
	{
		return GetParameter<NInt>(NLEP_MAX_IOD);
	}

	void SetMaxIod(NInt value)
	{
		SetParameter(NLEP_MAX_IOD, value);
	}

	NDouble GetFaceConfidenceThreshold()
	{
		return GetParameter<NDouble>(NLEP_FACE_CONFIDENCE_THRESHOLD);
	}

	void SetFaceConfidenceThreshold(NDouble value)
	{
		SetParameter(NLEP_FACE_CONFIDENCE_THRESHOLD, value);
	}

	bool GetFavorLargestFace()
	{
		return GetParameter<bool>(NLEP_FAVOR_LARGEST_FACE);
	}

	void SetFavorLargestFace(bool value)
	{
		SetParameter(NLEP_FAVOR_LARGEST_FACE, value);
	}

	NShort GetMaxRollAngleDeviation()
	{
		return GetParameter<NShort>(NLEP_MAX_ROLL_ANGLE_DEVIATION);
	}

	void SetMaxRollAngleDeviation(NShort value)
	{
		SetParameter(NLEP_MAX_ROLL_ANGLE_DEVIATION, value);
	}

	NShort GetMaxYawAngleDeviation()
	{
		return GetParameter<NShort>(NLEP_MAX_YAW_ANGLE_DEVIATION);
	}

	void SetMaxYawAngleDeviation(NShort value)
	{
		SetParameter(NLEP_MAX_YAW_ANGLE_DEVIATION, value);
	}

	bool GetDetectMoreFaces()
	{
		return GetParameter<bool>(NLEP_DETECT_MORE_FACES);
	}

	void SetDetectMoreFaces(bool value)
	{
		SetParameter(NLEP_DETECT_MORE_FACES, value);
	}

	NInt GetFaceDetectionScaleCount()
	{
		return GetParameter<NInt>(NLEP_FACE_DETECTION_SCALE_COUNT);
	}

	void SetFaceDetectionScaleCount(NInt value)
	{
		SetParameter(NLEP_FACE_DETECTION_SCALE_COUNT, value);
	}

	NInt GetFaceRollAngleBase()
	{
		return GetParameter<NShort>(NLEP_FACE_ROLL_ANGLE_BASE);
	}

	void SetFaceRollAngleBase(NShort value)
	{
		SetParameter(NLEP_FACE_ROLL_ANGLE_BASE, value);
	}

	bool GetDetectAllFeaturePoints()
	{
		return GetParameter<bool>(NLEP_DETECT_ALL_FEATURE_POINTS);
	}

	void SetDetectAllFeaturePoints(bool value)
	{
		SetParameter(NLEP_DETECT_ALL_FEATURE_POINTS, value);
	}

	NByte GetFaceQualityThreshold()
	{
		return GetParameter<NByte>(NLEP_FACE_QUALITY_THRESHOLD);
	}

	void SetFaceQualityThreshold(NByte value)
	{
		SetParameter(NLEP_FACE_QUALITY_THRESHOLD, value);
	}

	NleTemplateSize GetTemplateSize()
	{
		return (NleTemplateSize)GetParameter<NInt>(NLEP_TEMPLATE_SIZE);
	}

	void SetTemplateSize(NleTemplateSize value)
	{
		SetParameter(NLEP_TEMPLATE_SIZE, (NInt)value);
	}

	bool GetUseLivenessCheck()
	{
		return GetParameter<bool>(NLEP_USE_LIVENESS_CHECK);
	}

	void SetUseLivenessCheck(bool value)
	{
		SetParameter(NLEP_USE_LIVENESS_CHECK, value);
	}

	NDouble GetLivenessThreshold()
	{
		return GetParameter<NDouble>(NLEP_LIVENESS_THRESHOLD);
	}

	void SetLivenessThreshold(NDouble value)
	{
		SetParameter(NLEP_LIVENESS_THRESHOLD, value);
	}

	NInt GetMaxRecordsPerTemplate()
	{
		return GetParameter<NInt>(NLEP_MAX_RECORDS_PER_TEMPLATE);
	}

	void SetMaxRecordsPerTemplate(NInt value)
	{
		SetParameter(NLEP_MAX_RECORDS_PER_TEMPLATE, value);
	}

	NInt GetMaxStreamDurationInFrames()
	{
		return GetParameter<NInt>(NLEP_MAX_STREAM_DURATION_IN_FRAMES);
	}

	void SetMaxStreamDurationInFrames(NInt value)
	{
		SetParameter(NLEP_MAX_STREAM_DURATION_IN_FRAMES, value);
	}

	void SetDetectBaseFeaturePoints(bool value)
	{
		SetParameter(NLEP_DETECT_BASE_FEATURE_POINTS, value);
	}
	bool GetDetectBaseFeaturePoints()
	{
		return GetParameter<bool>(NLEP_DETECT_BASE_FEATURE_POINTS);
	}
	void SetDetectGender(bool value)
	{
		SetParameter(NLEP_DETECT_GENDER, value);
	}
	bool GetDetectGender()
	{
		return GetParameter<bool>(NLEP_DETECT_GENDER);
	}
	void SetGenderConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_GENDER_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetGenderConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_GENDER_CONFIDENCE_THRESHOLD);
	}
	void SetDetectExpression(bool value)
	{
		SetParameter(NLEP_DETECT_EXPRESSION, value);
	}
	bool GetDetectExpression()
	{
		return GetParameter<bool>(NLEP_DETECT_EXPRESSION);
	}
	void SetExpressionConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_EXPRESSION_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetExpressionConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_EXPRESSION_CONFIDENCE_THRESHOLD);
	}
	void SetDetectGlasses(bool value)
	{
		SetParameter(NLEP_DETECT_GLASSES, value);
	}
	bool GetDetectGlasses()
	{
		return GetParameter<bool>(NLEP_DETECT_GLASSES);
	}
	void SetGlassesConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_GLASSES_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetGlassesConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_GLASSES_CONFIDENCE_THRESHOLD);
	}
	void SetDetectDarkGlasses(NByte value)
	{
		SetParameter(NLEP_DETECT_DARK_GLASSES, value);
	}
	bool GetDetectDarkGlasses()
	{
		return GetParameter<bool>(NLEP_DETECT_DARK_GLASSES);
	}
	void SetDarkGlassesConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_DARK_GLASSES_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetDarkGlassesConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_DARK_GLASSES_CONFIDENCE_THRESHOLD);
	}
	void SetDetectBlink(bool value)
	{
		SetParameter(NLEP_DETECT_BLINK, value);
	}
	bool GetDetectBlink()
	{
		return GetParameter<bool>(NLEP_DETECT_BLINK);
	}
	void SetBlinkConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_BLINK_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetBlinkConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_BLINK_CONFIDENCE_THRESHOLD);
	}
	void SetDetectMouthOpen(bool value)
	{
		SetParameter(NLEP_DETECT_MOUTH_OPEN, value);
	}
	bool GetDetectMouthOpen()
	{
		return GetParameter<bool>(NLEP_DETECT_MOUTH_OPEN);
	}
	void SetMouthOpenConfidenceThreshold(NByte value)
	{
		SetParameter(NLEP_MOUTH_OPEN_CONFIDENCE_THRESHOLD, value);
	}
	NByte GetMouthOpenConfidenceThreshold()
	{
		return GetParameter<NByte>(NLEP_MOUTH_OPEN_CONFIDENCE_THRESHOLD);
	}

	N_DECLARE_OBJECT_CLASS(NLExtractor, NObject)
};

}}

#endif // !NL_EXTRACTOR_HPP_INCLUDED
