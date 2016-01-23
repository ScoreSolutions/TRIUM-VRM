#ifndef N_RGB_IMAGE_PROC_HPP_INCLUDED
#define N_RGB_IMAGE_PROC_HPP_INCLUDED

#include <NRgbImage.hpp>
namespace Neurotec { namespace Images { namespace Processing
{
#include <NRgbImageProc.h>
}}}

namespace Neurotec { namespace Images { namespace Processing
{

class N_CLASS(Nrgbip)
{
	N_DECLARE_STATIC_OBJECT_CLASS(Nrgbip)

public:
	static N_CLASS(NRgbImage) * Invert(N_CLASS(NRgbImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNRgbImage hResultImage;
		NCheck(NrgbipInvert(pImage->GetHandle(), &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void Invert(N_CLASS(NRgbImage) * pImage, N_CLASS(NRgbImage) * pDstImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipInvertDst(pImage->GetHandle(), pDstImage->GetHandle()));
	}

	static void InvertSame(N_CLASS(NRgbImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NrgbipInvertSame(pImage->GetHandle()));
	}

	static N_CLASS(NRgbImage) * AdjustBrightnessContrast(N_CLASS(NRgbImage) * pImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNRgbImage hResultImage;
		NCheck(NrgbipAdjustBrightnessContrast(pImage->GetHandle(), brightness, contrast, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AdjustBrightnessContrast(N_CLASS(NRgbImage) * pImage, N_CLASS(NRgbImage) * pDstImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipAdjustBrightnessContrastDst(pImage->GetHandle(), pDstImage->GetHandle(), brightness, contrast));
	}

	static void AdjustBrightnessContrastSame(N_CLASS(NRgbImage) * pImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NrgbipAdjustBrightnessContrastSame(pImage->GetHandle(), brightness, contrast));
	}

	static N_CLASS(NRgbImage) * AdjustBrightnessContrast(N_CLASS(NRgbImage) * pImage,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNRgbImage hResultImage;
		NCheck(NrgbipAdjustChannelsBrightnessContrast(pImage->GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AdjustBrightnessContrast(N_CLASS(NRgbImage) * pImage, N_CLASS(NRgbImage) * pDstImage,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipAdjustChannelsBrightnessContrastDst(pImage->GetHandle(), pDstImage->GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast));
	}

	static void AdjustBrightnessContrastSame(N_CLASS(NRgbImage) * pImage,
		NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NrgbipAdjustChannelsBrightnessContrastSame(pImage->GetHandle(), redBrightness, redContrast, greenBrightness, greenContrast, blueBrightness, blueContrast));
	}

	static N_CLASS(NRgbImage) * ColorMatrixTransform(N_CLASS(NRgbImage) * pImage, NDouble * pColorMatrix)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNRgbImage hResultImage;
		NCheck(NrgbipColorMatrixTransform(pImage->GetHandle(), pColorMatrix, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void ColorMatrixTransform(N_CLASS(NRgbImage) * pImage, N_CLASS(NRgbImage) * pDstImage, NDouble * pColorMatrix)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipColorMatrixTransformDst(pImage->GetHandle(), pDstImage->GetHandle(), pColorMatrix));
	}

	static void ColorMatrixTransformSame(N_CLASS(NRgbImage) * pImage, NDouble * pColorMatrix)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NrgbipColorMatrixTransformSame(pImage->GetHandle(), pColorMatrix));
	}

	static N_CLASS(NRgbImage) * AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble alpha)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		HNRgbImage hResultImage;
		NCheck(NrgbipAlphaBlend(pImageA->GetHandle(), pImageB->GetHandle(), alpha, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble alpha, N_CLASS(NRgbImage) * pDstImage)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipAlphaBlendDst(pImageA->GetHandle(), pImageB->GetHandle(), pDstImage->GetHandle(), alpha));
	}

	static void AlphaBlendSame(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble alpha)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		NCheck(NrgbipAlphaBlendSame(pImageA->GetHandle(), pImageB->GetHandle(), alpha));
	}

	static N_CLASS(NRgbImage) * AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble r, NDouble g, NDouble b, NDouble a)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		HNRgbImage hResultImage;
		NCheck(NrgbipAlphaBlendColor(pImageA->GetHandle(), pImageB->GetHandle(), r, g, b, a, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble r, NDouble g, NDouble b, NDouble a, N_CLASS(NRgbImage) * pDstImage)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipAlphaBlendColorDst(pImageA->GetHandle(), pImageB->GetHandle(), pDstImage->GetHandle(), r, g, b, a));
	}

	static void AlphaBlendSame(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble r, NDouble g, NDouble b, NDouble a)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		NCheck(NrgbipAlphaBlendColorSame(pImageA->GetHandle(), pImageB->GetHandle(), r, g, b, a));
	}

	static N_CLASS(NRgbImage) * AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble * pColorMatrix)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		HNRgbImage hResultImage;
		NCheck(NrgbipAlphaBlendColorMatrix(pImageA->GetHandle(), pImageB->GetHandle(), pColorMatrix, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NRgbImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AlphaBlend(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble * pColorMatrix, N_CLASS(NRgbImage) * pDstImage)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NrgbipAlphaBlendColorMatrixDst(pImageA->GetHandle(), pImageB->GetHandle(), pDstImage->GetHandle(), pColorMatrix));
	}

	static void AlphaBlendSame(N_CLASS(NRgbImage) * pImageA, N_CLASS(NImage) * pImageB, NDouble * pColorMatrix)
	{
		if (!pImageA) NThrowArgumentNullException(N_T("pImageA"));
		if (!pImageB) NThrowArgumentNullException(N_T("pImageB"));
		NCheck(NrgbipAlphaBlendColorMatrixSame(pImageA->GetHandle(), pImageB->GetHandle(), pColorMatrix));
	}
};

}}}

#endif // !N_RGB_IMAGE_PROC_HPP_INCLUDED
