#ifndef N_GRAYSCALE_IMAGE_H_INCLUDED
#define N_GRAYSCALE_IMAGE_H_INCLUDED

#include <NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

NResult N_API NGrayscaleImageGetMinValue(HNGrayscaleImage hImage, NByte * pValue);
NResult N_API NGrayscaleImageSetMinValue(HNGrayscaleImage hImage, NByte value);
NResult N_API NGrayscaleImageGetMaxValue(HNGrayscaleImage hImage, NByte * pValue);
NResult N_API NGrayscaleImageSetMaxValue(HNGrayscaleImage hImage, NByte value);
NResult N_API NGrayscaleImageGetPixel(HNGrayscaleImage hImage, NUInt x, NUInt y, NByte * pValue);
NResult N_API NGrayscaleImageSetPixel(HNGrayscaleImage hImage, NUInt x, NUInt y, NByte value);

#ifdef N_CPP
}
#endif

#endif // !N_GRAYSCALE_IMAGE_H_INCLUDED
