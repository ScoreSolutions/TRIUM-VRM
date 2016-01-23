#ifndef NTFI_HPP_INCLUDED
#define NTFI_HPP_INCLUDED

#include <NCore.hpp>
#include <NImage.hpp>
#include <NGeometry.hpp>
#include <NBiometrics.hpp>
#include <NtfiParams.hpp>
namespace Neurotec { namespace Biometrics { namespace Tools
{
using ::Neurotec::Images::HNImage;
using ::Neurotec::Geometry::NPoint_;
#include <Ntfi.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Tools
{

class N_CLASS(NtfiAttributes) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(NtfiAttributes, NObject)

	N_CLASS(NtfiAttributes)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	NDouble GetSharpness() const
	{
		NDouble value;
		NCheck(NtfiAttributesGetSharpness(GetHandle(), &value));
		return value;
	}

	NDouble GetBackgroundUniformity() const
	{
		NDouble value;
		NCheck(NtfiAttributesGetBackgroundUniformity(GetHandle(), &value));
		return value;
	}

	NDouble GetGrayscaleDensity() const
	{
		NDouble value;
		NCheck(NtfiAttributesGetGrayscaleDensity(GetHandle(), &value));
		return value;
	}
};

class N_CLASS(Ntfi) : public N_CLASS(NObject)
{
	N_DECLARE_OBJECT_CLASS(Ntfi, NObject)

private:
	static HNtfi Create()
	{
		HNtfi handle;
		NCheck(NtfiCreate(&handle));
		return handle;
	}

	N_CLASS(Ntfi)(HNObject handle, bool claimHandle)
		: N_CLASS(NObject)(handle, claimHandle)
	{
	}

public:
	N_CLASS(Ntfi)()
		: N_CLASS(NObject)(Create(), true)
	{
		N_OBJECT_CLASS_REGISTER_TYPE(Ntfi);
	}

	::Neurotec::Images::N_CLASS(NImage) * CreateTokenFaceImage(::Neurotec::Images::N_CLASS(NImage) * pImage, const ::Neurotec::Geometry::N_CLASS(NPoint) & firstEye, const ::Neurotec::Geometry::N_CLASS(NPoint) & secondEye)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNImage hTokenFaceImage;
		NCheck(NtfiCreateTokenFaceImageEx(GetHandle(), pImage->GetHandle(), &firstEye, &secondEye, &hTokenFaceImage));
		try
		{
			return FromHandle< ::Neurotec::Images::N_CLASS(NImage)>(hTokenFaceImage);
		}
		catch (...)
		{
			Unref(hTokenFaceImage);
			throw;
		}
	}

	NDouble TestTokenFaceImage(::Neurotec::Images::N_CLASS(NImage) * pTokenFaceImage, N_CLASS(NtfiAttributes) * * ppNtfiAttributes)
	{
		if (!pTokenFaceImage) NThrowArgumentNullException(N_T("pTokenFaceImage"));
		if (!ppNtfiAttributes) NThrowArgumentNullException(N_T("ppNtfiAttributes"));
		HNtfiAttributes hNtfiAttributes;
		NDouble score;
		NCheck(NtfiTestTokenFaceImage(GetHandle(), pTokenFaceImage->GetHandle(), &hNtfiAttributes, &score));
		try
		{
			*ppNtfiAttributes = FromHandle<N_CLASS(NtfiAttributes)>(hNtfiAttributes);
			return score;
		}
		catch (...)
		{
			Unref(hNtfiAttributes);
			throw;
		}
	}

	NInt GetTokenFaceImageWidth() const
	{
		return GetParameter<NInt>(NTFIP_TOKEN_FACE_IMAGE_WIDTH);
	}

	void SetTokenFaceImageWidth(NInt value)
	{
		SetParameter(NTFIP_TOKEN_FACE_IMAGE_WIDTH, value);
	}

	bool GetUseLightnessNormalization() const
	{
		return GetParameter<bool>(NTFIP_USE_LIGHTNESS_NORMALIZATION);
	}

	void SetUseLightnessNormalization(bool value)
	{
		SetParameter(NTFIP_USE_LIGHTNESS_NORMALIZATION, value);
	}

	NDouble GetQualityThreshold() const
	{
		return GetParameter<NDouble>(NTFIP_QUALITY_THRESHOLD);
	}

	void SetQualityThreshold(NDouble value)
	{
		SetParameter(NTFIP_QUALITY_THRESHOLD, value);
	}

	NDouble GetSharpnessThreshold() const
	{
		return GetParameter<NDouble>(NTFIP_SHARPNESS_THRESHOLD);
	}

	void SetSharpnessThreshold(NDouble value)
	{
		SetParameter(NTFIP_SHARPNESS_THRESHOLD, value);
	}

	NDouble GetBackgroundUniformityThreshold() const
	{
		return GetParameter<NDouble>(NTFIP_BACKGROUND_UNIFORMITY_THRESHOLD);
	}

	void SetBackgroundUniformityThreshold(NDouble value)
	{
		SetParameter(NTFIP_BACKGROUND_UNIFORMITY_THRESHOLD, value);
	}

	NDouble GetGrayscaleDensityThreshold() const
	{
		return GetParameter<NDouble>(NTFIP_GRAYSCALE_DENSITY_THRESHOLD);
	}

	void SetGrayscaleDensityThreshold(NDouble value)
	{
		SetParameter(NTFIP_GRAYSCALE_DENSITY_THRESHOLD, value);
	}
};

}}}

#endif // !NTFI_HPP_INCLUDED
