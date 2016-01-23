#ifndef N_RGB_IMAGE_PROC_H_INCLUDED
#define N_RGB_IMAGE_PROC_H_INCLUDED

#include <NRgbImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_STATIC_OBJECT_TYPE(Nrgbip)

// Invert

NResult N_API NrgbipInvert(HNRgbImage hImage, HNRgbImage * pHResultImage);
NResult N_API NrgbipInvertDst(HNRgbImage hImage, HNRgbImage hDstImage);
NResult N_API NrgbipInvertSame(HNRgbImage hImage);

// Brightness & Contrast

NResult N_API NrgbipAdjustBrightnessContrast(HNRgbImage hImage, NDouble brightness, NDouble contrast, HNRgbImage * pHResultImage);
NResult N_API NrgbipAdjustBrightnessContrastDst(HNRgbImage hImage, HNRgbImage hDstImage, NDouble brightness, NDouble contrast);
NResult N_API NrgbipAdjustBrightnessContrastSame(HNRgbImage hImage, NDouble brightness, NDouble contrast);

NResult N_API NrgbipAdjustChannelsBrightnessContrast(HNRgbImage hImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast, HNRgbImage * pHResultImage);
NResult N_API NrgbipAdjustChannelsBrightnessContrastDst(HNRgbImage hImage, HNRgbImage hDstImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast);
NResult N_API NrgbipAdjustChannelsBrightnessContrastSame(HNRgbImage hImage,
	NDouble redBrightness, NDouble redContrast, NDouble greenBrightness, NDouble greenContrast, NDouble blueBrightness, NDouble blueContrast);

// Color Matrix transformation

NResult N_API NrgbipColorMatrixTransform(HNRgbImage hImage, NDouble * pColorMatrix, HNRgbImage * pHResultImage);
NResult N_API NrgbipColorMatrixTransformDst(HNRgbImage hImage, HNRgbImage hDstImage, NDouble * pColorMatrix);
NResult N_API NrgbipColorMatrixTransformSame(HNRgbImage hImage, NDouble * pColorMatrix);

// Tools for mask painting

NResult N_API NrgbipAlphaBlend(HNRgbImage hImageA, HNImage hImageB, NDouble alpha, HNRgbImage *pHResultImage);
NResult N_API NrgbipAlphaBlendDst(HNRgbImage hImageA, HNImage hImageB, HNRgbImage hDstImage, NDouble alpha);
NResult N_API NrgbipAlphaBlendSame(HNRgbImage hImageA, HNImage hImageB, NDouble alpha);

NResult N_API NrgbipAlphaBlendColor(HNRgbImage hImageA, HNImage hImageB, NDouble r, NDouble g, NDouble b, NDouble a, HNRgbImage * pHResultImage);
NResult N_API NrgbipAlphaBlendColorDst(HNRgbImage hImageA, HNImage hImageB, HNRgbImage hDstImage, NDouble r, NDouble g, NDouble b, NDouble a);
NResult N_API NrgbipAlphaBlendColorSame(HNRgbImage hImageA, HNImage hImageB, NDouble r, NDouble g, NDouble b, NDouble a);

NResult N_API NrgbipAlphaBlendColorMatrix(HNRgbImage hImageA, HNImage hImageB, NDouble * pColorMatrix, HNRgbImage * pHResultImage);
NResult N_API NrgbipAlphaBlendColorMatrixDst(HNRgbImage hImageA, HNImage hImageB, HNRgbImage hDstImage, NDouble * pColorMatrix);
NResult N_API NrgbipAlphaBlendColorMatrixSame(HNRgbImage hImageA, HNImage hImageB, NDouble * pColorMatrix);

#ifdef N_CPP
}
#endif

#endif // !N_RGB_IMAGE_PROC_H_INCLUDED
