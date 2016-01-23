#ifndef N_RGB_IMAGE_H_INCLUDED
#define N_RGB_IMAGE_H_INCLUDED

#include <NImage.h>
#include <NRgb.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NRgbImageGetMinValue(HNRgbImage hImage, struct NRgb_ * pValue);
NResult N_API NRgbImageSetMinValue(HNRgbImage hImage, const struct NRgb_ * pValue);
NResult N_API NRgbImageGetMaxValue(HNRgbImage hImage, struct NRgb_ * pValue);
NResult N_API NRgbImageSetMaxValue(HNRgbImage hImage, const struct NRgb_ * pValue);
NResult N_API NRgbImageGetPixel(HNRgbImage hImage, NUInt x, NUInt y, struct NRgb_ * pValue);
NResult N_API NRgbImageSetPixel(HNRgbImage hImage, NUInt x, NUInt y, const struct NRgb_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_RGB_IMAGE_H_INCLUDED
