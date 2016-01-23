#ifndef NE_SEGMENTER_HPP_INCLUDED
#define NE_SEGMENTER_HPP_INCLUDED

#include <NCore.hpp>
#include <NImage.hpp>
#include <NGeometry.hpp>
#include <NBiometrics.hpp>
#include <NESegmenterParams.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
#include <NESegmenter.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{

class N_CLASS(NESegmenterAttributes) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NESegmenterAttributes, NObject)

private:
	N_CLASS(NESegmenterAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	NByte GetGrayLevelSpread() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetGrayLevelSpread(GetHandle(), &value));
		return value;
	}

	NByte GetIrisSize() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetIrisSize(GetHandle(), &value));
		return value;
	}

	NByte GetPupilIrisRatio() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetPupilIrisRatio(GetHandle(), &value));
		return value;
	}

	NByte GetUsableIrisArea() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetUsableIrisArea(GetHandle(), &value));
		return value;
	}

	NByte GetIrisScleraContrast() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetIrisScleraContrast(GetHandle(), &value));
		return value;
	}

	NByte GetIrisPupilContrast() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetIrisPupilContrast(GetHandle(), &value));
		return value;
	}

	NByte GetIrisScleraBoundaryShape() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetIrisScleraBoundaryShape(GetHandle(), &value));
		return value;
	}

	NByte GetIrisPupilBoundaryShape() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetIrisPupilBoundaryShape(GetHandle(), &value));
		return value;
	}

	NByte GetMargin() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetMargin(GetHandle(), &value));
		return value;
	}

	NByte GetSharpness() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetSharpness(GetHandle(), &value));
		return value;
	}

	NByte SignalToNoiseRatio() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetSignalToNoiseRatio(GetHandle(), &value));
		return value;
	}

	NByte GetInterlace() const
	{
		NByte value;
		NCheck(NESegmenterAttributesGetInterlace(GetHandle(), &value));
		return value;
	}
};

class N_CLASS(NESegmenter) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NESegmenter, NObject)

private:
	static HNESegmenter Create()
	{
		HNESegmenter handle;
		NCheck(NESegmenterCreate(&handle));
		return handle;
	}

	N_CLASS(NESegmenter)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(NESegmenter)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(NESegmenter);
	}

	::Neurotec::Images::N_CLASS(NGrayscaleImage) * Process(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NeeImageKind resultImageKind,
		N_CLASS(NESegmenterAttributes) * * ppAttributes, NByte * pQuality, NeeExtractionStatus * pStatus)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNGrayscaleImage hResultImage;
		HNESegmenterAttributes hAttributes = NULL;
		NByte quality = 0;
		NCheck(NESegmenterProcess(GetHandle(), pImage->GetHandle(), resultImageKind, ppAttributes ? &hAttributes : NULL, pQuality ? &quality : NULL, pStatus, &hResultImage));
		::Neurotec::Images::N_CLASS(NGrayscaleImage) * pResultImage = NULL;
		N_CLASS(NESegmenterAttributes) * pAttributes = NULL;
		try
		{
			if (ppAttributes) pAttributes = FromHandle<N_CLASS(NESegmenterAttributes)>(hAttributes);
			pResultImage = FromHandle< ::Neurotec::Images::N_CLASS(NGrayscaleImage)>(hResultImage);
			if (ppAttributes) *ppAttributes = pAttributes;
			if (pQuality) *pQuality = quality;
			return pResultImage;
		}
		catch (...)
		{
			UnrefOrDelete(hResultImage, pResultImage);
			UnrefOrDelete(hAttributes, pAttributes);
			throw;
		}
	}

	::Neurotec::Images::N_CLASS(NGrayscaleImage) * Process(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NeeImageKind resultImageKind, NByte * pQuality, NeeExtractionStatus * pStatus)
	{
		return Process(pImage, resultImageKind, NULL, pQuality, pStatus);
	}

	::Neurotec::Images::N_CLASS(NGrayscaleImage) * Process(::Neurotec::Images::N_CLASS(NGrayscaleImage) * pImage, NeeImageKind resultImageKind, NeeExtractionStatus * pStatus)
	{
		return Process(pImage, resultImageKind, NULL, NULL, pStatus);
	}

	NDouble GetHorizontalMargin() const
	{
		return GetParameter<NDouble>(NESP_HORIZONTAL_MARGIN);
	}

	void SetHorizontalMargin(NDouble value)
	{
		SetParameter(NESP_HORIZONTAL_MARGIN, value);
	}

	NDouble GetVerticalMargin() const
	{
		return GetParameter<NDouble>(NESP_VERTICAL_MARGIN);
	}

	void SetVerticalMargin(NDouble value)
	{
		SetParameter(NESP_VERTICAL_MARGIN, value);
	}

	NByte GetUpperEyelidMaskValue() const
	{
		return GetParameter<NByte>(NESP_UPPER_EYELID_MASK_VALUE);
	}

	void SetUpperEyelidMaskValue(NByte value)
	{
		SetParameter(NESP_UPPER_EYELID_MASK_VALUE, value);
	}

	NByte GetScleraMaskValue() const
	{
		return GetParameter<NByte>(NESP_SCLERA_MASK_VALUE);
	}

	void SetScleraMaskValue(NByte value)
	{
		SetParameter(NESP_SCLERA_MASK_VALUE, value);
	}

	NByte GetLowerEyelidMaskValue() const
	{
		return GetParameter<NByte>(NESP_LOWER_EYELID_MASK_VALUE);
	}

	void SetLowerEyelidMaskValue(NByte value)
	{
		SetParameter(NESP_LOWER_EYELID_MASK_VALUE, value);
	}

	NByte GetQualityThreshold() const
	{
		return GetParameter<NByte>(NESP_QUALITY_THRESHOLD);
	}

	void SetQualityThreshold(NByte value)
	{
		SetParameter(NESP_QUALITY_THRESHOLD, value);
	}

	NByte GetInterlaceThreshold() const
	{
		return GetParameter<NByte>(NESP_INTERLACE_THRESHOLD);
	}

	void SetInterlaceThreshold(NByte value)
	{
		SetParameter(NESP_INTERLACE_THRESHOLD, value);
	}
};

}}}

#endif // !NE_SEGMENTER_HPP_INCLUDED
