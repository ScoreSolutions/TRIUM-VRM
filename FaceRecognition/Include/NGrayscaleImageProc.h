#ifndef N_GRAYSCALE_IMAGE_PROC_H_INCLUDED
#define N_GRAYSCALE_IMAGE_PROC_H_INCLUDED

#include <NGrayscaleImage.h>
#include <NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(Ngip)

// Invert

NResult N_API NgipInvert(HNGrayscaleImage hImage, HNGrayscaleImage * pHResultImage);
NResult N_API NgipInvertDst(HNGrayscaleImage hImage, HNGrayscaleImage hDstImage);
NResult N_API NgipInvertSame(HNGrayscaleImage hImage);

// Scale

NResult N_API NgipScale(HNGrayscaleImage hSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
	NUInt resultWidth, NUInt resultHeight, NInterpolationMode interpolationMode, HNGrayscaleImage * pHResultImage);
NResult N_API NgipScaleDst(HNGrayscaleImage hSrcImage, NUInt srcLeft, NUInt srcTop, NUInt srcWidth, NUInt srcHeight,
	HNGrayscaleImage hDstImage, NUInt dstLeft, NUInt dstTop, NUInt dstWidth, NUInt dstHeight, NInterpolationMode interpolationMode);

// Brightness & Contrast

NResult N_API NgipAdjustBrightnessContrast(HNGrayscaleImage hImage, NDouble brightness, NDouble contrast, HNGrayscaleImage * pHResultImage);
NResult N_API NgipAdjustBrightnessContrastDst(HNGrayscaleImage hImage, HNGrayscaleImage hDstImage, NDouble brightness, NDouble contrast);
NResult N_API NgipAdjustBrightnessContrastSame(HNGrayscaleImage hImage, NDouble brightness, NDouble contrast);

// FFT

NResult N_API NgipIFFT(HNImage hSrcReal, HNImage hSrcImaginary, HNGrayscaleImage * pHDst);
NResult N_API NgipFFT(HNGrayscaleImage hSrc, HNImage * pHDstReal, HNImage * pHDstImaginary);
NResult N_API NgipApplyMaskToSpectrum(HNImage hSrcReal, HNImage hSrcImaginary, HNGrayscaleImage hMask);
NResult N_API NgipCreateMagnitudeFromSpectrum(HNImage hSrcReal, HNImage hSrcImaginary, HNGrayscaleImage * pHMagnitude);
NResult N_API NgipFFTGetOptimalSize(HNImage hSrc, NUInt * pWidth, NUInt * pHeight);

#ifdef N_CPP
}
#endif

#endif // !N_GRAYSCALE_IMAGE_PROC_H_INCLUDED
