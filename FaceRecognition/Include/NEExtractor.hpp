#ifndef NE_EXTRACTOR_HPP_INCLUDED
#define NE_EXTRACTOR_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NGeometry.hpp>
#include <NERecord.hpp>
#include <NEExtractorParams.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Images::HNGrayscaleImage;
using ::Neurotec::Geometry::NPoint_;
#include <NEExtractor.h>
}}

namespace Neurotec { namespace Biometrics
{

class N_CLASS(NEExtractor) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NEExtractor, NObject)

private:
	static HNEExtractor Create()
	{
		HNEExtractor handle;
		NCheck(NeeCreate(&handle));
		return handle;
	}

	N_CLASS(NEExtractor)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	static N_CLASS(NType) * NeeTemplateSizeNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NeeTemplateSize), true, true);
	}

	static N_CLASS(NType) * NeeExtractionStatusNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NeeExtractionStatus), true, true);
	}

	static N_CLASS(NType) * NeeImageKindNativeTypeOf()
	{
		return N_CLASS(NObject)::GetObject<N_CLASS(NType)>(N_TYPE_OF(NeeImageKind), true, true);
	}

	static N_CLASS(NERecord) * Compress(N_CLASS(NERecord) * pSrcRecord, NeeTemplateSize dstTemplateSize)
	{
		if (!pSrcRecord) NThrowArgumentNullException(N_T("pSrcRecord"));
		HNERecord hDstRecord;
		NCheck(NeeCompress(pSrcRecord->GetHandle(), dstTemplateSize, &hDstRecord));
		try
		{
			return FromHandle<N_CLASS(NERecord)>(hDstRecord);
		}
		catch (...)
		{
			Unref(hDstRecord);
			throw;
		}
	}

	N_CLASS(NEExtractor)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NEExtractor);
	}

	N_CLASS(NERecord) * Extract(const Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NEPosition position, NeeSegmentationDetails * pDetails, NeeExtractionStatus * pExtractionStatus)
	{
		HNERecord hTemplate;
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NeeExtract(GetHandle(), pImage->GetHandle(), position, pDetails, pExtractionStatus, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NERecord)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	N_CLASS(NERecord) * Extract(const Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NEPosition position, NeeExtractionStatus * pExtractionStatus)
	{
		return Extract(pImage, position, NULL, pExtractionStatus);
	}

	N_CLASS(NERecord) * Extract(const Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NeeImageKind imageKind, NEPosition position, NeeSegmentationDetails * pDetails, NeeExtractionStatus * pExtractionStatus)
	{
		HNERecord hTemplate;
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NeeExtractEx(GetHandle(), pImage->GetHandle(), imageKind, position, pDetails, pExtractionStatus, &hTemplate));
		try
		{
			return FromHandle<N_CLASS(NERecord)>(hTemplate);
		}
		catch (...)
		{
			Unref(hTemplate);
			throw;
		}
	}

	N_CLASS(NERecord) * Extract(const Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NeeImageKind imageKind, NEPosition position, NeeExtractionStatus * pExtractionStatus)
	{
		return Extract(pImage, imageKind, position, NULL, pExtractionStatus);
	}

	bool GetDeinterlace()
	{
		return GetParameter<bool>(NEEP_DEINTERLACE);
	}

	void SetDeinterlace(bool value)
	{
		SetParameter(NEEP_DEINTERLACE, value);
	}

	NInt GetInnerBoundaryFrom()
	{
		return GetParameter<NInt>(NEEP_INNER_BOUNDARY_FROM);
	}

	void SetInnerBoundaryFrom(NInt value)
	{
		SetParameter(NEEP_INNER_BOUNDARY_FROM, value);
	}

	NInt GetInnerBoundaryTo()
	{
		return GetParameter<NInt>(NEEP_INNER_BOUNDARY_TO);
	}

	void SetInnerBoundaryTo(NInt value)
	{
		SetParameter(NEEP_INNER_BOUNDARY_TO, value);
	}

	NInt GetOuterBoundaryFrom()
	{
		return GetParameter<NInt>(NEEP_OUTER_BOUNDARY_FROM);
	}

	void SetOuterBoundaryFrom(NInt value)
	{
		SetParameter(NEEP_OUTER_BOUNDARY_FROM, value);
	}

	NInt GetOuterBoundaryTo()
	{
		return GetParameter<NInt>(NEEP_OUTER_BOUNDARY_TO);
	}

	void SetOuterBoundaryTo(NInt value)
	{
		SetParameter(NEEP_OUTER_BOUNDARY_TO, value);
	}

	bool GetUseFlexibleBoundaryModel()
	{
		return GetParameter<bool>(NEEP_USE_FLEXIBLE_BOUNDARY_MODEL);
	}

	void SetUseFlexibleBoundaryModel(bool value)
	{
		SetParameter(NEEP_USE_FLEXIBLE_BOUNDARY_MODEL, value);
	}

	NeeTemplateSize GetTemplateSize()
	{
		return (NeeTemplateSize)GetParameter<NInt>(NEEP_TEMPLATE_SIZE);
	}

	void SetTemplateSize(NeeTemplateSize value)
	{
		SetParameter(NEEP_TEMPLATE_SIZE, (NInt)value);
	}
};

}}

#endif // !NE_EXTRACTOR_HPP_INCLUDED
