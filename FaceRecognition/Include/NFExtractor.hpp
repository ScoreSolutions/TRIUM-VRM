#ifndef NF_EXTRACTOR_HPP_INCLUDED
#define NF_EXTRACTOR_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NFRecord.hpp>
#include <NFExtractorParams.hpp>
namespace Neurotec { namespace Biometrics
{
using Neurotec::Images::HNGrayscaleImage;
#include <NFExtractor.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NFExtractor) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NFExtractor, NObject)

private:
	static HNFExtractor Create(bool isPalm)
	{
		HNFExtractor handle;
		NCheck(NfeCreateEx(isPalm, &handle));
		return handle;
	}

	N_CLASS(NFExtractor)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NfeReturnedImageNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NfeReturnedImage), true, true);
	}

	static N_CLASS(NType) * NfeTemplateSizeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NfeTemplateSize), true, true);
	}

	static N_CLASS(NType) * NfeExtractionStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NfeExtractionStatus), true, true);
	}

	explicit N_CLASS(NFExtractor)(bool isPalm = false)
		: N_CLASS(NObject)(Create(isPalm), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NFExtractor);
	}

	N_CLASS(NFRecord) * Extract(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NFPosition position, NFImpressionType impressionType, NfeExtractionStatus * pExtractionStatus)
	{
		if (pImage == NULL)
			NThrowArgumentNullException(N_T("pImage"));
		HNFRecord hRecord;
		NCheck(NfeExtract(GetHandle(), pImage->GetHandle(), position, impressionType, pExtractionStatus, &hRecord));
		try
		{
			return FromHandle<N_CLASS(NFRecord)>(hRecord);
		}
		catch (...)
		{
			Unref(hRecord);
			throw;
		}
	}

	void UpdateTemplate(Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, N_CLASS(NFRecord) * pRecord)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pRecord) NThrowArgumentNullException(N_T("pRecord"));
		NCheck(NfeUpdateTemplate(GetHandle(), pImage->GetHandle(), pRecord->GetHandle()));
	}

	N_CLASS(NFRecord) * Generalize(NInt recordCount, N_CLASS(NFRecord) * const * arpRecords, NfeExtractionStatus * pStatus, NInt * pBaseTemplateIndex)
	{
		N_CLASS(NObjectArray)<N_CLASS(NFRecord)> records(arpRecords, recordCount);
		HNFRecord hRecord;
		NCheck(NfeGeneralizeEx(GetHandle(), records.GetCount(), records.GetPtr(), pStatus, pBaseTemplateIndex, &hRecord));
		try
		{
			return FromHandle<N_CLASS(NFRecord)>(hRecord);
		}
		catch (...)
		{
			Unref(hRecord);
			throw;
		}
	}

	NfeTemplateSize GetTemplateSize()
	{
		return (NfeTemplateSize)GetParameter<NInt>(NFEP_TEMPLATE_SIZE);
	}

	void SetTemplateSize(NfeTemplateSize value)
	{
		SetParameter(NFEP_TEMPLATE_SIZE, (NInt)value);
	}

	bool GetExtractQualities()
	{
		return GetParameter<bool>(NFEP_EXTRACT_QUALITIES);
	}

	void SetExtractQualities(bool value)
	{
		SetParameter(NFEP_EXTRACT_QUALITIES, value);
	}

	bool GetExtractCurvatures()
	{
		return GetParameter<bool>(NFEP_EXTRACT_CURVATURES);
	}

	void SetExtractCurvatures(bool value)
	{
		SetParameter(NFEP_EXTRACT_CURVATURES, value);
	}

	bool GetExtractGs()
	{
		return GetParameter<bool>(NFEP_EXTRACT_GS);
	}

	void SetExtractGs(bool value)
	{
		SetParameter(NFEP_EXTRACT_GS, value);
	}

	NInt GetMinMinutiaCount()
	{
		return GetParameter<NInt>(NFEP_MIN_MINUTIA_COUNT);
	}

	void SetMinMinutiaCount(NInt value)
	{
		SetParameter(NFEP_MIN_MINUTIA_COUNT, value);
	}

	NFRidgeCountsType GetExtractedRidgeCounts()
	{
		return (NFRidgeCountsType)GetParameter<NInt>(NFEP_EXTRACTED_RIDGE_COUNTS);
	}

	void SetExtractedRidgeCounts(NFRidgeCountsType value)
	{
		SetParameter(NFEP_EXTRACTED_RIDGE_COUNTS, (NInt)value);
	}

	NfeReturnedImage GetReturnedImage()
	{
		return (NfeReturnedImage)GetParameter<NInt>(NFEP_RETURNED_IMAGE);
	}

	void SetReturnedImage(NfeReturnedImage value)
	{
		SetParameter(NFEP_RETURNED_IMAGE, (NInt)value);
	}

	NUInt GetMode()
	{
		return GetParameter<NUInt>(NFEP_MODE);
	}

	void SetMode(NUInt value)
	{
		SetParameter(NFEP_MODE, value);
	}

	bool GetUseQuality()
	{
		return GetParameter<bool>(NFEP_USE_QUALITY);
	}

	void SetUseQuality(bool value)
	{
		SetParameter(NFEP_USE_QUALITY, value);
	}

	NByte GetQualityThreshold()
	{
		return GetParameter<NByte>(NFEP_QUALITY_THRESHOLD);
	}

	void SetQualityThreshold(NByte value)
	{
		SetParameter(NFEP_QUALITY_THRESHOLD, value);
	}

	NInt GetGeneralizationThreshold()
	{
		return GetParameter<NInt>(NFEP_GENERALIZATION_THRESHOLD);
	}

	void SetGeneralizationThreshold(NInt value)
	{
		SetParameter(NFEP_GENERALIZATION_THRESHOLD, value);
	}

	NByte GetGeneralizationMaximalRotation()
	{
		return GetParameter<NByte>(NFEP_GENERALIZATION_MAXIMAL_ROTATION);
	}

	void SetGeneralizationMaximalRotation(NByte value)
	{
		SetParameter(NFEP_GENERALIZATION_MAXIMAL_ROTATION, value);
	}

	NInt GetGeneralizationMinMinutiaCount()
	{
		return GetParameter<NInt>(NFEP_GENERALIZATION_MIN_MINUTIA_COUNT);
	}

	void SetGeneralizationMinMinutiaCount(NInt value)
	{
		SetParameter(NFEP_GENERALIZATION_MIN_MINUTIA_COUNT, value);
	}
};

}}

#endif // !NF_EXTRACTOR_HPP_INCLUDED
