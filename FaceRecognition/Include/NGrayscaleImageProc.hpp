#ifndef N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED
#define N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED

#include <NGrayscaleImage.hpp>
#include <NGeometry.hpp>
namespace Neurotec { namespace Images { namespace Processing
{
using ::Neurotec::Geometry::NInterpolationMode;
#include <NGrayscaleImageProc.h>
}}}

namespace Neurotec { namespace Images { namespace Processing
{

class N_CLASS(Ngip)
{
	N_DECLARE_STATIC_OBJECT_CLASS(Ngip)

public:
	static N_CLASS(NGrayscaleImage) * Invert(N_CLASS(NGrayscaleImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNGrayscaleImage hResultImage;
		NCheck(NgipInvert(pImage->GetHandle(), &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void Invert(N_CLASS(NGrayscaleImage) * pImage, N_CLASS(NGrayscaleImage) * pDstImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NgipInvertDst(pImage->GetHandle(), pDstImage->GetHandle()));
	}

	static void InvertSame(N_CLASS(NGrayscaleImage) * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NgipInvertSame(pImage->GetHandle()));
	}

	static N_CLASS(NGrayscaleImage) * Scale(N_CLASS(NGrayscaleImage) * pSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
		NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNGrayscaleImage hResultImage;
		NCheck(NgipScale(pSrcImage->GetHandle(), srcLeft, srcTop, srcWidth, srcHeight, resultWidth, resultHeight, interpolationMode, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static N_CLASS(NGrayscaleImage) * Scale(N_CLASS(NGrayscaleImage) * pSrcImage, NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		HNGrayscaleImage hResultImage;
		NCheck(NgipScale(pSrcImage->GetHandle(), 0, 0, pSrcImage->GetWidth(), pSrcImage->GetHeight(), resultWidth, resultHeight, interpolationMode, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void Scale(N_CLASS(NGrayscaleImage) * pSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
		N_CLASS(NGrayscaleImage) * pDstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NgipScaleDst(pSrcImage->GetHandle(), srcLeft, srcTop, srcWidth, srcHeight, pDstImage->GetHandle(), dstLeft, dstTop, dstWidth, dstHeight, interpolationMode));
	}

	static void Scale(N_CLASS(NGrayscaleImage) * pSrcImage, N_CLASS(NGrayscaleImage) * pDstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode)
	{
		if (!pSrcImage) NThrowArgumentNullException(N_T("pSrcImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NgipScaleDst(pSrcImage->GetHandle(), 0, 0, pSrcImage->GetWidth(), pSrcImage->GetHeight(), pDstImage->GetHandle(), dstLeft, dstTop, dstWidth, dstHeight, interpolationMode));
	}

	static N_CLASS(NGrayscaleImage) * AdjustBrightnessContrast(N_CLASS(NGrayscaleImage) * pImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		HNGrayscaleImage hResultImage;
		NCheck(NgipAdjustBrightnessContrast(pImage->GetHandle(), brightness, contrast, &hResultImage));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hResultImage);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hResultImage);
			throw;
		}
	}

	static void AdjustBrightnessContrast(N_CLASS(NGrayscaleImage) * pImage, N_CLASS(NGrayscaleImage) * pDstImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		if (!pDstImage) NThrowArgumentNullException(N_T("pDstImage"));
		NCheck(NgipAdjustBrightnessContrastDst(pImage->GetHandle(), pDstImage->GetHandle(), brightness, contrast));
	}

	static void AdjustBrightnessContrastSame(N_CLASS(NGrayscaleImage) * pImage, NDouble brightness, NDouble contrast)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		NCheck(NgipAdjustBrightnessContrastSame(pImage->GetHandle(), brightness, contrast));
	}

	static N_CLASS(NGrayscaleImage) * IFFT(N_CLASS(NImage) * pSrcReal, N_CLASS(NImage) * pSrcImaginary)
	{
		if (!pSrcReal) NThrowArgumentNullException(N_T("pSrcReal"));
		if (!pSrcImaginary) NThrowArgumentNullException(N_T("pSrcImaginary"));
		HNGrayscaleImage hDst;
		NCheck(NgipIFFT(pSrcReal->GetHandle(), pSrcImaginary->GetHandle(), &hDst));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hDst);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hDst);
			throw;
		}
	}

	static void FFT(N_CLASS(NGrayscaleImage) * pSrc, N_CLASS(NImage) * * ppDstReal, N_CLASS(NImage) * * ppDstImaginary)
	{
		if (!pSrc) NThrowArgumentNullException(N_T("pSrc"));
		if (!ppDstReal) NThrowArgumentNullException(N_T("ppDstReal"));
		if (!ppDstImaginary) NThrowArgumentNullException(N_T("ppDstImaginary"));
		HNImage hDstReal;
		HNImage hDstImaginary;
		NCheck(NgipFFT(pSrc->GetHandle(), &hDstReal, &hDstImaginary));
		N_CLASS(NImage) * pDstReal = NULL;
		N_CLASS(NImage) * pDstImaginary = NULL;
		try
		{
			pDstReal = N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(hDstReal);
			pDstImaginary = N_CLASS(NObject)::FromHandle<N_CLASS(NImage)>(hDstImaginary);
			*ppDstReal = pDstReal;
			*ppDstImaginary = pDstImaginary;
		}
		catch (...)
		{
			N_CLASS(NObject)::UnrefOrDelete(hDstReal, pDstReal);
			N_CLASS(NObject)::UnrefOrDelete(hDstImaginary, pDstImaginary);
			throw;
		}
	}

	static void ApplyMaskToSpectrum(N_CLASS(NImage) * pSrcReal, N_CLASS(NImage) * pSrcImaginary, N_CLASS(NGrayscaleImage) * pMask)
	{
		if (!pSrcReal) NThrowArgumentNullException(N_T("pSrcReal"));
		if (!pSrcImaginary) NThrowArgumentNullException(N_T("pSrcImaginary"));
		if (!pMask) NThrowArgumentNullException(N_T("pMask"));
		NCheck(NgipApplyMaskToSpectrum(pSrcReal->GetHandle(), pSrcImaginary->GetHandle(), pMask->GetHandle()));
	}

	static N_CLASS(NGrayscaleImage) * CreateMagnitudeFromSpectrum(N_CLASS(NImage) * pSrcReal, N_CLASS(NImage) * pSrcImaginary)
	{
		if (!pSrcReal) NThrowArgumentNullException(N_T("pSrcReal"));
		if (!pSrcImaginary) NThrowArgumentNullException(N_T("pSrcImaginary"));
		HNGrayscaleImage hMagnitude;
		NCheck(NgipCreateMagnitudeFromSpectrum(pSrcReal->GetHandle(), pSrcImaginary->GetHandle(), &hMagnitude));
		try
		{
			return N_CLASS(NObject)::FromHandle<N_CLASS(NGrayscaleImage)>(hMagnitude);
		}
		catch (...)
		{
			N_CLASS(NObject)::Unref(hMagnitude);
			throw;
		}
	}

	static void FFTGetOptimalSize(N_CLASS(NImage) * pSrc, NUInt * pWidth, NUInt * pHeight)
	{
		if (!pSrc) NThrowArgumentNullException(N_T("pSrc"));
		NCheck(NgipFFTGetOptimalSize(pSrc->GetHandle(), pWidth, pHeight));
	}
};

}}}

#endif // !N_GRAYSCALE_IMAGE_PROC_HPP_INCLUDED
